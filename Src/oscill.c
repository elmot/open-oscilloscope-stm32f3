#include <stdint.h>
#include <string.h>
#include "oscilloscope.h"

//
// Created by elmot on 11.3.2017.
//
void startDAC() {
  HAL_TIM_Base_Start(&htim2);
  HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
}

// todo hw dividers
//todo leds
//todo gen
// todo trigger
// todo key frame
//todo config
// todo three channels
typedef struct {
    __IO uint32_t *div2ODR;
    uint32_t div2mask;
    __IO uint32_t *div10ODR;
    uint32_t div10mask;
    __IO uint32_t *div30ODR;
    uint32_t div30mask;
} VoltDivBits;

static const VoltDivBits divBits[3] = {
        {
                &OSCILLOSCOPE_A2_GPIO_Port->ODR, OSCILLOSCOPE_A2_Pin,
                &OSCILLOSCOPE_A10_GPIO_Port->ODR, OSCILLOSCOPE_A10_Pin,
                &OSCILLOSCOPE_A30_GPIO_Port->ODR, OSCILLOSCOPE_A30_Pin
        },
        {
                &OSCILLOSCOPE_B2_GPIO_Port->ODR, OSCILLOSCOPE_B2_Pin,
//                &OSCILLOSCOPE_B10_GPIO_Port->ODR, OSCILLOSCOPE_B10_Pin,
//                &OSCILLOSCOPE_B30_GPIO_Port->ODR, OSCILLOSCOPE_B30_Pin
        },
        {
                &OSCILLOSCOPE_C2_GPIO_Port->ODR, OSCILLOSCOPE_C2_Pin,
                &OSCILLOSCOPE_C10_GPIO_Port->ODR, OSCILLOSCOPE_C10_Pin,
                &OSCILLOSCOPE_C30_GPIO_Port->ODR, OSCILLOSCOPE_C30_Pin
        }
};

void clearKeyFrames();

int parseDecimal(char *buf, size_t len) {
  bool minus = false;
  int val = 0;
  for (int i = 0; i < len; i++) {
    if (buf[i] == '-') {
      minus = true;
    } else if (buf[i] >= '0' && buf[i] <= '9') {
      val = val * 10 + buf[i] - '0';
    } else break;
  }
  return minus ? -val : val;
}

void setDiv(char channel_letter, char d) {
  int chIdx = channel_letter - 'a';
  if (chIdx >= 0 && chIdx < 4) {
    switch (d) {
      case '0':
        *divBits[chIdx].div2ODR |= divBits[chIdx].div2mask;
        *divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
        *divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
        break;
      case '1':
        *divBits[chIdx].div2ODR &= ~divBits[chIdx].div2mask;;
        *divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
        *divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
        break;
      case '2':
        *divBits[chIdx].div2ODR |= divBits[chIdx].div2mask;
        *divBits[chIdx].div10ODR &= ~divBits[chIdx].div10mask;
        *divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
        break;
      default:
        *divBits[chIdx].div2ODR |= divBits[chIdx].div2mask;
        *divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
        *divBits[chIdx].div30ODR &= ~divBits[chIdx].div30mask;
        break;
    }
  }
  clearKeyFrames();
}

void clearKeyFrames() {//todo

}

void setGain(char opamp_letter, char g) {
  OPAMP_HandleTypeDef *opamp;
  switch (opamp_letter) {
    case 'a':
      opamp = &hopamp1;
      break;
    case 'b':
      opamp = &hopamp3;
      break;
    case 'c':
      opamp = &hopamp4;
      break;
    default:
      return;
  }
  opamp->Init.Mode = OPAMP_PGA_MODE;
  switch (g) {
    case '0':
      opamp->Init.PgaGain = OPAMP_PGA_GAIN_2;
      break;
    case '1':
      opamp->Init.PgaGain = OPAMP_PGA_GAIN_4;
      break;
    case '2':
      opamp->Init.PgaGain = OPAMP_PGA_GAIN_8;
      break;
    case '3':
      opamp->Init.PgaGain = OPAMP_PGA_GAIN_16;
      break;
    default:
      opamp->Init.Mode = OPAMP_FOLLOWER_MODE;
      break;
  }
  HAL_OPAMP_Init(opamp);
  HAL_OPAMP_Start(opamp);
  clearKeyFrames();
}

typedef struct {
    uint16_t prescaler;
    uint16_t arr;
    uint16_t samplingTime;
} TimeCoeff;

#define TIMING_COUNT 18
static const TimeCoeff timing[TIMING_COUNT] =
        {
                {999, 7200,  ADC_SAMPLETIME_601CYCLES_5},  // A => 10Hz
                {99,  36000, ADC_SAMPLETIME_601CYCLES_5},  // B => 20Hz
                {99,  14400, ADC_SAMPLETIME_601CYCLES_5},  // C => 50Hz
                {99,  7200,  ADC_SAMPLETIME_601CYCLES_5},   // D => 100Hz
                {99,  3600,  ADC_SAMPLETIME_601CYCLES_5},   // E => 200Hz
                {99,  1440,  ADC_SAMPLETIME_601CYCLES_5},   // F => 500Hz
                {99,  720,   ADC_SAMPLETIME_601CYCLES_5},    // G => 1kHz
                {0,   36000, ADC_SAMPLETIME_601CYCLES_5},   // H => 2kHz
                {0,   14400, ADC_SAMPLETIME_601CYCLES_5},   // I => 5kHz
                {0,   7200,  ADC_SAMPLETIME_601CYCLES_5},    // J => 10kHz
                {0,   3600,  ADC_SAMPLETIME_601CYCLES_5},    // K => 20kHz
                {0,   1440,  ADC_SAMPLETIME_601CYCLES_5},    // L => 50kHz
                {0,   720,   ADC_SAMPLETIME_601CYCLES_5},     // M => 100kHz
                {0,   360,   ADC_SAMPLETIME_181CYCLES_5},     // N => 200kHz
                {0,   144,   ADC_SAMPLETIME_19CYCLES_5},      // O => 500kHz
                {0,   72,    ADC_SAMPLETIME_19CYCLES_5},       // P => 1MHz
                {0,   36,    ADC_SAMPLETIME_19CYCLES_5},       // Q => 2MHz
                {0,   14,    ADC_SAMPLETIME_1CYCLE_5}          // R => 5MHz
        };

void setTiming(char t) {
  if (t < 'A') t = 0; else t -= 'A';
  if (t >= TIMING_COUNT) t = TIMING_COUNT - 1;
  __HAL_TIM_DISABLE(&htim1);
  htim1.Instance->PSC = timing[t].prescaler;
  htim1.Instance->ARR = timing[t].arr;
  htim1.Instance->CNT = 0;
  clearKeyFrames();

  //config ADC1
  ADC_ChannelConfTypeDef sConfig;
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = 1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  __HAL_ADC_DISABLE(&hadc1);
  HAL_ADC_ConfigChannel(&hadc1, &sConfig);
  __HAL_ADC_ENABLE(&hadc1);
  //TODO config ADC3
  //TODO config ADC4
  __HAL_TIM_ENABLE(&htim1);

}

char triggerType = 'R';
char triggerChannel = 'A';
int triggerTimeShift = 0;
int triggerLevel = 700;
volatile uint32_t triggerLevelReg2 = 0xFFFFFFFF;//todo make that AWD2?

ADC_HandleTypeDef *getTriggerADC() {
  switch (triggerChannel) {
    case 'B':
      return &hadc3;
    case 'C':
      return &hadc4;
    default:
      return &hadc1;
  }
}

static void setupTrigger() {
  hadc1.Instance->CFGR &= ~ADC_CFGR_AWD1EN;
  hadc3.Instance->CFGR &= ~ADC_CFGR_AWD1EN;
  hadc4.Instance->CFGR &= ~ADC_CFGR_AWD1EN;
  if (triggerChannel == 'Z') {
//    bufferA[0] |= FLAG_TRIGGERED;
//    bufferB[0] |= FLAG_TRIGGERED;
//    bufferC[0] |= FLAG_TRIGGERED;
  } else if (triggerChannel != 'N') {
//    bufferA[0] &= ~FLAG_TRIGGERED;
//    bufferB[0] &= ~FLAG_TRIGGERED;
//    bufferC[0] &= ~FLAG_TRIGGERED;
            __HAL_TIM_SetAutoreload(&htim3, FRAME_SIZE - triggerTimeShift);
            __HAL_TIM_SetCounter(&htim3, 0);
    ADC_HandleTypeDef *hadc = getTriggerADC();
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
    if (triggerType == 'R') {
      hadc->Instance->TR1 = __HAL_ADC_TRX_HIGHTHRESHOLD(0xFFF) | triggerLevel;
      triggerLevelReg2 = __HAL_ADC_TRX_HIGHTHRESHOLD(triggerLevel);
    } else {
      hadc->Instance->TR1 = __HAL_ADC_TRX_HIGHTHRESHOLD(triggerLevel);
      triggerLevelReg2 = __HAL_ADC_TRX_HIGHTHRESHOLD(0xFFF) | triggerLevel;
    }
#pragma clang diagnostic pop
    hadc->Instance->CFGR |= ADC_CFGR_AWD1EN;
    __HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);
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

void setTriggerLevel(char *value, size_t length) {
  triggerLevel = parseDecimal(value, length);
  setupTrigger();
}

void setTriggerTimeShift(char *value, size_t length) {
  triggerTimeShift = parseDecimal(value, length);
  setupTrigger();
}

bool processCommand(char buffer[]) {
  if (buffer[0] == 't' && buffer[1] == '=') {
    setTiming(buffer[2]);
    return true;
  }
  //s.c.range=F/2
  if (buffer[0] == 's' && buffer[1] == '.' && strncmp(&buffer[3], ".range=", 7) == 0) {
    setGain(buffer[2], buffer[10]);
    setDiv(buffer[2], buffer[12]);
    return true;
  }

//trig.type=R/F
  if (strncmp(buffer, "trig.type=", 10) == 0) {
    setTriggerType(buffer[10]);
    return true;
  }
//trig.ch=Z/A/B/C/E
  if (strncmp(buffer, "trig.ch=", 8) == 0) {
    setTriggerChannel(buffer[8]);
    return true;
  }
//trig.level=num
  if (strncmp(buffer, "trig.level=", 11) == 0) {
    setTriggerLevel(&buffer[11], 89);
    return true;
  }
//trig.time=num
  if (strncmp(buffer, "trig.time=", 10) == 0) {
    setTriggerTimeShift(&buffer[10], 89);
    return true;
  }
  return false;
}


void ADC1_IRQHandler() {
  ADC_HandleTypeDef *hadc = &hadc1;
  if (triggerLevelReg2 == 0xFFFFFFFF) {
//    ongoingFrameClear = false; todo???
    __HAL_TIM_ENABLE(&htim3);
    hadc->Instance->CFGR &= ~ADC_CFGR_AWD1EN;
  } else {
    hadc->Instance->TR1 = triggerLevelReg2;
    triggerLevelReg2 = 0xFFFFFFFF;
  }
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD1);
}

void __unused TIM3_IRQHandler() {
  __HAL_TIM_DISABLE(&htim1);
  __HAL_TIM_DISABLE(&htim3);
  __HAL_TIM_CLEAR_IT(&htim3, TIM_IT_UPDATE);
  size_t counter = hadc1.DMA_Handle->Instance->CNDTR;

  if (counter >= FRAME_SIZE) {
//    copyDataToAvailableFrame(&adc1_buffer[2 * FRAME_SIZE - counter], FRAME_SIZE, NULL, true);
  } else {
//    copyDataToAvailableFrame(&adc1_buffer[2 * FRAME_SIZE - counter], counter, adc1_buffer, true);

  }



//  memcpy(&bufferAT[1],&bufferA[FRAME_SIZE - counter + 1], counter * 2);
//  memcpy(&bufferAT[counter + 1],&bufferA[1], (FRAME_SIZE - counter) * 2);
//  memcpy(&bufferBT[1],&bufferB[FRAME_SIZE - counter + 1], counter * 2);
//  memcpy(&bufferBT[counter + 1],&bufferB[1], (FRAME_SIZE - counter) * 2);
//  memcpy(&bufferCT[1],&bufferC[FRAME_SIZE - counter + 1], counter * 2);
//  memcpy(&bufferCT[counter + 1],&bufferC[1], (FRAME_SIZE - counter) * 2);
//  bufferAT[0] = FLAG_NEW | FLAG_TRIGGERED;
//  bufferBT[0] = FLAG_NEW | FLAG_TRIGGERED;
//  bufferCT[0] = FLAG_NEW | FLAG_TRIGGERED;
//  if( ongoingFrameClear) {
//    bufferAT[0] |= FLAG_CLEAR;
//    bufferBT[0] |= FLAG_CLEAR;
//    bufferCT[0] |= FLAG_CLEAR;
//  }
  setupTrigger();
  __HAL_TIM_ENABLE(&htim1);
}

void setupAdc() {
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *) adc1_buffer, FRAME_SIZE * 2);
  __HAL_ADC_DISABLE_IT(&hadc1,ADC_IT_OVR);
  HAL_TIM_Base_Start(&htim1);
}

void initOscilloscope() {
  startDAC();
  setupAdc();
  setupUsbComm();
  HAL_OPAMP_Start(&hopamp1);
  setupTrigger();
}