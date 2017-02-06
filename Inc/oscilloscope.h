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
extern uint16_t adc1_buffer[FRAME_SIZE * 2];

typedef struct FRAME {
    uint16_t bufferA[FRAME_SIZE];
    size_t dataLength;
    volatile bool triggered;
    volatile bool busy;
} FRAME;


extern FRAME frame1;
extern FRAME frame2;

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

#endif //F3_OSCILL_FRAME_H
