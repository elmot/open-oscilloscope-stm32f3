#include <usbd_cdc_if.h>
#include <usb_device.h>
#include "oscilloscope.h"
//
// Created by elmot on 6.2.2017.
//
// Communication layer

static char ringBuffer[CMD_BUFFER][CMD_MAX_SIZE];
static int writeBufferIndex = 0;
static int writeCharIndex = 0;
static int readBufferIndex = 0;

bool sendBytes(uint8_t *s, int len) {
  uint8_t transmitResult;
  if (len == 0) return true;
  do {
    transmitResult = CDC_Transmit_FS(s, (uint16_t) len);
  } while (transmitResult == USBD_BUSY);
  return transmitResult == USBD_OK;
}

void waitUntilTransmissed() {
  USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef *) hUsbDeviceFS.pClassData;
  while (hcdc->TxState != 0);
}

void transmitString(char *str) {
  sendBytes((uint8_t *) str, strlen(str));
}

void transmitFrame() {
  static const uint16_t NO_DATA = 0x8000;

  uint16_t prioFlag;
  volatile FRAME *frame;
  __disable_irq();
  if (frame1.prio > frame2.prio) {
    frame = &frame1;
  } else if (frame2.prio > frame1.prio) {
    frame = &frame2;
  } else {
    frame = frame1.seq > frame2.seq ? &frame2 : &frame1;
  }
  if(frame->prio <= SENT) {
    __enable_irq();
    sendBytes((uint8_t *) &NO_DATA, 2);
    return;
  }
  prioFlag = (uint16_t) (frame->prio == TRIGGERED ? 0x4000 : 0);
  frame->prio = BUSY;
  __enable_irq();
  uint16_t head[3] = {0x8000 | (4 + /*3 * todo 3ch */ 2 * FRAME_SIZE),
                      'F' + 'R' * 0x100,
                      (uint16_t) (FRAME_SIZE | (0x1000 * NUM_CHANNELS) | prioFlag)
  };

  sendBytes((uint8_t *) head, 6);
  waitUntilTransmissed();
  sendBytes((uint8_t *) frame->bufferA, FRAME_SIZE * 2);
  waitUntilTransmissed();
  frame->prio = SENT;

}

void setupUsbComm() {
  writeCharIndex = 0;
  writeBufferIndex = 0;
  readBufferIndex = 0;
}
/**
 *
 * @param buffer buffer for the command
 * @param maxLength buffer length,
 * @return true if the command was received
 */
bool getCommand(char *buffer, size_t maxLength) {
  if(readBufferIndex == writeBufferIndex) return false;
  __disable_irq();
  strncpy(buffer, (const char *) &ringBuffer[readBufferIndex], maxLength);
  readBufferIndex = (readBufferIndex + 1) % CMD_BUFFER;
  __enable_irq();
  return true;
}

void receiveChar(char c) {
  if ((c == 10) || (c == 13)) {
    if(writeCharIndex==0) return; //skip heading CR LF
    ringBuffer[writeBufferIndex][writeCharIndex] = 0;

    writeBufferIndex = (writeBufferIndex + 1) % CMD_BUFFER;
    if(readBufferIndex == writeBufferIndex) readBufferIndex = (readBufferIndex + 1) % CMD_BUFFER;
    writeCharIndex = 0;
  } else if (writeCharIndex < CMD_MAX_SIZE - 1) {
    ringBuffer[writeBufferIndex][writeCharIndex++] = c;
  }
}
