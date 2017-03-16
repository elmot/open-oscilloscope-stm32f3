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

/* USER CODE END PFP */

void initOscilloscope();

FRAME *getFreeFrame(bool triggered);

/*__attribute__( ( long_call, section(".data") ) ) */void __unused DMA1_Channel1_IRQHandler(void)
{
  postponedTriggerEnable();

  switch( MAJOR_DMA->ISR & (MAJOR_DMA_ISR_HTI_FLAG | MAJOR_DMA_ISR_TCI_FLAG))
  {
    case MAJOR_DMA_ISR_HTI_FLAG:
      copyDataToAvailableFrame(adc1_buffer, false);
      break;
    case MAJOR_DMA_ISR_TCI_FLAG:
      copyDataToAvailableFrame(&adc1_buffer[FRAME_SIZE], false);
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
    HAL_DMA_Start(&hdma_memtomem_dma1_channel2, (uint32_t) src, (uint32_t) frame->bufferA, FRAME_SIZE );
    HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel2, HAL_DMA_FULL_TRANSFER, 2000); // todo optimise awful ST code
    frame->prio = triggered ? TRIGGERED : NORMAL;
  }
  busy = false;

}

void copyDataToAvailableFrame2(uint16_t *src1, uint16_t *src2, size_t size1, bool triggered) {
  if(busy)return;
  busy = true;
  FRAME *frame = getFreeFrame(triggered);
  if (frame != NULL) {
    if (size1 > 0)
      HAL_DMA_Start(&hdma_memtomem_dma1_channel2, (uint32_t) src1, (uint32_t) frame->bufferA, size1);
    size_t size2 = FRAME_SIZE - size1;
    if (size2 > 0)
      HAL_DMA_Start(&hdma_memtomem_dma2_channel1, (uint32_t) src2, (uint32_t) &frame->bufferA[size1], size2);
    if (size1 > 0)
      HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel2, HAL_DMA_FULL_TRANSFER, 2000); // todo optimise awful ST code
    if (size2 > 0)
      HAL_DMA_PollForTransfer(&hdma_memtomem_dma2_channel1, HAL_DMA_FULL_TRANSFER, 2000); // todo optimise awful ST code
    frame->prio = triggered ? TRIGGERED : NORMAL;
  }
  busy = false;
}

size_t writePriority(FRAME_SEND_PRIORITY priority) {
  switch (priority) {
    case TRIGGERED :
      return 1;
    case NORMAL :
      return 2;
    case SLO_MO :
      return 3;
    case SENT :
      return 4;
    default:
      return 0; //BUSY

  }
}

FRAME *getFreeFrame(bool triggered) {
  FRAME *frame;
  __disable_irq();
  size_t dPrio = writePriority(frame1.prio) - writePriority(frame2.prio);
  if (dPrio > 0) {
    frame = &frame1;
  } else if (dPrio < 0) {
    frame = &frame2;
  } else {
    frame = frame1.seq > frame2.seq ? &frame2 : &frame1;
  }
  if (frame->prio == BUSY || (!triggered && frame->prio == TRIGGERED)) {
    __enable_irq();
    return NULL;
  }
  frame->prio = BUSY;
  __enable_irq();
  return frame;
}

