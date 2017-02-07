#include <usbd_cdc_if.h>
#include "oscilloscope.h"
//
// Created by elmot on 6.2.2017.
//
// Communication layer

static char ringBuffer[CMD_BUFFER][CMD_MAX_SIZE];
static int writeBufferIndex = 0;
static int writeCharIndex = 0;
static int readBufferIndex = 0;

static bool sendString(const char *s, int len) {
  uint8_t transmitResult;
  if (len == -1) len = strlen(s);
  if (len == 0) return true;
  do {
    transmitResult = CDC_Transmit_FS((uint8_t *) s, (uint16_t) len);
  } while (transmitResult == USBD_BUSY);
  return transmitResult == USBD_OK;
}
void transmitFrame(FRAME *frame) {
  //todo
  if(frame == NULL) {
    sendString("#NODATA\n\r", 9);
    return;
  }
  __disable_irq();
  frame->busy = true;
  __enable_irq();
  char buf[200];
  sendString("#FRAME\n\r", 8);
  for (int i = 0; i < frame->dataLength; i++) {
    int m = frame->bufferA[i] / 32;
    memset(buf, 32, m);
    buf[m] = '*';
    buf[m + 1] = '\r';
    buf[m + 2] = '\n';
    buf[m + 3] = 0;
    sendString(buf, m + 3);
  }
  frame->busy = false;
  frame->busy = true;

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
