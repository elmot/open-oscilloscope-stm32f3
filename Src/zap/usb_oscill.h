#ifndef __USB_OSCILL_H_
#define __USB_OSCILL_H_

#include  "usbd_ioreq.h"


#define OSCILL_DATA_FS_IN_PACKET_SIZE 64

typedef struct {
	uint32_t data[OSCILL_DATA_FS_IN_PACKET_SIZE/4]
	}

#endif
