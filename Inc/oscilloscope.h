//
// Created by elmot on 5.2.2017.
//
// Memory frames support
//

#ifndef F3_OSCILL_FRAME_H
#define F3_OSCILL_FRAME_H

#define FRAME_SIZE ((size_t)1400)

#include <stdbool.h>
#include <stm32f3xx_hal.h>
#include <stddef.h>

typedef enum FRAME_STATUS {
    IDLE,
    PREPARING,
    READY,
    TRANSMITTING
} FRAME_STATUS;

#define CMD_MAX_SIZE 128
#define CMD_BUFFER 4
#define NUM_CHANNELS 1
extern uint16_t adc1_buffer[FRAME_SIZE * 2];

typedef struct FRAME {
    uint16_t bufferA[FRAME_SIZE];
    size_t dataLength;
    volatile bool triggered;
    volatile bool busy;
    volatile bool sent;
} FRAME;

extern OPAMP_HandleTypeDef hopamp1;
extern OPAMP_HandleTypeDef hopamp3;
extern OPAMP_HandleTypeDef hopamp4;

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc3;
extern ADC_HandleTypeDef hadc4;

extern TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

DAC_HandleTypeDef hdac;
DMA_HandleTypeDef hdma_dac_ch1;

extern FRAME frame1;
extern FRAME frame2;
extern FRAME * lastFrame;
extern volatile int phase;

void transmitFrame(FRAME * frame);

void transmitString(char *str);

void setupUsbComm();

void initOscilloscope();

/*__attribute__( ( long_call, section(".data") ) ) */void
copyDataToAvailableFrame(uint16_t *src1, size_t size, uint16_t *src2, bool triggered);

/**
 *
 * @param buffer buffer for the command
 * @param maxLength buffer length,
 * @return true if the command was received
 */
bool getCommand(char * buffer, size_t maxLength);

bool processCommand(char buffer[]);


// hardware device config
#define MAJOR_DMA DMA1
#define MAJOR_DMA_ISR_HTI_FLAG DMA_ISR_HTIF1
#define MAJOR_DMA_ISR_TCI_FLAG DMA_ISR_TCIF1
#define MAJOR_DMA_CH DMA1_Channel1


#endif //F3_OSCILL_FRAME_H
