#include <sched.h>
#include <main.h>
#include <stdbool.h>
#include "stm32f3xx_hal.h"

CHANNEL chA;
extern ADC_HandleTypeDef hadc2;
extern DMA_HandleTypeDef hdma_adc1;

extern DAC_HandleTypeDef hdac1;
extern DMA_HandleTypeDef hdma_dac_ch1;

extern OPAMP_HandleTypeDef hopamp2;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim7;

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_tx;

extern DMA_HandleTypeDef hdma_memtomem_dma1_channel1;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel2;

bool lockBuffer(volatile FRAME *frame) {
  __disable_irq();
  if (frame->status != BUSY) {
    frame->status = BUSY;
    __enable_irq();
    return true;
  }
  __enable_irq();
  return false;
}

bool lockReadyBuffer(volatile FRAME *frame) {
  __disable_irq();
  if (frame->status == READY) {
    frame->status = BUSY;
    __enable_irq();
    return true;
  }
  __enable_irq();
  return false;
}

void unlockBuffer(volatile FRAME *frame, volatile STATUS status) {
  __disable_irq();
  frame->status = status;
  __enable_irq();
}


void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef __unused *hadc) {
  if (lockBuffer(&chA.frame)) {
    HAL_DMA_Start(&WORD_DMA, (uint32_t) chA.buffer, (uint32_t) chA.frame.buffer, FRAME_LEN / 2);
    HAL_DMA_PollForTransfer(&WORD_DMA, HAL_DMA_FULL_TRANSFER, 200);
    unlockBuffer(&chA.frame, READY);
  }
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef __unused *hadc) {
  if (lockBuffer(&chA.frame)) {
    HAL_DMA_Start(&WORD_DMA, (uint32_t) &chA.buffer[FRAME_LEN], (uint32_t) chA.frame.buffer, FRAME_LEN / 2);
    HAL_DMA_PollForTransfer(&WORD_DMA, HAL_DMA_FULL_TRANSFER, 200);
    unlockBuffer(&chA.frame, READY);
  }
}


void setupGenerator() {
  HAL_DAC_Start(&hdac1, DAC_CHANNEL_1);
  HAL_DAC_Start(&hdac1, DAC_CHANNEL_2);
  HAL_DAC_SetValue(&hdac1, DAC1_CHANNEL_1, DAC_ALIGN_12B_R, 2048);
  HAL_TIM_Base_Start(&htim7);
}

void setupOscill() {
  HAL_ADCEx_Calibration_Start(&hadc2, ADC_DIFFERENTIAL_ENDED);
  HAL_ADC_PollForConversion(&hadc2, 200);
  HAL_ADC_Start_DMA(&hadc2, (uint32_t *) chA.buffer, FRAME_LEN * 2);
  HAL_TIM_Base_Start(&htim1);
}

#define CRLF "\r\n"
const char hex[] = "0123456789ABCDEF";
bool transmitFrame(volatile FRAME *frame, bool key) {
  if (lockReadyBuffer(frame)) {
    puts(key ? "KYFRAME"CRLF : "FRAME");
    for (int i = 0; i < FRAME_LEN; ++i) {
      int16_t val = frame->buffer[i];
      char buf[] = "XXX";
      buf[0] = hex[(val >> 8) & 0xf];
      buf[1] = hex[(val >> 4) & 0xf];
      buf[2] = hex[(val) & 0xf];
      puts(buf);
    }
    puts("END");

    unlockBuffer(frame, EMPTY);
    return true;
  }
  return false;
}