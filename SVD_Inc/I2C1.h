// Inter-integrated circuit
 extern struct {
// Control register 1
 struct {
      unsigned int PE: 1; // Peripheral enable
      unsigned int TXIE: 1; // TX Interrupt enable
      unsigned int RXIE: 1; // RX Interrupt enable
      unsigned int ADDRIE: 1; // Address match interrupt enable (slave only)
      unsigned int NACKIE: 1; // Not acknowledge received interrupt enable
      unsigned int STOPIE: 1; // STOP detection Interrupt enable
      unsigned int TCIE: 1; // Transfer Complete interrupt enable
      unsigned int ERRIE: 1; // Error interrupts enable
      unsigned int DNF: 4; // Digital noise filter
      unsigned int ANFOFF: 1; // Analog noise filter OFF
      unsigned int SWRST: 1; // Software reset
      unsigned int TXDMAEN: 1; // DMA transmission requests enable
      unsigned int RXDMAEN: 1; // DMA reception requests enable
      unsigned int SBC: 1; // Slave byte control
      unsigned int NOSTRETCH: 1; // Clock stretching disable
      unsigned int WUPEN: 1; // Wakeup from STOP enable
      unsigned int GCEN: 1; // General call enable
      unsigned int SMBHEN: 1; // SMBus Host address enable
      unsigned int SMBDEN: 1; // SMBus Device Default address enable
      unsigned int ALERTEN: 1; // SMBUS alert enable
      unsigned int PECEN: 1; // PEC enable
      unsigned int : 8; // Reserved
} CR1;
// Control register 2
 struct {
      unsigned int SADD0: 1; // Slave address bit 0 (master mode)
      unsigned int SADD1: 7; // Slave address bit 7:1 (master mode)
      unsigned int SADD8: 2; // Slave address bit 9:8 (master mode)
      unsigned int RD_WRN: 1; // Transfer direction (master mode)
      unsigned int ADD10: 1; // 10-bit addressing mode (master mode)
      unsigned int HEAD10R: 1; // 10-bit address header only read direction (master receiver mode)
      unsigned int START: 1; // Start generation
      unsigned int STOP: 1; // Stop generation (master mode)
      unsigned int NACK: 1; // NACK generation (slave mode)
      unsigned int NBYTES: 8; // Number of bytes
      unsigned int RELOAD: 1; // NBYTES reload mode
      unsigned int AUTOEND: 1; // Automatic end mode (master mode)
      unsigned int PECBYTE: 1; // Packet error checking byte
      unsigned int : 5; // Reserved
} CR2;
// Own address register 1
 struct {
      unsigned int OA1_0: 1; // Interface address
      unsigned int OA1_1: 7; // Interface address
      unsigned int OA1_8: 2; // Interface address
      unsigned int OA1MODE: 1; // Own Address 1 10-bit mode
      unsigned int : 4; // Reserved
      unsigned int OA1EN: 1; // Own Address 1 enable
      unsigned int : 16; // Reserved
} OAR1;
// Own address register 2
 struct {
      unsigned int : 1; // Reserved
      unsigned int OA2: 7; // Interface address
      unsigned int OA2MSK: 3; // Own Address 2 masks
      unsigned int : 4; // Reserved
      unsigned int OA2EN: 1; // Own Address 2 enable
      unsigned int : 16; // Reserved
} OAR2;
// Timing register
 struct {
      unsigned int SCLL: 8; // SCL low period (master mode)
      unsigned int SCLH: 8; // SCL high period (master mode)
      unsigned int SDADEL: 4; // Data hold time
      unsigned int SCLDEL: 4; // Data setup time
      unsigned int : 4; // Reserved
      unsigned int PRESC: 4; // Timing prescaler
} TIMINGR;
// Status register 1
 struct {
      unsigned int TIMEOUTA: 12; // Bus timeout A
      unsigned int TIDLE: 1; // Idle clock timeout detection
      unsigned int : 2; // Reserved
      unsigned int TIMOUTEN: 1; // Clock timeout enable
      unsigned int TIMEOUTB: 12; // Bus timeout B
      unsigned int : 3; // Reserved
      unsigned int TEXTEN: 1; // Extended clock timeout enable
} TIMEOUTR;
// Interrupt and Status register
 struct {
      unsigned int TXE: 1; // Transmit data register empty (transmitters)
      unsigned int TXIS: 1; // Transmit interrupt status (transmitters)
      unsigned int RXNE: 1; // Receive data register not empty (receivers)
      unsigned int ADDR: 1; // Address matched (slave mode)
      unsigned int NACKF: 1; // Not acknowledge received flag
      unsigned int STOPF: 1; // Stop detection flag
      unsigned int TC: 1; // Transfer Complete (master mode)
      unsigned int TCR: 1; // Transfer Complete Reload
      unsigned int BERR: 1; // Bus error
      unsigned int ARLO: 1; // Arbitration lost
      unsigned int OVR: 1; // Overrun/Underrun (slave mode)
      unsigned int PECERR: 1; // PEC Error in reception
      unsigned int TIMEOUT: 1; // Timeout or t_low detection flag
      unsigned int ALERT: 1; // SMBus alert
      unsigned int : 1; // Reserved
      unsigned int BUSY: 1; // Bus busy
      unsigned int DIR: 1; // Transfer direction (Slave mode)
      unsigned int ADDCODE: 7; // Address match code (Slave mode)
      unsigned int : 8; // Reserved
} ISR;
// Interrupt clear register
 struct {
      unsigned int : 3; // Reserved
      unsigned int ADDRCF: 1; // Address Matched flag clear
      unsigned int NACKCF: 1; // Not Acknowledge flag clear
      unsigned int STOPCF: 1; // Stop detection flag clear
      unsigned int : 2; // Reserved
      unsigned int BERRCF: 1; // Bus error flag clear
      unsigned int ARLOCF: 1; // Arbitration lost flag clear
      unsigned int OVRCF: 1; // Overrun/Underrun flag clear
      unsigned int PECCF: 1; // PEC Error flag clear
      unsigned int TIMOUTCF: 1; // Timeout detection flag clear
      unsigned int ALERTCF: 1; // Alert flag clear
      unsigned int : 18; // Reserved
} ICR;
// PEC register
 struct {
      unsigned int PEC: 8; // Packet error checking register
      unsigned int : 24; // Reserved
} PECR;
// Receive data register
 struct {
      unsigned int RXDATA: 8; // 8-bit receive data
      unsigned int : 24; // Reserved
} RXDR;
// Transmit data register
 struct {
      unsigned int TXDATA: 8; // 8-bit transmit data
      unsigned int : 24; // Reserved
} TXDR;
} SVD_I2C1 __attribute__ ((packed));
asm(".equ SVD_I2C1, 0x40005400");
