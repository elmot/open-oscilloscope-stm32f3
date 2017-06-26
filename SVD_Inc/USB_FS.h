// Universal serial bus full-speed device interface
 extern struct {
// endpoint 0 register
 struct {
      unsigned int EA: 4; // Endpoint address
      unsigned int STAT_TX: 2; // Status bits, for transmission transfers
      unsigned int DTOG_TX: 1; // Data Toggle, for transmission transfers
      unsigned int CTR_TX: 1; // Correct Transfer for transmission
      unsigned int EP_KIND: 1; // Endpoint kind
      unsigned int EP_TYPE: 2; // Endpoint type
      unsigned int SETUP: 1; // Setup transaction completed
      unsigned int STAT_RX: 2; // Status bits, for reception transfers
      unsigned int DTOG_RX: 1; // Data Toggle, for reception transfers
      unsigned int CTR_RX: 1; // Correct transfer for reception
      unsigned int : 16; // Reserved
} USB_EP0R;
// endpoint 1 register
 struct {
      unsigned int EA: 4; // Endpoint address
      unsigned int STAT_TX: 2; // Status bits, for transmission transfers
      unsigned int DTOG_TX: 1; // Data Toggle, for transmission transfers
      unsigned int CTR_TX: 1; // Correct Transfer for transmission
      unsigned int EP_KIND: 1; // Endpoint kind
      unsigned int EP_TYPE: 2; // Endpoint type
      unsigned int SETUP: 1; // Setup transaction completed
      unsigned int STAT_RX: 2; // Status bits, for reception transfers
      unsigned int DTOG_RX: 1; // Data Toggle, for reception transfers
      unsigned int CTR_RX: 1; // Correct transfer for reception
      unsigned int : 16; // Reserved
} USB_EP1R;
// endpoint 2 register
 struct {
      unsigned int EA: 4; // Endpoint address
      unsigned int STAT_TX: 2; // Status bits, for transmission transfers
      unsigned int DTOG_TX: 1; // Data Toggle, for transmission transfers
      unsigned int CTR_TX: 1; // Correct Transfer for transmission
      unsigned int EP_KIND: 1; // Endpoint kind
      unsigned int EP_TYPE: 2; // Endpoint type
      unsigned int SETUP: 1; // Setup transaction completed
      unsigned int STAT_RX: 2; // Status bits, for reception transfers
      unsigned int DTOG_RX: 1; // Data Toggle, for reception transfers
      unsigned int CTR_RX: 1; // Correct transfer for reception
      unsigned int : 16; // Reserved
} USB_EP2R;
// endpoint 3 register
 struct {
      unsigned int EA: 4; // Endpoint address
      unsigned int STAT_TX: 2; // Status bits, for transmission transfers
      unsigned int DTOG_TX: 1; // Data Toggle, for transmission transfers
      unsigned int CTR_TX: 1; // Correct Transfer for transmission
      unsigned int EP_KIND: 1; // Endpoint kind
      unsigned int EP_TYPE: 2; // Endpoint type
      unsigned int SETUP: 1; // Setup transaction completed
      unsigned int STAT_RX: 2; // Status bits, for reception transfers
      unsigned int DTOG_RX: 1; // Data Toggle, for reception transfers
      unsigned int CTR_RX: 1; // Correct transfer for reception
      unsigned int : 16; // Reserved
} USB_EP3R;
// endpoint 4 register
 struct {
      unsigned int EA: 4; // Endpoint address
      unsigned int STAT_TX: 2; // Status bits, for transmission transfers
      unsigned int DTOG_TX: 1; // Data Toggle, for transmission transfers
      unsigned int CTR_TX: 1; // Correct Transfer for transmission
      unsigned int EP_KIND: 1; // Endpoint kind
      unsigned int EP_TYPE: 2; // Endpoint type
      unsigned int SETUP: 1; // Setup transaction completed
      unsigned int STAT_RX: 2; // Status bits, for reception transfers
      unsigned int DTOG_RX: 1; // Data Toggle, for reception transfers
      unsigned int CTR_RX: 1; // Correct transfer for reception
      unsigned int : 16; // Reserved
} USB_EP4R;
// endpoint 5 register
 struct {
      unsigned int EA: 4; // Endpoint address
      unsigned int STAT_TX: 2; // Status bits, for transmission transfers
      unsigned int DTOG_TX: 1; // Data Toggle, for transmission transfers
      unsigned int CTR_TX: 1; // Correct Transfer for transmission
      unsigned int EP_KIND: 1; // Endpoint kind
      unsigned int EP_TYPE: 2; // Endpoint type
      unsigned int SETUP: 1; // Setup transaction completed
      unsigned int STAT_RX: 2; // Status bits, for reception transfers
      unsigned int DTOG_RX: 1; // Data Toggle, for reception transfers
      unsigned int CTR_RX: 1; // Correct transfer for reception
      unsigned int : 16; // Reserved
} USB_EP5R;
// endpoint 6 register
 struct {
      unsigned int EA: 4; // Endpoint address
      unsigned int STAT_TX: 2; // Status bits, for transmission transfers
      unsigned int DTOG_TX: 1; // Data Toggle, for transmission transfers
      unsigned int CTR_TX: 1; // Correct Transfer for transmission
      unsigned int EP_KIND: 1; // Endpoint kind
      unsigned int EP_TYPE: 2; // Endpoint type
      unsigned int SETUP: 1; // Setup transaction completed
      unsigned int STAT_RX: 2; // Status bits, for reception transfers
      unsigned int DTOG_RX: 1; // Data Toggle, for reception transfers
      unsigned int CTR_RX: 1; // Correct transfer for reception
      unsigned int : 16; // Reserved
} USB_EP6R;
// endpoint 7 register
 struct {
      unsigned int EA: 4; // Endpoint address
      unsigned int STAT_TX: 2; // Status bits, for transmission transfers
      unsigned int DTOG_TX: 1; // Data Toggle, for transmission transfers
      unsigned int CTR_TX: 1; // Correct Transfer for transmission
      unsigned int EP_KIND: 1; // Endpoint kind
      unsigned int EP_TYPE: 2; // Endpoint type
      unsigned int SETUP: 1; // Setup transaction completed
      unsigned int STAT_RX: 2; // Status bits, for reception transfers
      unsigned int DTOG_RX: 1; // Data Toggle, for reception transfers
      unsigned int CTR_RX: 1; // Correct transfer for reception
      unsigned int : 16; // Reserved
} USB_EP7R;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// control register
 struct {
      unsigned int FRES: 1; // Force USB Reset
      unsigned int PDWN: 1; // Power down
      unsigned int LPMODE: 1; // Low-power mode
      unsigned int FSUSP: 1; // Force suspend
      unsigned int RESUME: 1; // Resume request
      unsigned int : 3; // Reserved
      unsigned int ESOFM: 1; // Expected start of frame interrupt mask
      unsigned int SOFM: 1; // Start of frame interrupt mask
      unsigned int RESETM: 1; // USB reset interrupt mask
      unsigned int SUSPM: 1; // Suspend mode interrupt mask
      unsigned int WKUPM: 1; // Wakeup interrupt mask
      unsigned int ERRM: 1; // Error interrupt mask
      unsigned int PMAOVRM: 1; // Packet memory area over / underrun interrupt mask
      unsigned int CTRM: 1; // Correct transfer interrupt mask
      unsigned int : 16; // Reserved
} USB_CNTR;
// interrupt status register
 struct {
      unsigned int EP_ID: 4; // Endpoint Identifier
      unsigned int DIR: 1; // Direction of transaction
      unsigned int : 3; // Reserved
      unsigned int ESOF: 1; // Expected start frame
      unsigned int SOF: 1; // start of frame
      unsigned int RESET: 1; // reset request
      unsigned int SUSP: 1; // Suspend mode request
      unsigned int WKUP: 1; // Wakeup
      unsigned int ERR: 1; // Error
      unsigned int PMAOVR: 1; // Packet memory area over / underrun
      unsigned int CTR: 1; // Correct transfer
      unsigned int : 16; // Reserved
} ISTR;
// frame number register
 struct {
      unsigned int FN: 11; // Frame number
      unsigned int LSOF: 2; // Lost SOF
      unsigned int LCK: 1; // Locked
      unsigned int RXDM: 1; // Receive data - line status
      unsigned int RXDP: 1; // Receive data + line status
      unsigned int : 16; // Reserved
} FNR;
// device address
 struct {
      unsigned int ADD: 1; // Device address
      unsigned int ADD1: 1; // Device address
      unsigned int ADD2: 1; // Device address
      unsigned int ADD3: 1; // Device address
      unsigned int ADD4: 1; // Device address
      unsigned int ADD5: 1; // Device address
      unsigned int ADD6: 1; // Device address
      unsigned int EF: 1; // Enable function
      unsigned int : 24; // Reserved
} DADDR;
// Buffer table address
 struct {
      unsigned int : 3; // Reserved
      unsigned int BTABLE: 13; // Buffer table
      unsigned int : 16; // Reserved
} BTABLE;
} SVD_USB_FS;
asm(".equ SVD_USB_FS, 0x40005c00");
