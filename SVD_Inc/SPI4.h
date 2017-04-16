// SPI1
 extern struct {
// CR1
 struct {
      unsigned int CPHA: 1; // CPHA
      unsigned int CPOL: 1; // CPOL
      unsigned int MSTR: 1; // MSTR
      unsigned int BR: 3; // BR
      unsigned int SPE: 1; // SPE
      unsigned int LSBFIRST: 1; // LSBFIRST
      unsigned int SSI: 1; // SSI
      unsigned int SSM: 1; // SSM
      unsigned int RXONLY: 1; // RXONLY
      unsigned int DFF: 1; // DFF
      unsigned int CRCNEXT: 1; // CRCNEXT
      unsigned int CRCEN: 1; // CRCEN
      unsigned int BIDIOE: 1; // BIDIOE
      unsigned int BIDIMODE: 1; // BIDIMODE
      unsigned int : 16; // Reserved
} CR1;
// CR2
 struct {
      unsigned int RXDMAEN: 1; // RXDMAEN
      unsigned int TXDMAEN: 1; // TXDMAEN
      unsigned int SSOE: 1; // SSOE
      unsigned int NSSP: 1; // NSSP
      unsigned int FRF: 1; // FRF
      unsigned int ERRIE: 1; // ERRIE
      unsigned int RXNEIE: 1; // RXNEIE
      unsigned int TXEIE: 1; // TXEIE
      unsigned int DS: 4; // DS
      unsigned int FRXTH: 1; // FRXTH
      unsigned int LDMA_RX: 1; // LDMA_RX
      unsigned int LDMA_TX: 1; // LDMA_TX
      unsigned int : 17; // Reserved
} CR2;
// SR
 struct {
      unsigned int RXNE: 1; // RXNE
      unsigned int TXE: 1; // TXE
      unsigned int CHSIDE: 1; // CHSIDE
      unsigned int UDR: 1; // UDR
      unsigned int CRCERR: 1; // CRCERR
      unsigned int MODF: 1; // MODF
      unsigned int OVR: 1; // OVR
      unsigned int BSY: 1; // BSY
      unsigned int TIFRFE: 1; // TIFRFE
      unsigned int FRLVL: 2; // FRLVL
      unsigned int FTLVL: 2; // FTLVL
      unsigned int : 19; // Reserved
} SR;
// DR
 struct {
      unsigned int DR: 16; // DR
      unsigned int : 16; // Reserved
} DR;
// CRCPR
 struct {
      unsigned int CRCPOLY: 16; // CRCPOLY
      unsigned int : 16; // Reserved
} CRCPR;
// RXCRCR
 struct {
      unsigned int RxCRC: 16; // RxCRC
      unsigned int : 16; // Reserved
} RXCRCR;
// TXCRCR
 struct {
      unsigned int TxCRC: 16; // TxCRC
      unsigned int : 16; // Reserved
} TXCRCR;
// I2SCFGR
 struct {
      unsigned int CHLEN: 1; // CHLEN
      unsigned int DATLEN: 2; // DATLEN
      unsigned int CKPOL: 1; // CKPOL
      unsigned int I2SSTD: 2; // I2SSTD
      unsigned int : 1; // Reserved
      unsigned int PCMSYNC: 1; // PCMSYNC
      unsigned int I2SCFG: 2; // I2SCFG
      unsigned int I2SE: 1; // I2SE
      unsigned int I2SMOD: 1; // I2SMOD
      unsigned int : 20; // Reserved
} I2SCFGR;
// I2SPR
 struct {
      unsigned int I2SDIV: 8; // I2SDIV
      unsigned int ODD: 1; // ODD
      unsigned int MCKOE: 1; // MCKOE
      unsigned int : 22; // Reserved
} I2SPR;
} SVD_SPI4 __attribute__ ((packed));
asm(".equ SVD_SPI4, 0x40013c00");
