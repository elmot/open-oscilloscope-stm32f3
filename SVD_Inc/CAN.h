// Controller area network
 extern struct {
// master control register
 struct {
      unsigned int INRQ: 1; // INRQ
      unsigned int SLEEP: 1; // SLEEP
      unsigned int TXFP: 1; // TXFP
      unsigned int RFLM: 1; // RFLM
      unsigned int NART: 1; // NART
      unsigned int AWUM: 1; // AWUM
      unsigned int ABOM: 1; // ABOM
      unsigned int TTCM: 1; // TTCM
      unsigned int : 7; // Reserved
      unsigned int RESET: 1; // RESET
      unsigned int DBF: 1; // DBF
      unsigned int : 15; // Reserved
} MCR;
// master status register
 struct {
      unsigned int INAK: 1; // INAK
      unsigned int SLAK: 1; // SLAK
      unsigned int ERRI: 1; // ERRI
      unsigned int WKUI: 1; // WKUI
      unsigned int SLAKI: 1; // SLAKI
      unsigned int : 3; // Reserved
      unsigned int TXM: 1; // TXM
      unsigned int RXM: 1; // RXM
      unsigned int SAMP: 1; // SAMP
      unsigned int RX: 1; // RX
      unsigned int : 20; // Reserved
} MSR;
// transmit status register
 struct {
      unsigned int RQCP0: 1; // RQCP0
      unsigned int TXOK0: 1; // TXOK0
      unsigned int ALST0: 1; // ALST0
      unsigned int TERR0: 1; // TERR0
      unsigned int : 3; // Reserved
      unsigned int ABRQ0: 1; // ABRQ0
      unsigned int RQCP1: 1; // RQCP1
      unsigned int TXOK1: 1; // TXOK1
      unsigned int ALST1: 1; // ALST1
      unsigned int TERR1: 1; // TERR1
      unsigned int : 3; // Reserved
      unsigned int ABRQ1: 1; // ABRQ1
      unsigned int RQCP2: 1; // RQCP2
      unsigned int TXOK2: 1; // TXOK2
      unsigned int ALST2: 1; // ALST2
      unsigned int TERR2: 1; // TERR2
      unsigned int : 3; // Reserved
      unsigned int ABRQ2: 1; // ABRQ2
      unsigned int CODE: 2; // CODE
      unsigned int TME0: 1; // Lowest priority flag for mailbox 0
      unsigned int TME1: 1; // Lowest priority flag for mailbox 1
      unsigned int TME2: 1; // Lowest priority flag for mailbox 2
      unsigned int LOW0: 1; // Lowest priority flag for mailbox 0
      unsigned int LOW1: 1; // Lowest priority flag for mailbox 1
      unsigned int LOW2: 1; // Lowest priority flag for mailbox 2
} TSR;
// receive FIFO 0 register
 struct {
      unsigned int FMP0: 2; // FMP0
      unsigned int : 1; // Reserved
      unsigned int FULL0: 1; // FULL0
      unsigned int FOVR0: 1; // FOVR0
      unsigned int RFOM0: 1; // RFOM0
      unsigned int : 26; // Reserved
} RF0R;
// receive FIFO 1 register
 struct {
      unsigned int FMP1: 2; // FMP1
      unsigned int : 1; // Reserved
      unsigned int FULL1: 1; // FULL1
      unsigned int FOVR1: 1; // FOVR1
      unsigned int RFOM1: 1; // RFOM1
      unsigned int : 26; // Reserved
} RF1R;
// interrupt enable register
 struct {
      unsigned int TMEIE: 1; // TMEIE
      unsigned int FMPIE0: 1; // FMPIE0
      unsigned int FFIE0: 1; // FFIE0
      unsigned int FOVIE0: 1; // FOVIE0
      unsigned int FMPIE1: 1; // FMPIE1
      unsigned int FFIE1: 1; // FFIE1
      unsigned int FOVIE1: 1; // FOVIE1
      unsigned int : 1; // Reserved
      unsigned int EWGIE: 1; // EWGIE
      unsigned int EPVIE: 1; // EPVIE
      unsigned int BOFIE: 1; // BOFIE
      unsigned int LECIE: 1; // LECIE
      unsigned int : 3; // Reserved
      unsigned int ERRIE: 1; // ERRIE
      unsigned int WKUIE: 1; // WKUIE
      unsigned int SLKIE: 1; // SLKIE
      unsigned int : 14; // Reserved
} IER;
// error status register
 struct {
      unsigned int EWGF: 1; // EWGF
      unsigned int EPVF: 1; // EPVF
      unsigned int BOFF: 1; // BOFF
      unsigned int : 1; // Reserved
      unsigned int LEC: 3; // LEC
      unsigned int : 9; // Reserved
      unsigned int TEC: 8; // TEC
      unsigned int REC: 8; // REC
} ESR;
// bit timing register
 struct {
      unsigned int BRP: 10; // BRP
      unsigned int : 6; // Reserved
      unsigned int TS1: 4; // TS1
      unsigned int TS2: 3; // TS2
      unsigned int : 1; // Reserved
      unsigned int SJW: 2; // SJW
      unsigned int : 4; // Reserved
      unsigned int LBKM: 1; // LBKM
      unsigned int SILM: 1; // SILM
} BTR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// TX mailbox identifier register
 struct {
      unsigned int TXRQ: 1; // TXRQ
      unsigned int RTR: 1; // RTR
      unsigned int IDE: 1; // IDE
      unsigned int EXID: 18; // EXID
      unsigned int STID: 11; // STID
} TI0R;
// mailbox data length control and time stamp register
 struct {
      unsigned int DLC: 4; // DLC
      unsigned int : 4; // Reserved
      unsigned int TGT: 1; // TGT
      unsigned int : 7; // Reserved
      unsigned int TIME: 16; // TIME
} TDT0R;
// mailbox data low register
 struct {
      unsigned int DATA0: 8; // DATA0
      unsigned int DATA1: 8; // DATA1
      unsigned int DATA2: 8; // DATA2
      unsigned int DATA3: 8; // DATA3
} TDL0R;
// mailbox data high register
 struct {
      unsigned int DATA4: 8; // DATA4
      unsigned int DATA5: 8; // DATA5
      unsigned int DATA6: 8; // DATA6
      unsigned int DATA7: 8; // DATA7
} TDH0R;
// TX mailbox identifier register
 struct {
      unsigned int TXRQ: 1; // TXRQ
      unsigned int RTR: 1; // RTR
      unsigned int IDE: 1; // IDE
      unsigned int EXID: 18; // EXID
      unsigned int STID: 11; // STID
} TI1R;
// mailbox data length control and time stamp register
 struct {
      unsigned int DLC: 4; // DLC
      unsigned int : 4; // Reserved
      unsigned int TGT: 1; // TGT
      unsigned int : 7; // Reserved
      unsigned int TIME: 16; // TIME
} TDT1R;
// mailbox data low register
 struct {
      unsigned int DATA0: 8; // DATA0
      unsigned int DATA1: 8; // DATA1
      unsigned int DATA2: 8; // DATA2
      unsigned int DATA3: 8; // DATA3
} TDL1R;
// mailbox data high register
 struct {
      unsigned int DATA4: 8; // DATA4
      unsigned int DATA5: 8; // DATA5
      unsigned int DATA6: 8; // DATA6
      unsigned int DATA7: 8; // DATA7
} TDH1R;
// TX mailbox identifier register
 struct {
      unsigned int TXRQ: 1; // TXRQ
      unsigned int RTR: 1; // RTR
      unsigned int IDE: 1; // IDE
      unsigned int EXID: 18; // EXID
      unsigned int STID: 11; // STID
} TI2R;
// mailbox data length control and time stamp register
 struct {
      unsigned int DLC: 4; // DLC
      unsigned int : 4; // Reserved
      unsigned int TGT: 1; // TGT
      unsigned int : 7; // Reserved
      unsigned int TIME: 16; // TIME
} TDT2R;
// mailbox data low register
 struct {
      unsigned int DATA0: 8; // DATA0
      unsigned int DATA1: 8; // DATA1
      unsigned int DATA2: 8; // DATA2
      unsigned int DATA3: 8; // DATA3
} TDL2R;
// mailbox data high register
 struct {
      unsigned int DATA4: 8; // DATA4
      unsigned int DATA5: 8; // DATA5
      unsigned int DATA6: 8; // DATA6
      unsigned int DATA7: 8; // DATA7
} TDH2R;
// receive FIFO mailbox identifier register
 struct {
      unsigned int : 1; // Reserved
      unsigned int RTR: 1; // RTR
      unsigned int IDE: 1; // IDE
      unsigned int EXID: 18; // EXID
      unsigned int STID: 11; // STID
} RI0R;
// receive FIFO mailbox data length control and time stamp register
 struct {
      unsigned int DLC: 4; // DLC
      unsigned int : 4; // Reserved
      unsigned int FMI: 8; // FMI
      unsigned int TIME: 16; // TIME
} RDT0R;
// receive FIFO mailbox data low register
 struct {
      unsigned int DATA0: 8; // DATA0
      unsigned int DATA1: 8; // DATA1
      unsigned int DATA2: 8; // DATA2
      unsigned int DATA3: 8; // DATA3
} RDL0R;
// receive FIFO mailbox data high register
 struct {
      unsigned int DATA4: 8; // DATA4
      unsigned int DATA5: 8; // DATA5
      unsigned int DATA6: 8; // DATA6
      unsigned int DATA7: 8; // DATA7
} RDH0R;
// receive FIFO mailbox identifier register
 struct {
      unsigned int : 1; // Reserved
      unsigned int RTR: 1; // RTR
      unsigned int IDE: 1; // IDE
      unsigned int EXID: 18; // EXID
      unsigned int STID: 11; // STID
} RI1R;
// receive FIFO mailbox data length control and time stamp register
 struct {
      unsigned int DLC: 4; // DLC
      unsigned int : 4; // Reserved
      unsigned int FMI: 8; // FMI
      unsigned int TIME: 16; // TIME
} RDT1R;
// receive FIFO mailbox data low register
 struct {
      unsigned int DATA0: 8; // DATA0
      unsigned int DATA1: 8; // DATA1
      unsigned int DATA2: 8; // DATA2
      unsigned int DATA3: 8; // DATA3
} RDL1R;
// receive FIFO mailbox data high register
 struct {
      unsigned int DATA4: 8; // DATA4
      unsigned int DATA5: 8; // DATA5
      unsigned int DATA6: 8; // DATA6
      unsigned int DATA7: 8; // DATA7
} RDH1R;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// filter master register
 struct {
      unsigned int FINIT: 1; // Filter init mode
      unsigned int : 7; // Reserved
      unsigned int CAN2SB: 6; // CAN2 start bank
      unsigned int : 18; // Reserved
} FMR;
// filter mode register
 struct {
      unsigned int FBM0: 1; // Filter mode
      unsigned int FBM1: 1; // Filter mode
      unsigned int FBM2: 1; // Filter mode
      unsigned int FBM3: 1; // Filter mode
      unsigned int FBM4: 1; // Filter mode
      unsigned int FBM5: 1; // Filter mode
      unsigned int FBM6: 1; // Filter mode
      unsigned int FBM7: 1; // Filter mode
      unsigned int FBM8: 1; // Filter mode
      unsigned int FBM9: 1; // Filter mode
      unsigned int FBM10: 1; // Filter mode
      unsigned int FBM11: 1; // Filter mode
      unsigned int FBM12: 1; // Filter mode
      unsigned int FBM13: 1; // Filter mode
      unsigned int FBM14: 1; // Filter mode
      unsigned int FBM15: 1; // Filter mode
      unsigned int FBM16: 1; // Filter mode
      unsigned int FBM17: 1; // Filter mode
      unsigned int FBM18: 1; // Filter mode
      unsigned int FBM19: 1; // Filter mode
      unsigned int FBM20: 1; // Filter mode
      unsigned int FBM21: 1; // Filter mode
      unsigned int FBM22: 1; // Filter mode
      unsigned int FBM23: 1; // Filter mode
      unsigned int FBM24: 1; // Filter mode
      unsigned int FBM25: 1; // Filter mode
      unsigned int FBM26: 1; // Filter mode
      unsigned int FBM27: 1; // Filter mode
      unsigned int : 4; // Reserved
} FM1R;
      unsigned int : 32; // Reserved
// filter scale register
 struct {
      unsigned int FSC0: 1; // Filter scale configuration
      unsigned int FSC1: 1; // Filter scale configuration
      unsigned int FSC2: 1; // Filter scale configuration
      unsigned int FSC3: 1; // Filter scale configuration
      unsigned int FSC4: 1; // Filter scale configuration
      unsigned int FSC5: 1; // Filter scale configuration
      unsigned int FSC6: 1; // Filter scale configuration
      unsigned int FSC7: 1; // Filter scale configuration
      unsigned int FSC8: 1; // Filter scale configuration
      unsigned int FSC9: 1; // Filter scale configuration
      unsigned int FSC10: 1; // Filter scale configuration
      unsigned int FSC11: 1; // Filter scale configuration
      unsigned int FSC12: 1; // Filter scale configuration
      unsigned int FSC13: 1; // Filter scale configuration
      unsigned int FSC14: 1; // Filter scale configuration
      unsigned int FSC15: 1; // Filter scale configuration
      unsigned int FSC16: 1; // Filter scale configuration
      unsigned int FSC17: 1; // Filter scale configuration
      unsigned int FSC18: 1; // Filter scale configuration
      unsigned int FSC19: 1; // Filter scale configuration
      unsigned int FSC20: 1; // Filter scale configuration
      unsigned int FSC21: 1; // Filter scale configuration
      unsigned int FSC22: 1; // Filter scale configuration
      unsigned int FSC23: 1; // Filter scale configuration
      unsigned int FSC24: 1; // Filter scale configuration
      unsigned int FSC25: 1; // Filter scale configuration
      unsigned int FSC26: 1; // Filter scale configuration
      unsigned int FSC27: 1; // Filter scale configuration
      unsigned int : 4; // Reserved
} FS1R;
      unsigned int : 32; // Reserved
// filter FIFO assignment register
 struct {
      unsigned int FFA0: 1; // Filter FIFO assignment for filter 0
      unsigned int FFA1: 1; // Filter FIFO assignment for filter 1
      unsigned int FFA2: 1; // Filter FIFO assignment for filter 2
      unsigned int FFA3: 1; // Filter FIFO assignment for filter 3
      unsigned int FFA4: 1; // Filter FIFO assignment for filter 4
      unsigned int FFA5: 1; // Filter FIFO assignment for filter 5
      unsigned int FFA6: 1; // Filter FIFO assignment for filter 6
      unsigned int FFA7: 1; // Filter FIFO assignment for filter 7
      unsigned int FFA8: 1; // Filter FIFO assignment for filter 8
      unsigned int FFA9: 1; // Filter FIFO assignment for filter 9
      unsigned int FFA10: 1; // Filter FIFO assignment for filter 10
      unsigned int FFA11: 1; // Filter FIFO assignment for filter 11
      unsigned int FFA12: 1; // Filter FIFO assignment for filter 12
      unsigned int FFA13: 1; // Filter FIFO assignment for filter 13
      unsigned int FFA14: 1; // Filter FIFO assignment for filter 14
      unsigned int FFA15: 1; // Filter FIFO assignment for filter 15
      unsigned int FFA16: 1; // Filter FIFO assignment for filter 16
      unsigned int FFA17: 1; // Filter FIFO assignment for filter 17
      unsigned int FFA18: 1; // Filter FIFO assignment for filter 18
      unsigned int FFA19: 1; // Filter FIFO assignment for filter 19
      unsigned int FFA20: 1; // Filter FIFO assignment for filter 20
      unsigned int FFA21: 1; // Filter FIFO assignment for filter 21
      unsigned int FFA22: 1; // Filter FIFO assignment for filter 22
      unsigned int FFA23: 1; // Filter FIFO assignment for filter 23
      unsigned int FFA24: 1; // Filter FIFO assignment for filter 24
      unsigned int FFA25: 1; // Filter FIFO assignment for filter 25
      unsigned int FFA26: 1; // Filter FIFO assignment for filter 26
      unsigned int FFA27: 1; // Filter FIFO assignment for filter 27
      unsigned int : 4; // Reserved
} FFA1R;
      unsigned int : 32; // Reserved
// CAN filter activation register
 struct {
      unsigned int FACT0: 1; // Filter active
      unsigned int FACT1: 1; // Filter active
      unsigned int FACT2: 1; // Filter active
      unsigned int FACT3: 1; // Filter active
      unsigned int FACT4: 1; // Filter active
      unsigned int FACT5: 1; // Filter active
      unsigned int FACT6: 1; // Filter active
      unsigned int FACT7: 1; // Filter active
      unsigned int FACT8: 1; // Filter active
      unsigned int FACT9: 1; // Filter active
      unsigned int FACT10: 1; // Filter active
      unsigned int FACT11: 1; // Filter active
      unsigned int FACT12: 1; // Filter active
      unsigned int FACT13: 1; // Filter active
      unsigned int FACT14: 1; // Filter active
      unsigned int FACT15: 1; // Filter active
      unsigned int FACT16: 1; // Filter active
      unsigned int FACT17: 1; // Filter active
      unsigned int FACT18: 1; // Filter active
      unsigned int FACT19: 1; // Filter active
      unsigned int FACT20: 1; // Filter active
      unsigned int FACT21: 1; // Filter active
      unsigned int FACT22: 1; // Filter active
      unsigned int FACT23: 1; // Filter active
      unsigned int FACT24: 1; // Filter active
      unsigned int FACT25: 1; // Filter active
      unsigned int FACT26: 1; // Filter active
      unsigned int FACT27: 1; // Filter active
      unsigned int : 4; // Reserved
} FA1R;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// Filter bank 0 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F0R1;
// Filter bank 0 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F0R2;
// Filter bank 1 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F1R1;
// Filter bank 1 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F1R2;
// Filter bank 2 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F2R1;
// Filter bank 2 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F2R2;
// Filter bank 3 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F3R1;
// Filter bank 3 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F3R2;
// Filter bank 4 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F4R1;
// Filter bank 4 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F4R2;
// Filter bank 5 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F5R1;
// Filter bank 5 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F5R2;
// Filter bank 6 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F6R1;
// Filter bank 6 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F6R2;
// Filter bank 7 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F7R1;
// Filter bank 7 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F7R2;
// Filter bank 8 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F8R1;
// Filter bank 8 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F8R2;
// Filter bank 9 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F9R1;
// Filter bank 9 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F9R2;
// Filter bank 10 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F10R1;
// Filter bank 10 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F10R2;
// Filter bank 11 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F11R1;
// Filter bank 11 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F11R2;
// Filter bank 4 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F12R1;
// Filter bank 12 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F12R2;
// Filter bank 13 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F13R1;
// Filter bank 13 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F13R2;
// Filter bank 14 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F14R1;
// Filter bank 14 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F14R2;
// Filter bank 15 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F15R1;
// Filter bank 15 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F15R2;
// Filter bank 16 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F16R1;
// Filter bank 16 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F16R2;
// Filter bank 17 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F17R1;
// Filter bank 17 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F17R2;
// Filter bank 18 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F18R1;
// Filter bank 18 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F18R2;
// Filter bank 19 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F19R1;
// Filter bank 19 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F19R2;
// Filter bank 20 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F20R1;
// Filter bank 20 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F20R2;
// Filter bank 21 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F21R1;
// Filter bank 21 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F21R2;
// Filter bank 22 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F22R1;
// Filter bank 22 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F22R2;
// Filter bank 23 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F23R1;
// Filter bank 23 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F23R2;
// Filter bank 24 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F24R1;
// Filter bank 24 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F24R2;
// Filter bank 25 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F25R1;
// Filter bank 25 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F25R2;
// Filter bank 26 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F26R1;
// Filter bank 26 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F26R2;
// Filter bank 27 register 1
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F27R1;
// Filter bank 27 register 2
 struct {
      unsigned int FB0: 1; // Filter bits
      unsigned int FB1: 1; // Filter bits
      unsigned int FB2: 1; // Filter bits
      unsigned int FB3: 1; // Filter bits
      unsigned int FB4: 1; // Filter bits
      unsigned int FB5: 1; // Filter bits
      unsigned int FB6: 1; // Filter bits
      unsigned int FB7: 1; // Filter bits
      unsigned int FB8: 1; // Filter bits
      unsigned int FB9: 1; // Filter bits
      unsigned int FB10: 1; // Filter bits
      unsigned int FB11: 1; // Filter bits
      unsigned int FB12: 1; // Filter bits
      unsigned int FB13: 1; // Filter bits
      unsigned int FB14: 1; // Filter bits
      unsigned int FB15: 1; // Filter bits
      unsigned int FB16: 1; // Filter bits
      unsigned int FB17: 1; // Filter bits
      unsigned int FB18: 1; // Filter bits
      unsigned int FB19: 1; // Filter bits
      unsigned int FB20: 1; // Filter bits
      unsigned int FB21: 1; // Filter bits
      unsigned int FB22: 1; // Filter bits
      unsigned int FB23: 1; // Filter bits
      unsigned int FB24: 1; // Filter bits
      unsigned int FB25: 1; // Filter bits
      unsigned int FB26: 1; // Filter bits
      unsigned int FB27: 1; // Filter bits
      unsigned int FB28: 1; // Filter bits
      unsigned int FB29: 1; // Filter bits
      unsigned int FB30: 1; // Filter bits
      unsigned int FB31: 1; // Filter bits
} F27R2;
} SVD_CAN;
asm(".equ SVD_CAN, 0x40006400");
