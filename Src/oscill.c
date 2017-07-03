#include <sched.h>
#include <main.h>
#include <stm32f303xe.h>
#include "stm32f3xx_hal.h"

CHANNEL chA;
extern ADC_HandleTypeDef hadc2;

extern DAC_HandleTypeDef hdac1;

extern OPAMP_HandleTypeDef hopamp2;

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim7;

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_tx;

extern DMA_HandleTypeDef hdma_memtomem_dma1_channel1;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel2;

struct SVD_ADC2;
struct SVD_TIM2;

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

  ADC_AnalogWDGConfTypeDef AnalogWDGConfig;
  AnalogWDGConfig.WatchdogNumber = ADC_ANALOGWATCHDOG_2;
  AnalogWDGConfig.WatchdogMode = ADC_ANALOGWATCHDOG_SINGLE_REG;
  AnalogWDGConfig.HighThreshold = 4095;
  AnalogWDGConfig.LowThreshold = 900;
  AnalogWDGConfig.Channel = ADC_CHANNEL_3;
  AnalogWDGConfig.ITMode = ENABLE;
  if (HAL_ADC_AnalogWDGConfig(&hadc2, &AnalogWDGConfig) != HAL_OK) {
    _Error_Handler(__FILE__, __LINE__);
  }


  HAL_ADC_Start_DMA(&hadc2, (uint32_t *) chA.buffer, FRAME_LEN * 2);


  hadc2.Instance->IER = ADC_IT_AWD1;//Only watchdog 1 is enabled
  __HAL_TIM_CLEAR_FLAG(&htim2,TIM_FLAG_UPDATE);
  __HAL_TIM_ENABLE_IT(&htim2, TIM_IT_UPDATE);
  HAL_TIM_Base_Start(&htim1);
}

volatile bool dryRun = false;
volatile int triggerFrameShift = FRAME_LEN / 2;


void __unused ADC1_2_IRQHandler(void) {
  if (__HAL_ADC_GET_FLAG(&hadc2, ADC_FLAG_AWD1)) {// trigger histeresis detected

    __HAL_ADC_CLEAR_FLAG(&hadc2, ADC_FLAG_AWD1);
    hadc2.Instance->IER = ADC_IT_AWD2;//Only watchdog 2 is enabled

  } else {
    hadc2.Instance->IER = 0;//disable everything
    // trigger detected, run TIM2 to stop measurement
    __HAL_TIM_SET_AUTORELOAD(&htim2, triggerFrameShift);
    __HAL_TIM_CLEAR_FLAG(&htim2,TIM_FLAG_UPDATE);
    __HAL_TIM_ENABLE(&htim2);
  }

}

void __unused TIM2_IRQHandler(void) {
  if(dryRun) {
    __HAL_TIM_DISABLE(&htim2);
    __HAL_ADC_CLEAR_FLAG(&hadc2, ADC_FLAG_AWD1 | ADC_FLAG_AWD2);
    hadc2.Instance->IER = ADC_IT_AWD1;//Only watchdog 1 is enabled
    dryRun = false;
  } else {
    __HAL_TIM_DISABLE(&htim1);
    __HAL_TIM_SET_AUTORELOAD(&htim2, 2*FRAME_LEN); //todo calc correct value
    dryRun = true;
    if (lockBuffer(&chA.keyFrame)) {
      uint32_t remainingSamples = hadc2.DMA_Handle->Instance->CNDTR;
      if (remainingSamples > FRAME_LEN) {
        //End of the buffer contains some data
        uint32_t tailLen = remainingSamples - FRAME_LEN;
        HAL_DMA_Start(&HALFWORD_DMA, (uint32_t) &chA.buffer[2 * FRAME_LEN - tailLen],
                      (uint32_t) chA.keyFrame.buffer, tailLen);
        HAL_DMA_PollForTransfer(&HALFWORD_DMA, HAL_DMA_FULL_TRANSFER, 200);

        if (tailLen < FRAME_LEN) {
          HAL_DMA_Start(&HALFWORD_DMA, (uint32_t) chA.buffer,
                        (uint32_t) &chA.keyFrame.buffer[tailLen], FRAME_LEN - tailLen);
          HAL_DMA_PollForTransfer(&HALFWORD_DMA, HAL_DMA_FULL_TRANSFER, 200);
        }

      } else {
        HAL_DMA_Start(&HALFWORD_DMA, (uint32_t) &chA.buffer[FRAME_LEN - remainingSamples],
                      (uint32_t) chA.keyFrame.buffer, FRAME_LEN);
        HAL_DMA_PollForTransfer(&HALFWORD_DMA, HAL_DMA_FULL_TRANSFER, 200);
      }
      unlockBuffer(&chA.keyFrame, READY);
    }


    __HAL_TIM_ENABLE(&htim1);
  }
  __HAL_TIM_SET_COUNTER(&htim2, 0);
  __HAL_TIM_CLEAR_FLAG(&htim2,TIM_FLAG_UPDATE);
  __HAL_TIM_CLEAR_IT(&htim2,TIM_IT_UPDATE);
}

//#define CRLF "\r\n"
const char hex[] = "0123456789ABCDEF";
bool transmitFrame(volatile FRAME *frame, bool key) {
  if (lockReadyBuffer(frame)) {
    puts(key ? "KYFRAME" : "FRAME");
    for (int i = 0; i < FRAME_LEN; ++i) {
      int16_t val = frame->buffer[i];
      char buf[] = "XXX";
      buf[0] = hex[(val >> 8) & 0xf];
      buf[1] = hex[(val >> 4) & 0xf];
      buf[2] = hex[(val) & 0xf];
      fputs(buf, stdout);
//      puts(buf);
    }
    puts("\nEND");

    unlockBuffer(frame, EMPTY);
    return true;
  }
  return false;
}
