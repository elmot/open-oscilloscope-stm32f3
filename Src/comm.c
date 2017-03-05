#include <usbd_cdc_if.h>
#include <usb_device.h>
#include <usbd_cdc.h>
#include "oscilloscope.h"
//
// Created by elmot on 6.2.2017.
//
// Communication layer

static char ringBuffer[CMD_BUFFER][CMD_MAX_SIZE];
static int writeBufferIndex = 0;
static int writeCharIndex = 0;
static int readBufferIndex = 0;

static bool sendBytes(uint8_t *s, int len) {
  uint8_t transmitResult;
  if (len == 0) return true;
  do {
    transmitResult = CDC_Transmit_FS(s, (uint16_t) len);
  } while (transmitResult == USBD_BUSY);
  return transmitResult == USBD_OK;
}

static void waitUntilTransmissed() {
  USBD_CDC_HandleTypeDef *hcdc = (USBD_CDC_HandleTypeDef *) hUsbDeviceFS.pClassData;
  while (hcdc->TxState != 0);
}

static bool sendString(const char *s, int len) {
  if (len == -1) len = strlen(s);
  return sendBytes((uint8_t *) s, len);
}

void transmitFrame(FRAME *frame) {
  //todo
  uint16_t length;
  static const uint8_t NO_DATA[2] = {00, 0x80};
  if(frame == NULL) {
    sendBytes((uint8_t *) NO_DATA, 2);
    return;
  }
  __disable_irq();
  frame->busy = true;
  __enable_irq();
  length = (uint16_t) (0x8000 | frame->dataLength | (frame->triggered ? 0x4000 : 0) | (0x1000 * NUM_CHANNELS));
  uint8_t buffer[2] = {(uint8_t) (length & 0xff), (uint8_t) (length >> 8)};
  sendBytes(buffer, 2);
  waitUntilTransmissed();
  sendBytes((uint8_t *) frame->bufferA, frame->dataLength * 2);
  waitUntilTransmissed();
  frame->busy = false;

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
  strncpy(buffer, (const char *) &ringBuffer[readBufferIndex], maxLength);
  readBufferIndex = (readBufferIndex + 1) % CMD_BUFFER;
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
