#ifndef __OSCILL_H
#define __OSCILL_H

#define FLAG_TRIGGERED 0x8000
#define FLAG_NEW 0x4000

extern uint8_t OscillConfigData[];
extern uint16_t bufferA[2049];
extern uint16_t bufferB[2049];
extern uint16_t bufferC[2049];
extern uint16_t bufferAT[2049];
extern uint16_t bufferBT[2049];
extern uint16_t bufferCT[2049];

extern OPAMP_HandleTypeDef hopamp1;
extern OPAMP_HandleTypeDef hopamp3;
extern OPAMP_HandleTypeDef hopamp4;
extern TIM_HandleTypeDef htim1;



#endif

