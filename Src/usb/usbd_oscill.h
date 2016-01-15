/**
  ******************************************************************************
  * @file    usbd_oscill.h
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    13-June-2014
  * @brief   header file for the usbd_oscill.c file.
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
  
/** @defgroup usbd_oscill
  * @brief This file is the Header file for USBD_OSCILL.c
  * @{
  */ 


/** @defgroup usbd_oscill_Exported_Defines
  * @{
  */ 
#define OSCILL_IN_EP                       			0x81  /* EP for Data IN */
#define OSCILL_OUT_EP                           0x02  /* EP for commands */


# define USB_OSCILL_CONFIG_DESC_SIZ                32

/*---------------------------------------------------------------------*/
/*  OSCILL definitions                                                    */
/*---------------------------------------------------------------------*/

/**
  * @}
  */ 


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */

/**
  * @}
  */ 
typedef struct
{
  uint32_t config_no;
  uint32_t sample_freq;
  uint32_t trigger_source;
  uint32_t trigger_type;
  uint32_t trigger_value;
  uint32_t trigger_timeshift;
  uint32_t voltage_rangeA;
  uint32_t voltage_rangeB;
  uint32_t voltage_rangeC;
  uint32_t voltage_rangeD;
}USBD_OSCILL_CodingTypeDef;

typedef struct _USBD_OSCILL_Itf
{
  int8_t (* Init)          (void);
  int8_t (* DeInit)        (void);
  int8_t (* Control)       (uint8_t, uint8_t * , uint16_t);   
  int8_t (* Receive)       (uint8_t *, uint32_t *);  

}USBD_OSCILL_ItfTypeDef;


typedef struct
{
  uint32_t data[ USB_FS_MAX_PACKET_SIZE /4];      /* Force 32bits alignment */
  uint8_t  CmdOpCode;
  uint8_t  CmdLength;    
  uint8_t  *RxBuffer;  
  uint8_t  *TxBuffer;   
  uint32_t RxLength;
  uint32_t TxLength;    
  
}
USBD_OSCILL_HandleTypeDef; 



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */ 
  
/**
  * @}
  */ 

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */ 

extern USBD_ClassTypeDef  USBD_OSCILL;
/**
  * @}
  */ 

/** @defgroup USB_CORE_Exported_Functions
  * @{
  */
uint8_t  USBD_OSCILL_RegisterInterface  (USBD_HandleTypeDef   *pdev, 
                                      USBD_OSCILL_ItfTypeDef *fops);

uint8_t  USBD_OSCILL_SetTxBuffer  (USBD_HandleTypeDef   *pdev,
                                uint8_t  *pbuff,
                                uint16_t length);

uint8_t  USBD_OSCILL_SetRxBuffer        (USBD_HandleTypeDef   *pdev,
                                      uint8_t  *pbuff);
  
uint8_t  USBD_OSCILL_TransmitPacket  (USBD_HandleTypeDef *pdev);
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
