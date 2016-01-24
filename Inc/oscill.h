#ifndef __OSCILL_H
#define __OSCILL_H

#include "stm32f3xx_hal.h"

#define FLAG_TRIGGERED 0x8000
#define FLAG_NEW 0x4000
#define FLAG_CLEAR 0x2000

#define FRAME_SIZE 2047

extern uint8_t OscillConfigData[];
extern uint16_t bufferA[FRAME_SIZE + 1];
extern uint16_t bufferB[FRAME_SIZE + 1];
extern uint16_t bufferC[FRAME_SIZE + 1];
extern uint16_t bufferAT[FRAME_SIZE + 1];
extern uint16_t bufferBT[FRAME_SIZE + 1];
extern uint16_t bufferCT[FRAME_SIZE + 1];

extern OPAMP_HandleTypeDef hopamp1;
extern OPAMP_HandleTypeDef hopamp3;
extern OPAMP_HandleTypeDef hopamp4;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc3;
extern ADC_HandleTypeDef hadc4;
extern DMA_HandleTypeDef hdma_adc1;
extern DMA_HandleTypeDef hdma_adc3;
extern DMA_HandleTypeDef hdma_adc4;

extern DAC_HandleTypeDef hdac;
extern DMA_HandleTypeDef hdma_dac_ch1;

extern UART_HandleTypeDef huart2;

extern DMA_HandleTypeDef hdma_memtomem_dma1_channel2;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel3;

void initOscill(void);
void sendBuffer(char channel_letter);

void setGain(char opamp_letter, char g);
void setTiming(char t);
void setDiv(char channel_letter, char d);

void setTriggerType(char sign);
void setTriggerChannel(char sign);
void setTriggerLevel(char *value, size_t length);
void setTriggerTimeShift(char *value, size_t length);
#endif

