#include "string.h"
#include "stdbool.h"
#include "oscill.h"
#include "usbd_oscill_if.h"

uint16_t bufferA[FRAME_SIZE + 1];
uint16_t bufferB[FRAME_SIZE + 1];
uint16_t bufferC[FRAME_SIZE + 1];
uint16_t bufferAT[FRAME_SIZE + 1];
uint16_t bufferBT[FRAME_SIZE + 1];
uint16_t bufferCT[FRAME_SIZE + 1];

uint16_t bufferD[FRAME_SIZE + 1];

volatile bool ongoingFrameClear = false;
/* TODO
trig.ch
            <!--<option value="E" DISABLED>Ext</option>-->
Empty frames after param change
*/
char triggerType = 'R';
char triggerChannel = 'Z';
int triggerTimeShift = 0;
int triggerLevel = 0;
volatile uint32_t triggerLevelReg2 = 0xFFFFFFFF;

ADC_HandleTypeDef * getTriggerADC(){
	switch(triggerChannel) {
		case 'B': return &hadc3;
		case 'C': return &hadc4;
	}
	return &hadc1;
}
static void setupTrigger() {
	hadc1.Instance->CFGR &= ~ADC_CFGR_AWD1EN;
	hadc3.Instance->CFGR &= ~ADC_CFGR_AWD1EN;
	hadc4.Instance->CFGR &= ~ADC_CFGR_AWD1EN;
	if(triggerChannel == 'Z') {
			bufferA[0] |= FLAG_TRIGGERED;
			bufferB[0] |= FLAG_TRIGGERED;
			bufferC[0] |= FLAG_TRIGGERED;
	} else {
		bufferA[0] &= ~FLAG_TRIGGERED;
		bufferB[0] &= ~FLAG_TRIGGERED;
		bufferC[0] &= ~FLAG_TRIGGERED;
		__HAL_TIM_SetAutoreload(&htim3, FRAME_SIZE + triggerTimeShift);
		__HAL_TIM_SetCounter(&htim3, 0);
		ADC_HandleTypeDef * hadc = getTriggerADC();
		if(triggerType == 'R') {
			hadc->Instance->TR1 = __HAL_ADC_TRX_HIGHTHRESHOLD(0xFFF) | triggerLevel;
			triggerLevelReg2 = __HAL_ADC_TRX_HIGHTHRESHOLD(triggerLevel);
		} else {
			hadc->Instance->TR1 = __HAL_ADC_TRX_HIGHTHRESHOLD(triggerLevel);
			triggerLevelReg2 = __HAL_ADC_TRX_HIGHTHRESHOLD(0xFFF) | triggerLevel;
		}
		hadc->Instance->CFGR |= ADC_CFGR_AWD1EN;
	}
}

void setTriggerType(char sign) {
	triggerType = sign;
	setupTrigger();
}

void setTriggerChannel(char sign) {
	triggerChannel = sign;
	setupTrigger();
}

int parseDecimal(char* buf, size_t len) {
	bool minus = false;
	int val = 0;
	for(int i = 0; i < len; i++) {
	  if(buf[i]  == '-') {
			minus = true; 
		} else if(buf[i]  >= '0' && buf[i]  <= '9' ) {
			val = val*10 + buf[i] -'0';
		} else break;
	}
	return minus ? -val : val;
}

void setTriggerLevel(char *value, size_t length) {
	triggerLevel = parseDecimal(value,length);
	setupTrigger();
}

void setTriggerTimeShift(char *value, size_t length) {
	triggerTimeShift = parseDecimal(value,length);
	setupTrigger();
}




void channelTrigger() {
	HAL_TIM_Base_Stop(&htim1);
	HAL_TIM_Base_Stop(&htim3);
	int counter = hadc1.DMA_Handle->Instance->CNDTR;

	memcpy(&bufferAT[1],&bufferA[FRAME_SIZE - counter + 1], counter * 2);
	memcpy(&bufferAT[counter + 1],&bufferA[1], (FRAME_SIZE - counter) * 2);
	memcpy(&bufferBT[1],&bufferB[FRAME_SIZE - counter + 1], counter * 2);
	memcpy(&bufferBT[counter + 1],&bufferB[1], (FRAME_SIZE - counter) * 2);
	memcpy(&bufferCT[1],&bufferC[FRAME_SIZE - counter + 1], counter * 2);
	memcpy(&bufferCT[counter + 1],&bufferC[1], (FRAME_SIZE - counter) * 2);
	bufferAT[0] = FLAG_NEW | FLAG_TRIGGERED;
	bufferBT[0] = FLAG_NEW | FLAG_TRIGGERED;
	bufferCT[0] = FLAG_NEW | FLAG_TRIGGERED;
  if( ongoingFrameClear) {
		bufferAT[0] |= FLAG_CLEAR;
		bufferBT[0] |= FLAG_CLEAR;
		bufferCT[0] |= FLAG_CLEAR;
	}
	HAL_TIM_Base_Start(&htim1);
	
	setupTrigger();
}

void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc) {
	if(triggerLevelReg2 == 0xFFFFFFFF) {
		ongoingFrameClear = false;
		HAL_TIM_Base_Start(&htim3);
		hadc->Instance->CFGR &= ~ADC_CFGR_AWD1EN;
	} else {
		hadc->Instance->TR1 = triggerLevelReg2;
		triggerLevelReg2 = 0xFFFFFFFF;
	}
}

void initOscill() {
		{/*Fix cubeMX bug */
		hopamp4.Init.NonInvertingInput = OPAMP_NONINVERTINGINPUT_VP3;
		HAL_OPAMP_Init(&hopamp4);
	}
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&bufferA[1], FRAME_SIZE);
	HAL_ADC_Start_DMA(&hadc3, (uint32_t*)&bufferB[1], FRAME_SIZE);
	HAL_ADC_Start_DMA(&hadc4, (uint32_t*)&bufferC[1], FRAME_SIZE);
	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_Base_Start(&htim2);
	HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
	HAL_OPAMP_Start(&hopamp1);
	HAL_OPAMP_Start(&hopamp3);
	HAL_OPAMP_Start(&hopamp4);

  __HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);
	
	bufferAT[0] = FLAG_TRIGGERED | FLAG_CLEAR;
	bufferBT[0] = FLAG_TRIGGERED | FLAG_CLEAR;
	bufferCT[0] = FLAG_TRIGGERED | FLAG_CLEAR;
	setupTrigger();
}

static void clearKeyFrames()
{
	bufferAT[0] |= FLAG_CLEAR | FLAG_NEW;
	bufferBT[0] |= FLAG_CLEAR | FLAG_NEW;
	bufferCT[0] |= FLAG_CLEAR | FLAG_NEW;
	ongoingFrameClear = true;
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
	clearKeyFrames();
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
	clearKeyFrames();
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
	clearKeyFrames();
	//TODO ADC SAMPLING TIME
}

void sendBuffer(char channel) {
		uint16_t* buffer;
		uint16_t* bufferKey;
//__IO uint32_t *counter;
		switch(channel) {
			case 'B':
				buffer = bufferB;
				bufferKey = bufferBT;
//				counter = &hadc1.DMA_Handle->Instance->CNDTR;
				break;
			case 'C': 
				buffer = bufferC;
				bufferKey = bufferCT;
//				counter = &hadc3.DMA_Handle->Instance->CNDTR;
				break;
			default: 
				buffer = bufferA;
				bufferKey = bufferAT;
//				counter = &hadc4.DMA_Handle->Instance->CNDTR;
		}
		if(bufferKey[0] & FLAG_NEW) {
			bufferKey[0] &= ~FLAG_NEW;
			buffer = bufferKey;
//			counter = NULL;
		}
		if(buffer[0] & FLAG_CLEAR) {
			OSCILL_Transmit_FS((uint8_t*)buffer, 2); 
		} else {
			memcpy(bufferD,buffer,sizeof(bufferD));
//			if(counter != NULL)bufferD[FRAME_SIZE - * counter + 2] = NO_DATA;
			OSCILL_Transmit_FS((uint8_t*)bufferD, (FRAME_SIZE + 1) * 2); 
		}
}
