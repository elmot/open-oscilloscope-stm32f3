// Serial peripheral interface/Inter-IC sound
 extern struct {
// control register 1
 struct {
      unsigned int CPHA: 1; // Clock phase
      unsigned int CPOL: 1; // Clock polarity
      unsigned int MSTR: 1; // Master selection
      unsigned int BR: 3; // Baud rate control
      unsigned int SPE: 1; // SPI enable
      unsigned int LSBFIRST: 1; // Frame format
      unsigned int SSI: 1; // Internal slave select
      unsigned int SSM: 1; // Software slave management
      unsigned int RXONLY: 1; // Receive only
      unsigned int DFF: 1; // Data frame format
      unsigned int CRCNEXT: 1; // CRC transfer next
      unsigned int CRCEN: 1; // Hardware CRC calculation enable
      unsigned int BIDIOE: 1; // Output enable in bidirectional mode
      unsigned int BIDIMODE: 1; // Bidirectional data mode enable
      unsigned int : 16; // Reserved
} CR1;
// control register 2
 struct {
      unsigned int RXDMAEN: 1; // Rx buffer DMA enable
      unsigned int TXDMAEN: 1; // Tx buffer DMA enable
      unsigned int SSOE: 1; // SS output enable
      unsigned int NSSP: 1; // NSS pulse management
      unsigned int FRF: 1; // Frame format
      unsigned int ERRIE: 1; // Error interrupt enable
      unsigned int RXNEIE: 1; // RX buffer not empty interrupt enable
      unsigned int TXEIE: 1; // Tx buffer empty interrupt enable
      unsigned int DS: 4; // Data size
      unsigned int FRXTH: 1; // FIFO reception threshold
      unsigned int LDMA_RX: 1; // Last DMA transfer for reception
      unsigned int LDMA_TX: 1; // Last DMA transfer for transmission
      unsigned int : 17; // Reserved
} CR2;
// status register
 struct {
      unsigned int RXNE: 1; // Receive buffer not empty
      unsigned int TXE: 1; // Transmit buffer empty
      unsigned int CHSIDE: 1; // Channel side
      unsigned int UDR: 1; // Underrun flag
      unsigned int CRCERR: 1; // CRC error flag
      unsigned int MODF: 1; // Mode fault
      unsigned int OVR: 1; // Overrun flag
      unsigned int BSY: 1; // Busy flag
      unsigned int TIFRFE: 1; // TI frame format error
      unsigned int FRLVL: 2; // FIFO reception level
      unsigned int FTLVL: 2; // FIFO transmission level
      unsigned int : 19; // Reserved
} SR;
// data register
 struct {
      unsigned int DR: 16; // Data register
      unsigned int : 16; // Reserved
} DR;
// CRC polynomial register
 struct {
      unsigned int CRCPOLY: 16; // CRC polynomial register
      unsigned int : 16; // Reserved
} CRCPR;
// RX CRC register
 struct {
      unsigned int RxCRC: 16; // Rx CRC register
      unsigned int : 16; // Reserved
} RXCRCR;
// TX CRC register
 struct {
      unsigned int TxCRC: 16; // Tx CRC register
      unsigned int : 16; // Reserved
} TXCRCR;
// I2S configuration register
 struct {
      unsigned int CHLEN: 1; // Channel length (number of bits per audio channel)
      unsigned int DATLEN: 2; // Data length to be transferred
      unsigned int CKPOL: 1; // Steady state clock polarity
      unsigned int I2SSTD: 2; // I2S standard selection
      unsigned int : 1; // Reserved
      unsigned int PCMSYNC: 1; // PCM frame synchronization
      unsigned int I2SCFG: 2; // I2S configuration mode
      unsigned int I2SE: 1; // I2S Enable
      unsigned int I2SMOD: 1; // I2S mode selection
      unsigned int : 20; // Reserved
} I2SCFGR;
// I2S prescaler register
 struct {
      unsigned int I2SDIV: 8; // I2S Linear prescaler
      unsigned int ODD: 1; // Odd factor for the prescaler
      unsigned int MCKOE: 1; // Master clock output enable
      unsigned int : 22; // Reserved
} I2SPR;
} SVD_I2S3ext __attribute__ ((packed));
asm(".equ SVD_I2S3ext, 0x40004000");
