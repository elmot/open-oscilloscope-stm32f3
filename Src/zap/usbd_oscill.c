/**
  ******************************************************************************
  * @file    usbd_oscill.c
  * @author  Elmot
  * @version V0.1
  * @date    13-Oct-2015
  * @brief   This file provides the Custom USB class functions
  *
  * @verbatim
	* 4 endpoints:
  * -inout 0(descriptors)          
  * -in command(bulk, receives json)
	* -out dev config (bulk, sends json)
	* -out dev data (bulk, sends binary data)
	*
  * @note     In HS mode and when the DMA is used, all variables and data structures
  *           dealing with the DMA during the transaction process should be 32-bit aligned.
  *           
  *      
  *  @endverbatim
  *
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
#include "usbd_oscill.h"
#include "usbd_ctlreq.h"


/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */


/** @defgroup USBD_OSCILL 
  * @brief usbd core module
  * @{
  */ 
USBD_HandleTypeDef hUsbDeviceFS;

uint8_t OSCILL_CONF_TX_BUFF[USB_FS_MAX_PACKET_SIZE];
uint8_t OSCILL_DATA_TX_BUFF[USB_FS_MAX_PACKET_SIZE];
/**
  * @}
  */ 

/** @defgroup USBD_OSCILL_Private_TypesDefinitions
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup USBD_OSCILL_Private_Defines
  * @{
  */ 

/**
  * @}
  */ 


/** @defgroup USBD_OSCILL_Private_Macros
  * @{
  */ 
                                         
/**
  * @}
  */ 




/** @defgroup USBD_OSCILL_Private_FunctionPrototypes
  * @{
  */


static uint8_t  USBD_OSCILL_Init (USBD_HandleTypeDef *pdev, 
                               uint8_t cfgidx);

static uint8_t  USBD_OSCILL_DeInit (USBD_HandleTypeDef *pdev, 
                                 uint8_t cfgidx);

static uint8_t  USBD_OSCILL_Setup (USBD_HandleTypeDef *pdev, 
                                USBD_SetupReqTypedef *req);

static uint8_t  *USBD_OSCILL_GetCfgDesc (uint16_t *length);

static uint8_t  *USBD_OSCILL_GetDeviceDesc (uint16_t *length);

static uint8_t  USBD_OSCILL_DataIn (USBD_HandleTypeDef *pdev, uint8_t epnum);

static uint8_t  USBD_OSCILL_DataOut (USBD_HandleTypeDef *pdev, uint8_t epnum);

static uint8_t  USBD_OSCILL_EP0_RxReady (USBD_HandleTypeDef *pdev);

static uint8_t  USBD_OSCILL_EP0_TxReady (USBD_HandleTypeDef *pdev);

static uint8_t  *USBD_OSCILL_GetStrDesc(USBD_HandleTypeDef *pdev ,uint8_t index,  uint16_t *length);   

/**
  * @}
  */ 

/** @defgroup USBD_OSCILL_Private_Variables
  * @{
  */ 

USBD_ClassTypeDef  USBD_OSCILL_ClassDriver = 
{
  USBD_OSCILL_Init,
  USBD_OSCILL_DeInit,
  USBD_OSCILL_Setup,
  USBD_OSCILL_EP0_TxReady,  
  USBD_OSCILL_EP0_RxReady,
  USBD_OSCILL_DataIn,
  USBD_OSCILL_DataOut,
  NULL,
  NULL,
  NULL,
  USBD_OSCILL_GetCfgDesc,
  USBD_OSCILL_GetCfgDesc, 
  USBD_OSCILL_GetCfgDesc,
  USBD_OSCILL_GetDeviceDesc,
	USBD_OSCILL_GetStrDesc
};

static uint8_t *     USBD_FS_DeviceDescriptor( USBD_SpeedTypeDef speed , uint16_t *length);
static uint8_t *     USBD_FS_LangIDStrDescriptor( USBD_SpeedTypeDef speed , uint16_t *length);
static uint8_t *     USBD_FS_ManufacturerStrDescriptor ( USBD_SpeedTypeDef speed , uint16_t *length);
static uint8_t *     USBD_FS_ProductStrDescriptor ( USBD_SpeedTypeDef speed , uint16_t *length);
static uint8_t *     USBD_FS_SerialStrDescriptor( USBD_SpeedTypeDef speed , uint16_t *length);
//static uint8_t *     USBD_FS_ConfigStrDescriptor( USBD_SpeedTypeDef speed , uint16_t *length);
//static uint8_t *     USBD_FS_InterfaceStrDescriptor( USBD_SpeedTypeDef speed , uint16_t *length);
USBD_DescriptorsTypeDef FS_Desc =
{
  USBD_FS_DeviceDescriptor,
  USBD_FS_LangIDStrDescriptor, 
  USBD_FS_ManufacturerStrDescriptor,
  USBD_FS_ProductStrDescriptor,
  USBD_FS_SerialStrDescriptor,
  USBD_FS_ProductStrDescriptor, //USBD_FS_ConfigDescriptor,
  USBD_FS_ProductStrDescriptor  //USBD_FS_InterfaceDescriptor,
};


#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif
/* USB OSCILL device Configuration Descriptor */
static uint8_t USBD_OSCILL_CfgDesc[USB_OSCILL_CONFIG_DESC_SIZ] =
{
  0x09, /* bLength: Configuation Descriptor size */
  USB_DESC_TYPE_OTHER_SPEED_CONFIGURATION, /* bDescriptorType: Configuration */
  USB_OSCILL_CONFIG_DESC_SIZ,
  /* wTotalLength: Bytes returned */
  0x00,
  0x01,         /*bNumInterfaces: 1 interface*/
  0x01,         /*bConfigurationValue: Configuration value*/
  0x02,         /*iConfiguration: Index of string descriptor describing the configuration*/
  0xC0,         /*bmAttributes: bus powered and Supprts Remote Wakeup */
  0x32,         /*MaxPower 100 mA: this current is used for detecting Vbus*/
  
  /**********  Descriptor of OSCILL interface 0 Alternate setting 0 **************/  
	/*Interface Descriptor*/
	0x09,   /* bLength: Interface Descriptor size */
	0x04,   /* bDescriptorType: Interface */
	0x00,   /* bInterfaceNumber: Number of Interface */
	0x00,   /* bAlternateSetting: Alternate setting */
	0x03,   /* bNumEndpoints: One endpoints used */
	0xFF,   /* bInterfaceClass: Vendor Specific*/
	0xEA,   /* bInterfaceSubClass*/
	0x00,   /* bInterfaceProtocol*/
	0x00,   /* iInterface: */  

  /*Endpoint 1 Descriptor*/
    0x07,   /* bLength: Endpoint Descriptor size */
    0x05,   /* bDescriptorType: Endpoint */
    OSCILL_IN_EP,   /* bEndpointAddress: */
    0x02,   /* bmAttributes: Bulk */
    USB_FS_MAX_PACKET_SIZE,      /* wMaxPacketSize: */
    0x00,
    0x00,   /* bInterval: */

	/*Endpoint 2 Descriptor*/
    0x07,   /* bLength: Endpoint Descriptor size */
    0x05,   /* bDescriptorType: Endpoint */
    OSCILL_OUT_CONF_EP,   /* bEndpointAddress: */
    0x02,   /* bmAttributes: Bulk */
    USB_FS_MAX_PACKET_SIZE,      /* wMaxPacketSize: */
    0x00,
    0x00,   /* bInterval: */

	/*Endpoint 2 Descriptor*/
    0x07,   /* bLength: Endpoint Descriptor size */
    0x05,   /* bDescriptorType: Endpoint */
    OSCILL_OUT_DATA_EP,   /* bEndpointAddress: */
    0x02,   /* bmAttributes: Bulk */
    USB_FS_MAX_PACKET_SIZE,      /* wMaxPacketSize: */
    0x00,
    0x00   /* bInterval: */
};

  
#if defined ( __ICCARM__ ) /*!< IAR Compiler */
  #pragma data_alignment=4   
#endif

/* USB Standard Device Descriptor */
static uint8_t USBD_OSCILL_DeviceDesc[USB_LEN_DEV_DESC] =
{
  USB_LEN_DEV_DESC,
	USB_DESC_TYPE_DEVICE,
  0x00, //USB version BCD
  0x02, //USB version BCD
  0xFF, //Vendor-specific class
  0xEA, //Some subclass
  0xFF, //Vendor-specific protocol
  USB_FS_MAX_PACKET_SIZE, //Max packet size
  0xE1, //vendor id
  0xE1, //vendor id
	0xC1, //product Id
	0x0C, //product Id
	0x01, //version bcd
	0x00, //version bcd
  1,              /* Index of string descriptor describing manufacturer */
  2,              /* Index of string descriptor describing product */
  3,              /* Index of string descriptor describing the device's serial number */
  0x01    /* bNumConfigurations */};

/**
  * @}
  */ 

/** @defgroup USBD_OSCILL_Private_Functions
  * @{
  */ 

/**
  * @brief  USBD_OSCILL_Init
  *         Initialize the OSCILL interface
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
static uint8_t  USBD_OSCILL_Init (USBD_HandleTypeDef *pdev, 
                               uint8_t cfgidx)
{
  uint8_t ret = 0;
//  USBD_OSCILL_HandleTypeDef   *hcdc;


	/* Open EP IN */
	USBD_LL_OpenEP(pdev,
								 OSCILL_IN_EP,
								 USBD_EP_TYPE_BULK,
								 USB_FS_MAX_PACKET_SIZE);
	
	/* Open EP CONF OUT */
	USBD_LL_OpenEP(pdev,
								 OSCILL_OUT_CONF_EP,
								 USBD_EP_TYPE_BULK,
								 USB_FS_MAX_PACKET_SIZE);

	/* Open EP DATA OUT */
	USBD_LL_OpenEP(pdev,
								 OSCILL_OUT_DATA_EP,
								 USBD_EP_TYPE_BULK,
								 USB_FS_MAX_PACKET_SIZE);
								 
								 
//  pdev->pClassData = USBD_malloc(sizeof (USBD_OSCILL_HandleTypeDef));
  
		/* Prepare Out endpoint to receive next packet */
	USBD_LL_PrepareReceive(pdev,
												 OSCILL_OUT_CONF_EP,
												 OSCILL_CONF_TX_BUFF,
												 USB_FS_MAX_PACKET_SIZE);
	USBD_LL_PrepareReceive(pdev,
												 OSCILL_OUT_DATA_EP,
												 OSCILL_DATA_TX_BUFF,
												 USB_FS_MAX_PACKET_SIZE);
  return ret;
}

/**
  * @brief  USBD_OSCILL_Init
  *         DeInitialize the OSCILL layer
  * @param  pdev: device instance
  * @param  cfgidx: Configuration index
  * @retval status
  */
static uint8_t  USBD_OSCILL_DeInit (USBD_HandleTypeDef *pdev, 
                                 uint8_t cfgidx)
{
  USBD_LL_CloseEP(pdev,
              OSCILL_IN_EP);
  
  /* Open EP OUT */
  USBD_LL_CloseEP(pdev,
              OSCILL_OUT_CONF_EP);
  
  /* Open Command IN EP */
  USBD_LL_CloseEP(pdev,
              OSCILL_OUT_DATA_EP);
  
  

  return USBD_OK;
}

/**
  * @brief  USBD_OSCILL_Setup
  *         Handle the OSCILL specific requests
  * @param  pdev: instance
  * @param  req: usb requests
  * @retval status
  */
static uint8_t  USBD_OSCILL_Setup (USBD_HandleTypeDef *pdev, 
                                USBD_SetupReqTypedef *req)
{
 
  switch (req->bmRequest & USB_REQ_TYPE_MASK)
  {
  case USB_REQ_TYPE_CLASS :  
    switch (req->bRequest)
    {
      
    default:
      USBD_CtlError (pdev, req);
      return USBD_FAIL; 
    }
    break;
    
  case USB_REQ_TYPE_STANDARD:
    switch (req->bRequest)
    {
    
    default:
      USBD_CtlError (pdev, req);
      return USBD_FAIL;     
    }
  }
  return USBD_OK;
}


/**
  * @brief  USBD_OSCILL_GetCfgDesc 
  *         return configuration descriptor
  * @param  length : pointer data length
  * @retval pointer to descriptor buffer
  */
static uint8_t  *USBD_OSCILL_GetCfgDesc (uint16_t *length)
{
  *length = sizeof (USBD_OSCILL_CfgDesc);
  return USBD_OSCILL_CfgDesc;
}



/**
  * @brief  USBD_OSCILL_DataIn
  *         handle data IN Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t  USBD_OSCILL_DataIn (USBD_HandleTypeDef *pdev, 
                              uint8_t epnum)
{

  return USBD_OK;
}

/**
  * @brief  USBD_OSCILL_EP0_RxReady
  *         handle EP0 Rx Ready event
  * @param  pdev: device instance
  * @retval status
  */
static uint8_t  USBD_OSCILL_EP0_RxReady (USBD_HandleTypeDef *pdev)
{

  return USBD_OK;
}
/**
  * @brief  USBD_OSCILL_EP0_TxReady
  *         handle EP0 TRx Ready event
  * @param  pdev: device instance
  * @retval status
  */
static uint8_t  USBD_OSCILL_EP0_TxReady (USBD_HandleTypeDef *pdev)
{

  return USBD_OK;
}

/**
  * @brief  USBD_OSCILL_DataOut
  *         handle data OUT Stage
  * @param  pdev: device instance
  * @param  epnum: endpoint index
  * @retval status
  */
static uint8_t  USBD_OSCILL_DataOut (USBD_HandleTypeDef *pdev, 
                              uint8_t epnum)
{

  return USBD_OK;
}

/**
* @brief  DeviceDescriptor 
*         return Device descriptor
* @param  length : pointer data length
* @retval pointer to descriptor buffer
*/
uint8_t  *USBD_OSCILL_GetDeviceDesc (uint16_t *length)
{
  *length = sizeof (USBD_OSCILL_DeviceDesc);
  return USBD_OSCILL_DeviceDesc;
}

/* USB String Descriptors */
const uint8_t USB_StringLangID[SIZ_STRING_LANGID] =
  {
	SIZ_STRING_LANGID,	/* bLength */
    0x03,	/* String descriptor */
    0x09,
    0x04 /* LangID = 0x0409: U.S. English */
  };

const uint8_t USB_StringVendor[SIZ_STRING_VENDOR] =
  {
	SIZ_STRING_VENDOR,    		 /* Size of Vendor string */
    0x03,            /* bDescriptorType*/
    /* Manufacturer: "Amon-Ra" */
    'e', 0, 'l', 0, 'm', 0, 't', 0, '.', 0, 'x', 0, 'y', 0, 'z', 0
  };

const uint8_t USB_StringProduct[SIZ_STRING_PRODUCT] =
  {
	SIZ_STRING_PRODUCT,          /* bLength */
    0x03,        /* bDescriptorType */
    /* Product name: "USB LCD" */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, 'F', 0, '-', 0, 
		'O', 0, 's', 0, 'c', 0, 'i', 0, 'l', 0, 'l', 0, 'o', 0, 's', 0, 'c', 0, 'o', 0, 'p', 0, 'e', 0
  };

uint8_t USB_StringSerial[SIZ_STRING_SERIAL] =
  {
	SIZ_STRING_SERIAL,           /* bLength */
    0x03,           /* bDescriptorType */
    '0', 0, '.', 0, '1', 0, 'A', 0, 'l', 0, 'p', 0, 'h', 0, 'a', 0
  };

/**
* @brief  StringDescriptors 
*         return String descriptor
* @param  index : descriptor index
* @param  length : pointer data length
* @retval pointer to descriptor buffer
*/
uint8_t  *USBD_OSCILL_GetStrDesc(USBD_HandleTypeDef *pdev ,uint8_t index,  uint16_t *length){
	const uint8_t * descriptor;
	switch(index) {
		case 0: descriptor = USB_StringLangID; break;
		case 1: descriptor = USB_StringVendor; break;
		case 2: descriptor = USB_StringProduct; break;
		case 3: descriptor = USB_StringSerial; break;
		default: return NULL;
	}
	* length = descriptor[0];
	return (uint8_t*)descriptor;
}
/**
  * @}
  */ 
void USB_OSCILL_Init(void)
{
/* Init Device Library */
  USBD_Init(&hUsbDeviceFS, &FS_Desc, 0);//todo inline, move descriptors to flash
  
  /* Register the HID class */
  USBD_RegisterClass(&hUsbDeviceFS, &USBD_OSCILL_ClassDriver);//todo inline
  
  /* Start Device Process */
  USBD_Start(&hUsbDeviceFS);//todo inline
}

/**
* @brief  USBD_FS_DeviceDescriptor 
*         return the device descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *  USBD_FS_DeviceDescriptor( USBD_SpeedTypeDef speed , uint16_t *length)
{
  *length = sizeof(USBD_OSCILL_DeviceDesc);
  return USBD_OSCILL_DeviceDesc;
}

/**
* @brief  USBD_FS_LangIDStrDescriptor 
*         return the LangID string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *  USBD_FS_LangIDStrDescriptor( USBD_SpeedTypeDef speed , uint16_t *length)
{
  *length =  sizeof(USB_StringLangID);  
  return (uint8_t *)USB_StringLangID;
}

/**
* @brief  USBD_FS_ProductStrDescriptor 
*         return the product string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *  USBD_FS_ProductStrDescriptor( USBD_SpeedTypeDef speed , uint16_t *length)
{
  *length =  sizeof(USB_StringProduct);  
  return (uint8_t *)USB_StringProduct;
}

/**
* @brief  USBD_FS_ManufacturerStrDescriptor 
*         return the manufacturer string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *  USBD_FS_ManufacturerStrDescriptor( USBD_SpeedTypeDef speed , uint16_t *length)
{
  *length =  sizeof(USB_StringVendor);  
  return (uint8_t *)USB_StringVendor;
}

/**
* @brief  USBD_FS_SerialStrDescriptor 
*         return the serial number string descriptor
* @param  speed : current device speed
* @param  length : pointer to data length variable
* @retval pointer to descriptor buffer
*/
uint8_t *  USBD_FS_SerialStrDescriptor( USBD_SpeedTypeDef speed , uint16_t *length)
{
  *length =  sizeof(USB_StringSerial);  
  return (uint8_t *)USB_StringSerial;
}

/**
  * @}
  */ 


/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
