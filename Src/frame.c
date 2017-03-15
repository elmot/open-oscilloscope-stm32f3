#include <stdint.h>
#include <string.h>
#include <stm32f303xc.h>
#include "oscilloscope.h"

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel2;
extern DMA_HandleTypeDef hdma_memtomem_dma2_channel1;

uint16_t adc1_buffer[FRAME_SIZE * 2];
FRAME frame1;
FRAME frame2;
FRAME * lastFrame = NULL;

/* USER CODE END PFP */

void initOscilloscope();

FRAME *getFreeFrame(bool triggered);

/*__attribute__( ( long_call, section(".data") ) ) */void __unused DMA1_Channel1_IRQHandler(void)
{
  switch( MAJOR_DMA->ISR & (MAJOR_DMA_ISR_HTI_FLAG | MAJOR_DMA_ISR_TCI_FLAG))
  {
    case MAJOR_DMA_ISR_HTI_FLAG:
//      copyDataToAvailableFrame(adc1_buffer, FRAME_SIZE, NULL, false);
      break;
    case MAJOR_DMA_ISR_TCI_FLAG:
//      copyDataToAvailableFrame(&adc1_buffer[FRAME_SIZE], FRAME_SIZE, NULL, false);
      break;
    default: break;// Too late IRQ, skip the frame
  }

  MAJOR_DMA->IFCR |= MAJOR_DMA_ISR_HTI_FLAG | DMA_ISR_TCIF1;

}


static volatile bool busy = false;

void copyDataToAvailableFrame(uint16_t *src, bool triggered) {
  if(busy)return;
  busy = true;
  FRAME *frame = getFreeFrame(triggered);
  if (frame != NULL) {
    if(!triggered && frame->triggered && !frame-> sent) return;
    HAL_DMA_Start(&hdma_memtomem_dma1_channel2, (uint32_t) src, (uint32_t) frame->bufferA, FRAME_SIZE );
    frame->triggered = triggered;
    frame->dataLength = FRAME_SIZE;
    frame->sent = false;
    HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel2, HAL_DMA_FULL_TRANSFER, 2000); // todo optimise awful ST code
    frame->busy = false;
    lastFrame = frame;
    busy = false;
  }

}

void copyDataToAvailableFrame2(uint16_t *src1, uint16_t *src2, size_t size1, bool triggered) {
  if(busy)return;
  busy = true;
  FRAME *frame = getFreeFrame(triggered);
  if (frame != NULL) {
    HAL_DMA_Start(&hdma_memtomem_dma1_channel2, (uint32_t) src1, (uint32_t) frame->bufferA, size1);
    HAL_DMA_Start(&hdma_memtomem_dma2_channel1, (uint32_t) src2, (uint32_t) &frame->bufferA[size1], FRAME_SIZE - size1);
    frame->dataLength = FRAME_SIZE;
    frame->sent = false;
    HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel2, HAL_DMA_FULL_TRANSFER, 2000); // todo optimise awful ST code
    HAL_DMA_PollForTransfer(&hdma_memtomem_dma2_channel1, HAL_DMA_FULL_TRANSFER, 2000); // todo optimise awful ST code
    frame->busy = false;
    lastFrame = frame;
    busy = false;
  }

}

FRAME *getFreeFrame(bool triggered) {
  FRAME *frame;
  __disable_irq();
  if (!frame1.busy &&(triggered || !frame1.triggered || frame1.sent)) {
    frame = &frame1;
    frame->busy = true;
    frame->triggered = triggered;
  } else if (!frame2.busy &&(triggered || !frame2.triggered || frame2.sent)) {
    frame = &frame2;
    frame->busy = true;
    frame->triggered = triggered;
  } else {
    frame = NULL;
  }
  __enable_irq();
  return frame;
}

