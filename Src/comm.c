#include <usbd_cdc_if.h>
#include "oscilloscope.h"
//
// Created by elmot on 6.2.2017.
//
// Communication layer

static char ringBuffer[CMD_BUFFER][CMD_MAX_SIZE];
int writeBufferIndex = 0;
int writeCharIndex = 0;
int readBufferIndex = 0;

void transmitFrame(FRAME *frame) {
  //todo
  CDC_Transmit_FS((uint8_t *) "FRAME REQUESTED!\n\r", 18);
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
  strncpy(buffer,ringBuffer[readBufferIndex],maxLength);
  readBufferIndex = (readBufferIndex + 1) % CMD_BUFFER;
  return true;
}

void receiveChar(char c) {
  if(c == 10 || c==13) {
    if(writeCharIndex==0) return; //skip heading CR LF
    ringBuffer[writeBufferIndex][writeCharIndex] = 0;
    writeBufferIndex = (writeBufferIndex + 1) % CMD_BUFFER;
    if(readBufferIndex == writeBufferIndex) readBufferIndex = (readBufferIndex + 1) % CMD_BUFFER;
    writeCharIndex = 0;
  }
  if(writeCharIndex < CMD_MAX_SIZE - 1) {
    ringBuffer[writeBufferIndex][writeCharIndex++] = c;
  }
}
