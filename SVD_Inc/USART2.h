// USART1
 extern struct {
// CR1
 struct {
      unsigned int UE: 1; // UE
      unsigned int UESM: 1; // UESM
      unsigned int RE: 1; // RE
      unsigned int TE: 1; // TE
      unsigned int IDLEIE: 1; // IDLEIE
      unsigned int RXNEIE: 1; // RXNEIE
      unsigned int TCIE: 1; // TCIE
      unsigned int TXEIE: 1; // TXEIE
      unsigned int PEIE: 1; // PEIE
      unsigned int PS: 1; // PS
      unsigned int PCE: 1; // PCE
      unsigned int WAKE: 1; // WAKE
      unsigned int M: 1; // M
      unsigned int MME: 1; // MME
      unsigned int CMIE: 1; // CMIE
      unsigned int OVER8: 1; // OVER8
      unsigned int DEDT: 5; // DEDT
      unsigned int DEAT: 5; // DEAT
      unsigned int RTOIE: 1; // RTOIE
      unsigned int EOBIE: 1; // EOBIE
      unsigned int : 4; // Reserved
} CR1;
// CR2
 struct {
      unsigned int : 4; // Reserved
      unsigned int ADDM7: 1; // ADDM7
      unsigned int LBDL: 1; // LBDL
      unsigned int LBDIE: 1; // LBDIE
      unsigned int : 1; // Reserved
      unsigned int LBCL: 1; // LBCL
      unsigned int CPHA: 1; // CPHA
      unsigned int CPOL: 1; // CPOL
      unsigned int CLKEN: 1; // CLKEN
      unsigned int STOP: 2; // STOP
      unsigned int LINEN: 1; // LINEN
      unsigned int SWAP: 1; // SWAP
      unsigned int RXINV: 1; // RXINV
      unsigned int TXINV: 1; // TXINV
      unsigned int DATAINV: 1; // DATAINV
      unsigned int MSBFIRST: 1; // MSBFIRST
      unsigned int ABREN: 1; // ABREN
      unsigned int ABRMOD: 2; // ABRMOD
      unsigned int RTOEN: 1; // RTOEN
      unsigned int ADD0: 4; // ADD0
      unsigned int ADD4: 4; // ADD4
} CR2;
// CR3
 struct {
      unsigned int EIE: 1; // EIE
      unsigned int IREN: 1; // IREN
      unsigned int IRLP: 1; // IRLP
      unsigned int HDSEL: 1; // HDSEL
      unsigned int NACK: 1; // NACK
      unsigned int SCEN: 1; // SCEN
      unsigned int DMAR: 1; // DMAR
      unsigned int DMAT: 1; // DMAT
      unsigned int RTSE: 1; // RTSE
      unsigned int CTSE: 1; // CTSE
      unsigned int CTSIE: 1; // CTSIE
      unsigned int ONEBIT: 1; // ONEBIT
      unsigned int OVRDIS: 1; // OVRDIS
      unsigned int DDRE: 1; // DDRE
      unsigned int DEM: 1; // DEM
      unsigned int DEP: 1; // DEP
      unsigned int : 1; // Reserved
      unsigned int SCARCNT: 3; // SCARCNT
      unsigned int WUS: 2; // WUS
      unsigned int WUFIE: 1; // WUFIE
      unsigned int : 9; // Reserved
} CR3;
// BRR
 struct {
      unsigned int DIV_Fraction: 4; // DIV_Fraction
      unsigned int DIV_Mantissa: 12; // DIV_Mantissa
      unsigned int : 16; // Reserved
} BRR;
// GTPR
 struct {
      unsigned int PSC: 8; // PSC
      unsigned int GT: 8; // GT
      unsigned int : 16; // Reserved
} GTPR;
// RTOR
 struct {
      unsigned int RTO: 24; // RTO
      unsigned int BLEN: 8; // BLEN
} RTOR;
// RQR
 struct {
      unsigned int ABRRQ: 1; // ABRRQ
      unsigned int SBKRQ: 1; // SBKRQ
      unsigned int MMRQ: 1; // MMRQ
      unsigned int RXFRQ: 1; // RXFRQ
      unsigned int TXFRQ: 1; // TXFRQ
      unsigned int : 27; // Reserved
} RQR;
// ISR
 struct {
      unsigned int PE: 1; // PE
      unsigned int FE: 1; // FE
      unsigned int NF: 1; // NF
      unsigned int ORE: 1; // ORE
      unsigned int IDLE: 1; // IDLE
      unsigned int RXNE: 1; // RXNE
      unsigned int TC: 1; // TC
      unsigned int TXE: 1; // TXE
      unsigned int LBDF: 1; // LBDF
      unsigned int CTSIF: 1; // CTSIF
      unsigned int CTS: 1; // CTS
      unsigned int RTOF: 1; // RTOF
      unsigned int EOBF: 1; // EOBF
      unsigned int : 1; // Reserved
      unsigned int ABRE: 1; // ABRE
      unsigned int ABRF: 1; // ABRF
      unsigned int BUSY: 1; // BUSY
      unsigned int CMF: 1; // CMF
      unsigned int SBKF: 1; // SBKF
      unsigned int RWU: 1; // RWU
      unsigned int WUF: 1; // WUF
      unsigned int TEACK: 1; // TEACK
      unsigned int REACK: 1; // REACK
      unsigned int : 9; // Reserved
} ISR;
// ICR
 struct {
      unsigned int PECF: 1; // PECF
      unsigned int FECF: 1; // FECF
      unsigned int NCF: 1; // NCF
      unsigned int ORECF: 1; // ORECF
      unsigned int IDLECF: 1; // IDLECF
      unsigned int : 1; // Reserved
      unsigned int TCCF: 1; // TCCF
      unsigned int : 1; // Reserved
      unsigned int LBDCF: 1; // LBDCF
      unsigned int CTSCF: 1; // CTSCF
      unsigned int : 1; // Reserved
      unsigned int RTOCF: 1; // RTOCF
      unsigned int EOBCF: 1; // EOBCF
      unsigned int : 4; // Reserved
      unsigned int CMCF: 1; // CMCF
      unsigned int : 2; // Reserved
      unsigned int WUCF: 1; // WUCF
      unsigned int : 11; // Reserved
} ICR;
// RDR
 struct {
      unsigned int RDR: 9; // RDR
      unsigned int : 23; // Reserved
} RDR;
// TDR
 struct {
      unsigned int TDR: 9; // TDR
      unsigned int : 23; // Reserved
} TDR;
} SVD_USART2 __attribute__ ((packed));
asm(".equ SVD_USART2, 0x40004400");
