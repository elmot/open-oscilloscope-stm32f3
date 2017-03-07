#include <stdint.h>
#include <string.h>
#include <stm32f303xc.h>
#include "oscilloscope.h"

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel2;

uint16_t adc1_buffer[FRAME_SIZE * 2];
FRAME frame1;
FRAME frame2;
FRAME * lastFrame = NULL;

/*__attribute__( ( long_call, section(".data") ) ) */static void copyDataToAvailableFrame(uint16_t * src, size_t size, bool triggered);

/*__attribute__( ( long_call, section(".data") ) ) */void __unused DMA1_Channel1_IRQHandler(void)
{
  switch( MAJOR_DMA->ISR & (MAJOR_DMA_ISR_HTI_FLAG | MAJOR_DMA_ISR_TCI_FLAG))
  {
    case MAJOR_DMA_ISR_HTI_FLAG:
      copyDataToAvailableFrame(adc1_buffer, FRAME_SIZE, false); break;
    case MAJOR_DMA_ISR_TCI_FLAG:
      copyDataToAvailableFrame(&adc1_buffer[FRAME_SIZE], FRAME_SIZE, false); break;
    default: break;// Too late IRQ, skip the frame
  }

  MAJOR_DMA->IFCR |= MAJOR_DMA_ISR_HTI_FLAG | DMA_ISR_TCIF1;

}


static volatile bool busy = false;
void setupAdc() {
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *) adc1_buffer, FRAME_SIZE * 2);
  HAL_TIM_Base_Start(&htim1);
}

static void copyDataToAvailableFrame(uint16_t *src, size_t size, bool triggered) {
  if(busy)return;
  busy = true;
  FRAME *frame;//todo do not overwrite triggered frames!
  __disable_irq();
  if (!frame1.busy) {
    frame = &frame1;
    frame->busy = true;
  } else if (!frame2.busy) {
    frame = &frame2;
    frame->busy = true;
  } else {
    frame = NULL;
  }
  __enable_irq();
  if (frame != NULL) {
    if(!triggered && frame->triggered && !frame-> sent) return;
    HAL_DMA_Start(&hdma_memtomem_dma1_channel2, (uint32_t) src, (uint32_t) frame->bufferA, size / 2);
    frame->triggered = triggered;
    frame->dataLength = size;
    frame->sent = false;
    HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel2, HAL_DMA_FULL_TRANSFER, 2000); // todo optimise awful ST code
//    memcpy(frame->bufferA,src,size*2);
    frame->busy = false;
    lastFrame = frame;
    busy = false;
  }

}

