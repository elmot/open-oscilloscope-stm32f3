/**
  ******************************************************************************
  * @file    usbd_oscill_core.h
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    13-June-2014
  * @brief   header file for the usbd_oscill_core.c file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/

#ifndef __USB_OSCILL_CORE_H_
#define __USB_OSCILL_CORE_H_

#include  "usbd_ioreq.h"

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup USBD_OSCILL
  * @brief This file is the Header file for USBD_msc.c
  * @{
  */ 


/** @defgroup USBD_OSCILL_Exported_Defines
  * @{
  */ 
#define OSCILL_IN_EP                 0x81
#define OSCILL_OUT_CONF_EP           0x01
#define OSCILL_OUT_DATA_EP           0x02

#define USB_OSCILL_CONFIG_DESC_SIZ   0x27

#define SIZ_STRING_LANGID						 0x04
#define SIZ_STRING_VENDOR						 0x12
#define SIZ_STRING_PRODUCT					 0x28
#define SIZ_STRING_SERIAL						 0x12

/**
  * @}
  */ 


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
//typedef struct
//{
//  uint8_t data[USB_FS_MAX_PACKET_SIZE];      /* Force 32bits alignment */

//}
//USBD_OSCILL_HandleTypeDef; 

/**
  * @}
  */ 



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */ 

/**
  * @}
  */ 

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */ 
extern USBD_HandleTypeDef hUsbDeviceFS;


extern USBD_ClassTypeDef  USBD_OSCILL_ClassDriver;
/**
  * @}
  */ 

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */ 
	
void USB_OSCILL_Init(void);	
/**
  * @}
  */ 

#endif  // __USB_OSCILL_CORE_H_
/**
  * @}
  */ 

/**
  * @}
  */ 
  
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
