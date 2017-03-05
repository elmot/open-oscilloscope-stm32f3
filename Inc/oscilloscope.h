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


extern FRAME frame1;
extern FRAME frame2;
extern FRAME * lastFrame;
extern volatile int phase;

void setupAdc(void);

void transmitFrame(FRAME * frame);

void setupUsbComm();
/**
 *
 * @param buffer buffer for the command
 * @param maxLength buffer length,
 * @return true if the command was received
 */
bool getCommand(char * buffer, size_t maxLength);


// hardware device config
#define MAJOR_DMA DMA1
#define MAJOR_DMA_ISR_HTI_FLAG DMA_ISR_HTIF1
#define MAJOR_DMA_ISR_TCI_FLAG DMA_ISR_TCIF1
#define MAJOR_DMA_CH DMA1_Channel1


#endif //F3_OSCILL_FRAME_H
