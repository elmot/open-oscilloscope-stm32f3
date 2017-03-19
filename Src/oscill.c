#include <stdint.h>
#include <string.h>
#include <stm32f303xc.h>
#include <stdlib.h>
#include "oscilloscope.h"

//
// Created by elmot on 11.3.2017.
//

// todo hw dividers
//todo fix pre-trigger
//todo config
//todo voltage and time values
// todo three channels
// todo slo_mo frames
typedef struct {
    __IO uint32_t *div2ODR;
    uint32_t div2mask;
    __IO uint32_t *div10ODR;
    uint32_t div10mask;
    __IO uint32_t *div30ODR;
    uint32_t div30mask;
} VoltDivBits;

typedef struct {
    const char prefix[20];
    const size_t prefix_len;
    char value[20];

    bool (*const parser)(char *strValue);
} COMMON_PARAM;

char configText[500] = "";
size_t configTextLen = 0;

static const VoltDivBits divBits[3] = {
        {
                &OSCILLOSCOPE_A2_GPIO_Port->ODR, OSCILLOSCOPE_A2_Pin,
                &OSCILLOSCOPE_A10_GPIO_Port->ODR, OSCILLOSCOPE_A10_Pin,
                &OSCILLOSCOPE_A30_GPIO_Port->ODR, OSCILLOSCOPE_A30_Pin
        },
        {
                &OSCILLOSCOPE_B2_GPIO_Port->ODR, OSCILLOSCOPE_B2_Pin,
                &OSCILLOSCOPE_B10_GPIO_Port->ODR, OSCILLOSCOPE_B10_Pin,
                &OSCILLOSCOPE_B30_GPIO_Port->ODR, OSCILLOSCOPE_B30_Pin
        },
        {
                &OSCILLOSCOPE_C2_GPIO_Port->ODR, OSCILLOSCOPE_C2_Pin,
                &OSCILLOSCOPE_C10_GPIO_Port->ODR, OSCILLOSCOPE_C10_Pin,
                &OSCILLOSCOPE_C30_GPIO_Port->ODR, OSCILLOSCOPE_C30_Pin
        }
};
static uint16_t genDmaBuf[GEN_DMA_LENGTH];
static char genShape = 'N';
static char genBuff;
static int genFreq;
static uint16_t genAmpl;

void clearKeyFrames();
static void setupTrigger();

void triggerEnable(ADC_HandleTypeDef *hadc);

void startDAC() {
  HAL_TIM_Base_Start(&htim2);
  HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t *) &genDmaBuf, GEN_DMA_LENGTH, DAC_ALIGN_12B_R);
}

void setDiv(uint8_t chIdx, char d) {
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

void clearKeyFrames() {//todo nuke?

}

void setGain(uint8_t idx, char g) {
  OPAMP_HandleTypeDef *opamp;
  switch (idx) {
    case 0:
      opamp = &hopamp1;
      break;
    case 1:
      opamp = &hopamp3;
      break;
    case 2:
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

bool setTiming(char *strT) {
  char t = strT[0];
  if (t < 'A' || t > 'R') return false;
  t -= 'A';
  if (t >= TIMING_COUNT) return false;
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
  setupTrigger();

  return true;
}

char triggerType = 'R';
char triggerChannel = 'A';
int triggerTimeShift = 0;
int triggerLevel = 700;
static volatile int postponedTriggerStart;// for pre-trigger
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
    //todo EXT trigger
  } else if (triggerChannel != 'N') {
            __HAL_TIM_SetAutoreload(&htim3, FRAME_SIZE - triggerTimeShift);
            __HAL_TIM_SetCounter(&htim3, 0);
    ADC_HandleTypeDef *hadc = getTriggerADC();
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
    if (triggerType == 'R') {
      hadc->Instance->TR1 = __HAL_ADC_TRX_HIGHTHRESHOLD(0xFFF) | triggerLevel - 15;//todo saturation!
      triggerLevelReg2 = __HAL_ADC_TRX_HIGHTHRESHOLD(triggerLevel);
    } else {
      hadc->Instance->TR1 = __HAL_ADC_TRX_HIGHTHRESHOLD(triggerLevel + 15 );//todo saturation!
      triggerLevelReg2 = __HAL_ADC_TRX_HIGHTHRESHOLD(0xFFF) | triggerLevel;
    }
#pragma clang diagnostic pop
    if (triggerTimeShift > 0) {
      postponedTriggerStart = 1;
    } else {
      triggerEnable(hadc);
    }
    __HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);
  }
}

void triggerEnable(ADC_HandleTypeDef *hadc) {
  hadc->Instance->CFGR |= ADC_CFGR_AWD1EN;
  postponedTriggerStart = 0;
}

void postponedTriggerEnable() {
  if (postponedTriggerStart-- > 0) {
    triggerEnable(getTriggerADC());
  }
}

bool setTriggerType(char *sign) {
  if (*sign != 'R' && *sign != 'F')
    return false;
  triggerType = *sign;
  return true;
}

bool setTriggerChannel(char *sign) {
  char c = *sign;
  if (c != 'A' && c != 'B' && c != 'C' && c != 'N' && c != 'Z')
    return false;
  triggerChannel = c;
  setupTrigger();
  return true;
}

bool setTriggerLevel(char *value) {
  int i = atoi(value);
  if (i < 0 || i > 4095)
    return false;
  triggerLevel = i;
  setupTrigger();
  return true;
}

bool setTriggerTimeShift(char *value) {
  int i = atoi(value);
  if (i >= (int) FRAME_SIZE ||
      (i <= -(int) FRAME_SIZE))
    return false;
    triggerTimeShift = i;
  setupTrigger();
  return true;
}

//Generator

void genFillConst(uint16_t ampl, uint16_t * buffer, size_t len)
{
  for(size_t i = 0; i < len; i++) {
    buffer[i] = ampl;
  }
}

void genFillTriangle() {
  for(size_t i = 0; i <= GEN_DMA_LENGTH / 2; i++) {
    genDmaBuf[i] = genDmaBuf[GEN_DMA_LENGTH - i] = (uint16_t) ((genAmpl * i) / (GEN_DMA_LENGTH / 2));
  }
}

void genFillSawtooth() {
  for(size_t i = 0; i < GEN_DMA_LENGTH ; i++) {
    genDmaBuf[i] = (uint16_t) ((genAmpl * i) / GEN_DMA_LENGTH);
  }
}

static void setupGen() {
  HAL_DAC_Stop(&hdac, DAC_CHANNEL_1);
  switch(genShape) {
    case '-'://const voltage
      genFillConst(genAmpl, genDmaBuf, GEN_DMA_LENGTH);
      break;
    case 'S': //Meander
      genSineWave(genAmpl, genDmaBuf);
      break;

    case 'M': //Meander
      genFillConst(0, genDmaBuf, GEN_DMA_LENGTH / 2);
      genFillConst(genAmpl, &genDmaBuf[GEN_DMA_LENGTH / 2], GEN_DMA_LENGTH / 2);
      break;
    case 'T': //Triangle
      genFillTriangle();
      break;
    case 'J'://Sawtooth
      genFillSawtooth();
      break;
    default: return;//case 'N'
  }
  htim2.Instance->ARR = (uint32_t) (100000 / genFreq);
  htim2.Instance->CNT = 0;
  if(genBuff == 't' || genBuff == 'T')
  {
    hdac.Instance->CR &= ~DAC_CR_BOFF1;
  } else {
    hdac.Instance->CR |= DAC_CR_BOFF1;
  }
  HAL_DAC_Start_DMA(&hdac, DAC_CHANNEL_1, (uint32_t*)genDmaBuf, GEN_DMA_LENGTH, DAC_ALIGN_12B_R);
}


bool setGenShape(char *sShape) {
  char shape = *sShape;
  if(shape != 'N' && shape != '-' && shape != 'M' && shape != 'T' && shape != 'S' && shape != 'J') {
    return false;
  }
  genShape = shape;
  setupGen();
  return true;
}

bool setGenBuff(char *buff) {
  if(*buff != 't' || *buff != 'f')
    return false;
  genBuff = *buff;
  setupGen();
  return true;
}

bool setGenFreq(char *value) {
  int i = atoi(value);
  if(i <2 || i> 10000)
    return false;
  genFreq = i;
  setupGen();
  return true;
}
bool setGenAmpl(char *value) {
  int i = atoi(value);
  if (i < 1 || i > 3000)
    return false;
  genAmpl = (uint16_t) (i * 4095 / 3000);
  setupGen();
  return true;
}

COMMON_PARAM common_params[] = {
        {"t=",          2,  "M",    setTiming},//t=A...R
        {"trig.type=",  10, "R",    setTriggerType},//trig.type=R/F
        {"trig.ch=",    8,  "A",    setTriggerChannel},//trig.ch=Z/A/B/C/E
        {"trig.level=", 11, "700",  setTriggerLevel},//trig.level=num
        {"trig.time=",  10, "0",    setTriggerTimeShift},//trig.time=num

        {"gen.shape=",  10, "M",    setGenShape},// N/-/M/T/S/J
        {"gen.ampl=",   9,  "1000", setGenAmpl},// 136-4095
        {"gen.freq=",   9,  "1000", setGenFreq},//2..10000
        {"gen.buff=",   9,  "0",    setGenBuff},// t/f
        {"",            9,  "", NULL}
};

char gains[3] = {'F', 'F', 'F'};
char divers[3] = {'1', '1', '1'};

void updateConfigText() {
  char *cPos = configText;
  for (COMMON_PARAM *p = common_params; p->parser != NULL; p++) {
    memcpy(cPos, p->prefix, p->prefix_len);
    cPos += p->prefix_len;
    size_t len = strlen(p->value);
    memcpy(cPos, p->value, len);
    cPos += len;
    *(cPos++) = 10;
    *(cPos++) = 13;
    *(cPos) = 0;
  }
  for (char cc = 0; cc < 3; cc++) {
    sprintf(cPos, "s.%c.range=%c/%c\n\r", cc + 'a', gains[cc], divers[cc]);
    cPos += strlen(cPos);
  }
  configTextLen = cPos - configText;
}

bool processCommand(char buffer[]) {
  bool ok = false;
  for (COMMON_PARAM *p = common_params; p->parser != NULL; p++) {
    if (strncmp(p->prefix, buffer, p->prefix_len) == 0) {
      char *strValue = &buffer[p->prefix_len];
      if (p->parser(strValue)) {
        strncpy(p->value, strValue, sizeof p->value);
        ok = true;
      }
    }
  }

  //s.c.range=F/2
  if (!ok && buffer[0] == 's' && buffer[1] == '.' && strncmp(&buffer[3], ".range=", 7) == 0) {
    uint8_t channelIdx = (uint8_t) (buffer[2] - 'a');
    if (channelIdx > 3) {
      return false;
    }
    char gain = buffer[10];
    gains[channelIdx] = gain;
    setGain(channelIdx, gain);
    char diver = buffer[12];
    setDiv(channelIdx, diver);
    divers[channelIdx] = diver;
    ok = true;
  }
  if (ok) {
    updateConfigText();
    uint16_t head[2] = {(uint16_t) (0x8000 | (2 + configTextLen)), 'C' + 0x100 * 'N'};
    sendBytes((uint8_t *) head, 4);
    waitUntilTransmissed();
    sendBytes((uint8_t *) configText, configTextLen);
    waitUntilTransmissed();
  }
  return ok;
}

void setSavedParameters() {
  for (COMMON_PARAM *p = common_params; p->parser != NULL; p++) {
    p->parser(p->value);
  }
  for (uint8_t ch = 0; ch < 3; ch++) {
    setGain(ch, gains[ch]);
    setDiv(ch, divers[ch]);
  }
}
void ADC1_IRQHandler() {
  ADC_HandleTypeDef *hadc = &hadc1;
  if (triggerLevelReg2 == 0xFFFFFFFF) {
    LED_ON(LD6)

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
  size_t counter = __HAL_DMA_GET_COUNTER(hadc1.DMA_Handle);

  if (counter <= FRAME_SIZE) {
    copyDataToAvailableFrame(&adc1_buffer[FRAME_SIZE - counter], true);
  } else {
    copyDataToAvailableFrame2(&adc1_buffer[3 * FRAME_SIZE - counter], adc1_buffer, counter - FRAME_SIZE, true);
  }
  LED_OFF(LD6)

  setupTrigger();
  __HAL_TIM_ENABLE(&htim1);
}

void setupAdc() {
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *) adc1_buffer, FRAME_SIZE * 2);
  __HAL_ADC_DISABLE_IT(&hadc1,ADC_IT_OVR);
  HAL_TIM_Base_Start(&htim1);
}

void initOscilloscope() {
  frame1.prio = SENT;
  frame2.prio = SENT;
  startDAC();
  setupAdc();
  setupUsbComm();
  setSavedParameters();
  HAL_OPAMP_Start(&hopamp1);
  setupTrigger();
}