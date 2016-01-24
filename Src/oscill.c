#include "string.h"
#include "oscill.h"
#include "usbd_oscill_if.h"

uint16_t bufferA[2049];
uint16_t bufferB[2049];
uint16_t bufferC[2049];
uint16_t bufferAT[2049];
uint16_t bufferBT[2049];
uint16_t bufferCT[2049];

void channelTrigger() {
	HAL_TIM_Base_Stop(&htim1);
	HAL_TIM_Base_Stop(&htim3);
	int counter = hadc1.DMA_Handle->Instance->CNDTR;
	memcpy(&bufferAT[1],&bufferA[2048 - counter + 1], counter * 2);
	memcpy(&bufferAT[counter + 1],&bufferA[1], 4096 - counter * 2);
	memcpy(&bufferBT[1],&bufferB[2048 - counter + 1], counter * 2);
	memcpy(&bufferBT[counter + 1],&bufferB[1], 4096 - counter * 2);
	memcpy(&bufferCT[1],&bufferC[2048 - counter + 1], counter * 2);
	memcpy(&bufferCT[counter + 1],&bufferC[1], 4096 - counter * 2);
	bufferAT[0] |= FLAG_NEW;
	bufferBT[0] |= FLAG_NEW;
	bufferCT[0] |= FLAG_NEW;
	HAL_TIM_Base_Start(&htim1);
	hadc1.Instance->CFGR |= ADC_CFGR_AWD1EN;//TODO which adc?
}

void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc) {
	
	HAL_TIM_Base_Start(&htim3);
	hadc->Instance->CFGR &= ~ADC_CFGR_AWD1EN;
}

void initOscill() {
		{/*Fix cubeMX bug */
		hopamp4.Init.NonInvertingInput = OPAMP_NONINVERTINGINPUT_VP3;
		HAL_OPAMP_Init(&hopamp4);
	}
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&bufferA[1], 2048);
	HAL_ADC_Start_DMA(&hadc3, (uint32_t*)&bufferB[1], 2048);
	HAL_ADC_Start_DMA(&hadc4, (uint32_t*)&bufferC[1], 2048);
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start(&htim2);
	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	HAL_OPAMP_Start(&hopamp1);
	HAL_OPAMP_Start(&hopamp3);
	HAL_OPAMP_Start(&hopamp4);
	
	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);
	
	bufferAT[0] = FLAG_TRIGGERED;
	bufferBT[0] = FLAG_TRIGGERED;
	bufferCT[0] = FLAG_TRIGGERED;

}

typedef struct {
	__IO uint32_t * div2ODR;
	uint32_t div2mask;
	__IO uint32_t * div10ODR;
	uint32_t div10mask;
	__IO uint32_t * div30ODR;
	uint32_t div30mask;
} VoltDivBits;

static const VoltDivBits divBits[3] = {
{
	&OSCILLOSCOPE_A2_GPIO_Port->ODR , OSCILLOSCOPE_A2_Pin, 
	&OSCILLOSCOPE_A10_GPIO_Port->ODR, OSCILLOSCOPE_A10_Pin, 
	&OSCILLOSCOPE_A30_GPIO_Port->ODR, OSCILLOSCOPE_A30_Pin
},
{
	&OSCILLOSCOPE_B2_GPIO_Port->ODR , OSCILLOSCOPE_B2_Pin, 
	&OSCILLOSCOPE_B10_GPIO_Port->ODR, OSCILLOSCOPE_B10_Pin, 
	&OSCILLOSCOPE_B30_GPIO_Port->ODR, OSCILLOSCOPE_B30_Pin
},
{
	&OSCILLOSCOPE_C2_GPIO_Port->ODR, OSCILLOSCOPE_C2_Pin, 
	&OSCILLOSCOPE_C10_GPIO_Port->ODR, OSCILLOSCOPE_C10_Pin, 
	&OSCILLOSCOPE_C30_GPIO_Port->ODR, OSCILLOSCOPE_C30_Pin
}

};

void setDiv(char channel_letter, char d) {
	int chIdx = channel_letter - 'a';
	if(chIdx >=0 && chIdx < 4) {
		switch(d) {
			case '0':
				* divBits[chIdx].div2ODR  |= divBits[chIdx].div2mask;
				* divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
				* divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
				break;
			case '1':
				* divBits[chIdx].div2ODR  &= ~divBits[chIdx].div2mask;;
				* divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
				* divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
				break;
			case '2':
				* divBits[chIdx].div2ODR  |= divBits[chIdx].div2mask;
				* divBits[chIdx].div10ODR &= ~divBits[chIdx].div10mask;
				* divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
				break;
			case '3':
				* divBits[chIdx].div2ODR  |= divBits[chIdx].div2mask;
				* divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
				* divBits[chIdx].div30ODR &= ~divBits[chIdx].div30mask;
				break;
		}
	}
}

void setGain(char opamp_letter, char g) {
	uint32_t gainBits;
	switch(g) {
			case '1': gainBits = OPAMP_PGA_GAIN_4; break;
			case '2': gainBits = OPAMP_PGA_GAIN_8; break;
			case '3': gainBits = OPAMP_PGA_GAIN_16; break;
			default: gainBits = OPAMP_PGA_GAIN_2; break;
	}
	OPAMP_TypeDef * opamp;
	switch(opamp_letter) {
		case	'a': opamp = hopamp1.Instance; break;
		case	'b': opamp = hopamp3.Instance; break;
		case	'c': opamp = hopamp4.Instance; break;
		default: return;
	}
	opamp->CSR = (opamp->CSR & ~OPAMP_CSR_PGGAIN) | gainBits;
}

typedef struct {
	uint16_t prescaler;
	uint16_t arr;
	uint16_t samplingTime;
} TimeCoeff;

static const size_t timing_count = 18;
static const TimeCoeff timing[timing_count] =
{
{999, 7200, ADC_SAMPLETIME_601CYCLES_5},  // A => 10Hz
{99, 36000, ADC_SAMPLETIME_601CYCLES_5},  // B => 20Hz
{99, 14400, ADC_SAMPLETIME_601CYCLES_5},  // C => 50Hz
{99, 7200, ADC_SAMPLETIME_601CYCLES_5},   // D => 100Hz
{99, 3600, ADC_SAMPLETIME_601CYCLES_5},   // E => 200Hz
{99, 1440, ADC_SAMPLETIME_601CYCLES_5},   // F => 500Hz
{99, 720, ADC_SAMPLETIME_601CYCLES_5},    // G => 1kHz
{0, 36000, ADC_SAMPLETIME_601CYCLES_5},   // H => 2kHz
{0, 14400, ADC_SAMPLETIME_601CYCLES_5},   // I => 5kHz
{0, 7200, ADC_SAMPLETIME_601CYCLES_5},    // J => 10kHz
{0, 3600, ADC_SAMPLETIME_601CYCLES_5},    // K => 20kHz
{0, 1440, ADC_SAMPLETIME_601CYCLES_5},    // L => 50kHz
{0, 720, ADC_SAMPLETIME_601CYCLES_5},     // M => 100kHz
{0, 360, ADC_SAMPLETIME_181CYCLES_5},     // N => 200kHz
{0, 144, ADC_SAMPLETIME_19CYCLES_5},      // O => 500kHz
{0, 72, ADC_SAMPLETIME_19CYCLES_5},       // P => 1MHz
{0, 36, ADC_SAMPLETIME_19CYCLES_5},       // Q => 2MHz
{0, 14, ADC_SAMPLETIME_1CYCLE_5}          // R => 5MHz
};	

void setTiming(char t){
	if(t < 'A') t = 0; else  t -= 'A';
	if(t >= timing_count) t = timing_count - 1;
	htim1.Instance->PSC = timing[t].prescaler;
	htim1.Instance->ARR = timing[t].arr;
	htim1.Instance->CNT = 0;
	//TODO ADC SAMPLING TIME
}

void sendBuffer(char channel) {
		uint8_t* buffer;
		switch(channel) {
			case 'B': 
				if(bufferBT[0] & FLAG_NEW) {
					bufferBT[0] &= ~FLAG_NEW;
					buffer = (uint8_t*)bufferBT;
				} else {
					buffer = (uint8_t*)bufferB; 
				}
				break;
			case 'C': 
				if(bufferCT[0] & FLAG_NEW) {
					bufferCT[0] &= ~FLAG_NEW;
					buffer = (uint8_t*)bufferCT;
				} else {
					buffer = (uint8_t*)bufferC; 
				}
				break;
			default: 
				if(bufferAT[0] & FLAG_NEW) {
					bufferAT[0] &= ~FLAG_NEW;
					buffer = (uint8_t*)bufferAT;
				} else {
					buffer = (uint8_t*)bufferA; 
				}
				break;
		}
		OSCILL_Transmit_FS(buffer,4098); 
	}
