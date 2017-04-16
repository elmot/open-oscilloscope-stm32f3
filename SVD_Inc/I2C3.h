// I2C1
 extern struct {
// CR1
 struct {
      unsigned int PE: 1; // PE
      unsigned int TXIE: 1; // TXIE
      unsigned int RXIE: 1; // RXIE
      unsigned int ADDRIE: 1; // ADDRIE
      unsigned int NACKIE: 1; // NACKIE
      unsigned int STOPIE: 1; // STOPIE
      unsigned int TCIE: 1; // TCIE
      unsigned int ERRIE: 1; // ERRIE
      unsigned int DNF: 4; // DNF
      unsigned int ANFOFF: 1; // ANFOFF
      unsigned int SWRST: 1; // SWRST
      unsigned int TXDMAEN: 1; // TXDMAEN
      unsigned int RXDMAEN: 1; // RXDMAEN
      unsigned int SBC: 1; // SBC
      unsigned int NOSTRETCH: 1; // NOSTRETCH
      unsigned int WUPEN: 1; // WUPEN
      unsigned int GCEN: 1; // GCEN
      unsigned int SMBHEN: 1; // SMBHEN
      unsigned int SMBDEN: 1; // SMBDEN
      unsigned int ALERTEN: 1; // ALERTEN
      unsigned int PECEN: 1; // PECEN
      unsigned int : 8; // Reserved
} CR1;
// CR2
 struct {
      unsigned int SADD0: 1; // SADD0
      unsigned int SADD1: 7; // SADD1
      unsigned int SADD8: 2; // SADD8
      unsigned int RD_WRN: 1; // RD_WRN
      unsigned int ADD10: 1; // ADD10
      unsigned int HEAD10R: 1; // HEAD10R
      unsigned int START: 1; // START
      unsigned int STOP: 1; // STOP
      unsigned int NACK: 1; // NACK
      unsigned int NBYTES: 8; // NBYTES
      unsigned int RELOAD: 1; // RELOAD
      unsigned int AUTOEND: 1; // AUTOEND
      unsigned int PECBYTE: 1; // PECBYTE
      unsigned int : 5; // Reserved
} CR2;
// OAR1
 struct {
      unsigned int OA1_0: 1; // OA1_0
      unsigned int OA1_1: 7; // OA1_1
      unsigned int OA1_8: 2; // OA1_8
      unsigned int OA1MODE: 1; // OA1MODE
      unsigned int : 4; // Reserved
      unsigned int OA1EN: 1; // OA1EN
      unsigned int : 16; // Reserved
} OAR1;
// OAR2
 struct {
      unsigned int : 1; // Reserved
      unsigned int OA2: 7; // OA2
      unsigned int OA2MSK: 3; // OA2MSK
      unsigned int : 4; // Reserved
      unsigned int OA2EN: 1; // OA2EN
      unsigned int : 16; // Reserved
} OAR2;
// TIMINGR
 struct {
      unsigned int SCLL: 8; // SCLL
      unsigned int SCLH: 8; // SCLH
      unsigned int SDADEL: 4; // SDADEL
      unsigned int SCLDEL: 4; // SCLDEL
      unsigned int : 4; // Reserved
      unsigned int PRESC: 4; // PRESC
} TIMINGR;
// TIMEOUTR
 struct {
      unsigned int TIMEOUTA: 12; // TIMEOUTA
      unsigned int TIDLE: 1; // TIDLE
      unsigned int : 2; // Reserved
      unsigned int TIMOUTEN: 1; // TIMOUTEN
      unsigned int TIMEOUTB: 12; // TIMEOUTB
      unsigned int : 3; // Reserved
      unsigned int TEXTEN: 1; // TEXTEN
} TIMEOUTR;
// ISR
 struct {
      unsigned int TXE: 1; // TXE
      unsigned int TXIS: 1; // TXIS
      unsigned int RXNE: 1; // RXNE
      unsigned int ADDR: 1; // ADDR
      unsigned int NACKF: 1; // NACKF
      unsigned int STOPF: 1; // STOPF
      unsigned int TC: 1; // TC
      unsigned int TCR: 1; // TCR
      unsigned int BERR: 1; // BERR
      unsigned int ARLO: 1; // ARLO
      unsigned int OVR: 1; // OVR
      unsigned int PECERR: 1; // PECERR
      unsigned int TIMEOUT: 1; // TIMEOUT
      unsigned int ALERT: 1; // ALERT
      unsigned int : 1; // Reserved
      unsigned int BUSY: 1; // BUSY
      unsigned int DIR: 1; // DIR
      unsigned int ADDCODE: 7; // ADDCODE
      unsigned int : 8; // Reserved
} ISR;
// ICR
 struct {
      unsigned int : 3; // Reserved
      unsigned int ADDRCF: 1; // ADDRCF
      unsigned int NACKCF: 1; // NACKCF
      unsigned int STOPCF: 1; // STOPCF
      unsigned int : 2; // Reserved
      unsigned int BERRCF: 1; // BERRCF
      unsigned int ARLOCF: 1; // ARLOCF
      unsigned int OVRCF: 1; // OVRCF
      unsigned int PECCF: 1; // PECCF
      unsigned int TIMOUTCF: 1; // TIMOUTCF
      unsigned int ALERTCF: 1; // ALERTCF
      unsigned int : 18; // Reserved
} ICR;
// PECR
 struct {
      unsigned int PEC: 8; // PEC
      unsigned int : 24; // Reserved
} PECR;
// RXDR
 struct {
      unsigned int RXDATA: 8; // RXDATA
      unsigned int : 24; // Reserved
} RXDR;
// TXDR
 struct {
      unsigned int TXDATA: 8; // TXDATA
      unsigned int : 24; // Reserved
} TXDR;
} SVD_I2C3 __attribute__ ((packed));
asm(".equ SVD_I2C3, 0x40007800");
