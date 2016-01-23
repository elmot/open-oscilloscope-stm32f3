/**
  ******************************************************************************
  * @file           : usbd_oscill_if.c
  * @brief          :
  ******************************************************************************
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  * 1. Redistributions of source code must retain the above copyright notice,
  * this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  * this list of conditions and the following disclaimer in the documentation
  * and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of its contributors
  * may be used to endorse or promote products derived from this software
  * without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "usbd_oscill_if.h"

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @{
  */

/** @defgroup USBD_OSCILL 
  * @brief usbd core module
  * @{
  */ 

/** @defgroup USBD_OSCILL_Private_TypesDefinitions
  * @{
  */ 
  /* USER CODE BEGIN 0 */ 
  /* USER CODE END 0 */ 
/**
  * @}
  */ 

/** @defgroup USBD_OSCILL_Private_Defines
  * @{
  */ 
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */  
/**
  * @}
  */ 

/** @defgroup USBD_OSCILL_Private_Macros
  * @{
  */ 
  /* USER CODE BEGIN 2 */ 
extern uint8_t OscillConfigData[];
extern OPAMP_HandleTypeDef hopamp1;
extern OPAMP_HandleTypeDef hopamp3;
extern OPAMP_HandleTypeDef hopamp4;
extern TIM_HandleTypeDef htim1;

  /* USER CODE END 2 */
/**
  * @}
  */ 
  
/** @defgroup USBD_OSCILL_Private_Variables
  * @{
  */
/* Create buffer for reception and transmission           */
/* It's up to user to redefine and/or remove those define */
/* Received Data over USB are stored in this buffer       */
uint8_t UserRxBufferFS[USB_FS_MAX_PACKET_SIZE];

/* Send Data over USB OSCILL are stored in this buffer       */
uint8_t UserTxBufferFS[USB_FS_MAX_PACKET_SIZE];

/* USB handler declaration */
/* Handle for USB Full Speed IP */
USBD_HandleTypeDef  *hUsbDevice_0;

extern USBD_HandleTypeDef hUsbDeviceFS;

/**
  * @}
  */ 
  
/** @defgroup USBD_OSCILL_Private_FunctionPrototypes
  * @{
  */
static int8_t OSCILL_Init_FS     (void);
static int8_t OSCILL_DeInit_FS   (void);
static int8_t OSCILL_Control_FS  (uint8_t cmd, uint8_t* pbuf, uint16_t length);
static int8_t OSCILL_Receive_FS  (uint8_t* pbuf, uint32_t *Len);

USBD_OSCILL_ItfTypeDef USBD_Interface_fops_FS = 
{
  OSCILL_Init_FS,
  OSCILL_DeInit_FS,
  OSCILL_Control_FS,  
  OSCILL_Receive_FS
};

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  OSCILL_Init_FS
  *         Initializes the OSCILL media low layer over the FS USB IP
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t OSCILL_Init_FS(void)
{
  hUsbDevice_0 = &hUsbDeviceFS;
  /* USER CODE BEGIN 3 */ 
  /* Set Application Buffers */
  USBD_OSCILL_SetTxBuffer(hUsbDevice_0, UserTxBufferFS, 0);
  USBD_OSCILL_SetRxBuffer(hUsbDevice_0, UserRxBufferFS);
  return (USBD_OK);
  /* USER CODE END 3 */ 
}

/**
  * @brief  CDC_DeInit_FS
  *         DeInitializes the OSCILL media low layer
  * @param  None
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t OSCILL_DeInit_FS(void)
{
  /* USER CODE BEGIN 4 */ 
  return (USBD_OK);
  /* USER CODE END 4 */ 
}

/**
  * @brief  OSCILL_Control_FS
  *         Manage the CDC class requests
  * @param  cmd: Command code            
  * @param  pbuf: Buffer containing command data (request parameters)
  * @param  length: Number of data to be sent (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t OSCILL_Control_FS  (uint8_t cmd, uint8_t* pbuf, uint16_t length)
{ 
  /* USER CODE BEGIN 5 */
  switch (cmd)
  {
    
  default:
    break;
  }

  return (USBD_OK);
  /* USER CODE END 5 */
}

typedef struct {
	__IO uint32_t * div2ODR;
	uint32_t div2mask;
	__IO uint32_t * div10ODR;
	uint32_t div10mask;
	__IO uint32_t * div30ODR;
	uint32_t div30mask;
} VoltDivBits;

static const VoltDivBits divBits[3] = {
{
	&OSCILLOSCOPE_A2_GPIO_Port->ODR , OSCILLOSCOPE_A2_Pin, 
	&OSCILLOSCOPE_A10_GPIO_Port->ODR, OSCILLOSCOPE_A10_Pin, 
	&OSCILLOSCOPE_A30_GPIO_Port->ODR, OSCILLOSCOPE_A30_Pin
},
{
	&OSCILLOSCOPE_B2_GPIO_Port->ODR , OSCILLOSCOPE_B2_Pin, 
	&OSCILLOSCOPE_B10_GPIO_Port->ODR, OSCILLOSCOPE_B10_Pin, 
	&OSCILLOSCOPE_B30_GPIO_Port->ODR, OSCILLOSCOPE_B30_Pin
},
{
	&OSCILLOSCOPE_C2_GPIO_Port->ODR, OSCILLOSCOPE_C2_Pin, 
	&OSCILLOSCOPE_C10_GPIO_Port->ODR, OSCILLOSCOPE_C10_Pin, 
	&OSCILLOSCOPE_C30_GPIO_Port->ODR, OSCILLOSCOPE_C30_Pin
}

};

void setDiv(char channel_letter, char d) {
	int chIdx = channel_letter - 'a';
	if(chIdx >=0 && chIdx < 4) {
		switch(d) {
			case '0':
				* divBits[chIdx].div2ODR  |= divBits[chIdx].div2mask;
				* divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
				* divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
				break;
			case '1':
				* divBits[chIdx].div2ODR  &= ~divBits[chIdx].div2mask;;
				* divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
				* divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
				break;
			case '2':
				* divBits[chIdx].div2ODR  |= divBits[chIdx].div2mask;
				* divBits[chIdx].div10ODR &= ~divBits[chIdx].div10mask;
				* divBits[chIdx].div30ODR |= divBits[chIdx].div30mask;
				break;
			case '3':
				* divBits[chIdx].div2ODR  |= divBits[chIdx].div2mask;
				* divBits[chIdx].div10ODR |= divBits[chIdx].div10mask;
				* divBits[chIdx].div30ODR &= ~divBits[chIdx].div30mask;
				break;
		}
	}
}
void setGain(char opamp_letter, char g) {
	uint32_t gainBits;
	switch(g) {
			case '1': gainBits = OPAMP_PGA_GAIN_4; break;
			case '2': gainBits = OPAMP_PGA_GAIN_8; break;
			case '3': gainBits = OPAMP_PGA_GAIN_16; break;
			default: gainBits = OPAMP_PGA_GAIN_2; break;
	}
	OPAMP_TypeDef * opamp;
	switch(opamp_letter) {
		case	'a': opamp = hopamp1.Instance; break;
		case	'b': opamp = hopamp3.Instance; break;
		case	'c': opamp = hopamp4.Instance; break;
		default: return;
	}
	opamp->CSR = (opamp->CSR & ~OPAMP_CSR_PGGAIN) | gainBits;
}

typedef struct {
	uint16_t prescaler;
	uint16_t arr;
	uint16_t samplingTime;
} TimeCoeff;

static const size_t timing_count = 18;
static const TimeCoeff timing[timing_count] =
{
{999, 7200, ADC_SAMPLETIME_601CYCLES_5},  // A => 10Hz
{99, 36000, ADC_SAMPLETIME_601CYCLES_5},  // B => 20Hz
{99, 14400, ADC_SAMPLETIME_601CYCLES_5},  // C => 50Hz
{99, 7200, ADC_SAMPLETIME_601CYCLES_5},   // D => 100Hz
{99, 3600, ADC_SAMPLETIME_601CYCLES_5},   // E => 200Hz
{99, 1440, ADC_SAMPLETIME_601CYCLES_5},   // F => 500Hz
{99, 720, ADC_SAMPLETIME_601CYCLES_5},    // G => 1kHz
{0, 36000, ADC_SAMPLETIME_601CYCLES_5},   // H => 2kHz
{0, 14400, ADC_SAMPLETIME_601CYCLES_5},   // I => 5kHz
{0, 7200, ADC_SAMPLETIME_601CYCLES_5},    // J => 10kHz
{0, 3600, ADC_SAMPLETIME_601CYCLES_5},    // K => 20kHz
{0, 1440, ADC_SAMPLETIME_601CYCLES_5},    // L => 50kHz
{0, 720, ADC_SAMPLETIME_601CYCLES_5},     // M => 100kHz
{0, 360, ADC_SAMPLETIME_181CYCLES_5},     // N => 200kHz
{0, 144, ADC_SAMPLETIME_19CYCLES_5},      // O => 500kHz
{0, 72, ADC_SAMPLETIME_19CYCLES_5},       // P => 1MHz
{0, 36, ADC_SAMPLETIME_19CYCLES_5},       // Q => 2MHz
{0, 14, ADC_SAMPLETIME_1CYCLE_5}          // R => 5MHz
};	

void setTiming(int t){
	t -= 'A';
	if(t <0) t = 0; else 
	if(t >= timing_count) t = timing_count - 1;
	htim1.Instance->PSC = timing[t].prescaler;
	htim1.Instance->ARR = timing[t].arr;
	htim1.Instance->CNT = 0;
	//TODO ADC SAMPLING TIME
}
	
/**
  * @brief  OSCILL_Receive_FS
  *         Data received over USB OUT endpoint are sent over CDC interface 
  *         through this function.
  *           
  *         @note
  *         This function will block any OUT packet reception on USB endpoint 
  *         untill exiting this function. If you exit this function before transfer
  *         is complete on OSCILL interface (ie. using DMA controller) it will result 
  *         in receiving more data while previous ones are still not sent.
  *                 
  * @param  Buf: Buffer of data to be received
  * @param  Len: Number of data received (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t OSCILL_Receive_FS (uint8_t* Buf, uint32_t *Len)
{
  /* USER CODE BEGIN 6 */
	if(*Len == 6 && memcmp(Buf,"FRAME",5) == 0)
	{
		switch(Buf[5]) {
			case 'B': OSCILL_Transmit_FS((uint8_t*)bufferB,4096); break;
			case 'C': OSCILL_Transmit_FS((uint8_t*)bufferC,4096); break;
			default: OSCILL_Transmit_FS((uint8_t*)bufferA,4096); break;
		}
		
	} else if(*Len ==13 && Buf[0]=='s' && Buf[1] =='.' &&
		memcmp (&Buf[3],".range=",7) == 0)
	{ //s.[channel].range=[0..3/0..3]
		char channel = Buf[2];
		char gain = Buf[10];
		char div = Buf[12];
		setGain(channel,gain);
		setDiv(channel, div);
	} else if(*Len ==3 && memcmp (Buf,"t=",2) == 0) {
		setTiming(Buf[2]);
	}
  return (USBD_OK);
  /* USER CODE END 6 */ 
}

/** 
  * @brief  OSCILL_Transmit_FS
  *         Data send over USB IN endpoint are sent over CDC interface 
  *         through this function.           
  *         @note
  *         
  *                 
  * @param  Buf: Buffer of data to be send
  * @param  Len: Number of data to be send (in bytes)
  * @retval Result of the operation: USBD_OK if all operations are OK else USBD_FAIL or USBD_BUSY
  */
uint8_t OSCILL_Transmit_FS(uint8_t* Buf, uint16_t Len)
{
  uint8_t result = USBD_OK;
  /* USER CODE BEGIN 7 */ 
  USBD_OSCILL_SetTxBuffer(hUsbDevice_0, Buf, Len);   
  result = USBD_OSCILL_TransmitPacket(hUsbDevice_0);
  /* USER CODE END 7 */ 
  return result;
}

/**
  * @brief Copy a buffer from user memory area to packet memory area (PMA)
  * @param   USBx: USB peripheral instance register address.
  * @param   pbUsrBuf: pointer to user memory area.
  * @param   wPMABufAddr: address into PMA.
  * @param   wNBytes: no. of bytes to be copied.
  * @retval None
	*
	* @!!! NOTE This is optimized version instead of standard one in Drivers/STM32F3xx_HAL_Driver/Src/stm32f3xx_hal_pcd_ex.c
  * @!!! NOTE Standard version should be removed after every CubeMX regeneration
	*
  */
void PCD_WritePMA(USB_TypeDef  *USBx, uint8_t *pbUsrBuf, uint16_t wPMABufAddr, uint16_t wNBytes)
{
  int n = (wNBytes + 1) >> 1;   // n = (wNBytes + 1) / 2 
  __IO uint32_t *pdwVal = (uint32_t *)(wPMABufAddr * 2 + (uint32_t)USBx + 0x400);
	uint16_t * pwUsrBuf = (uint16_t *) pbUsrBuf;
  for (; n != 0; n--)
  {
		*pdwVal = * pwUsrBuf;
		pwUsrBuf++;
		pdwVal++;
  }
}
/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

