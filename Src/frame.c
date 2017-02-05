#include "oscilloscope.h"

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel2;

uint16_t adc1_buffer[FRAME_SIZE * 2];
FRAME frame1;
FRAME frame2;


static void halfDmaDone(struct __DMA_HandleTypeDef *pDef);

static void fullDmaDone(struct __DMA_HandleTypeDef *pDef);

static void copyDataToAvailableFrame(uint16_t * src, size_t size, bool triggered);

void setupAdc() {
  HAL_ADC_Start_DMA(&hadc1, (uint32_t *) adc1_buffer, FRAME_SIZE * 2);
  HAL_TIM_Base_Start(&htim1);
  hadc1.DMA_Handle->XferCpltCallback = fullDmaDone;//todo optimize dma
  hadc1.DMA_Handle->XferHalfCpltCallback = halfDmaDone; //todo optimize dma
}

static void halfDmaDone(struct __DMA_HandleTypeDef *pDef) {
  copyDataToAvailableFrame(adc1_buffer, FRAME_SIZE, false);
}


static void fullDmaDone(struct __DMA_HandleTypeDef *pDef) {
  copyDataToAvailableFrame(&adc1_buffer[FRAME_SIZE], FRAME_SIZE, false);
}

static void copyDataToAvailableFrame(uint16_t *src, size_t size, bool triggered) {
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
    HAL_DMA_Start(&hdma_memtomem_dma1_channel2, (uint32_t) src, (uint32_t) frame->bufferA, size / 2);
    frame->triggered = false;
    frame->dataLength = size;
    HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel2,HAL_DMA_FULL_TRANSFER, 2000); // todo optimise awful ST code
    frame->busy = false;
  }

}
