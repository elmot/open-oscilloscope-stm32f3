//
// Created by elmot on 5.2.2017.
//
// Memory frames support
//

#ifndef F3_OSCILL_FRAME_H
#define F3_OSCILL_FRAME_H

#define FRAME_SIZE ((size_t)1400)

#define LED_DEBUG

#ifdef LED_DEBUG
#define LED_ON(pin) { pin ## _GPIO_Port->BSRR = pin ## _Pin; }
#define LED_OFF(pin) { pin ## _GPIO_Port->BRR = pin ## _Pin; }
#else
#define LED_ON(pin)
#define LED_OFF(pin)
#endif

#include <stdbool.h>
#include <stm32f3xx_hal.h>
#include <stddef.h>


#define CMD_MAX_SIZE 128
#define CMD_BUFFER 4
#define NUM_CHANNELS 1

extern uint16_t adc1_buffer[FRAME_SIZE * 2];

typedef volatile enum FRAME_SEND_PRIORITY {
    BUSY = 0,
    SENT = 1,
    SLO_MO = 2,
    NORMAL = 3,
    TRIGGERED = 4
} FRAME_SEND_PRIORITY;


size_t writePriority(FRAME_SEND_PRIORITY priority);

typedef struct FRAME {
    volatile uint16_t bufferA[FRAME_SIZE];
    volatile FRAME_SEND_PRIORITY prio;
    volatile uint8_t seq;
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

#define GEN_DMA_LENGTH 72
void genSineWave(uint16_t ampl, uint16_t pInt[72]);

void transmitString(char *str);

void setupUsbComm(void);

void initOscilloscope(void);

void postponedTriggerEnable(void);


/*__attribute__( ( long_call, section(".data") ) ) */
void copyDataToAvailableFrame(uint16_t *src, bool triggered);

/*__attribute__( ( long_call, section(".data") ) ) */
void copyDataToAvailableFrame2(uint16_t *src1, uint16_t *src2, size_t size, bool triggered);

bool sendBytes(uint8_t *s, int len);//low level

void transmitFrame(void);

void waitUntilTransmissed();


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
