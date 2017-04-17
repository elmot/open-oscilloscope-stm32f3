// Digital-to-analog converter
 extern struct {
// control register
 struct {
      unsigned int EN1: 1; // DAC channel1 enable
      unsigned int BOFF1: 1; // DAC channel1 output buffer disable
      unsigned int TEN1: 1; // DAC channel1 trigger enable
      unsigned int TSEL1: 3; // DAC channel1 trigger selection
      unsigned int WAVE1: 2; // DAC channel1 noise/triangle wave generation enable
      unsigned int MAMP1: 4; // DAC channel1 mask/amplitude selector
      unsigned int DMAEN1: 1; // DAC channel1 DMA enable
      unsigned int DMAUDRIE1: 1; // DAC channel1 DMA Underrun Interrupt enable
      unsigned int : 2; // Reserved
      unsigned int EN2: 1; // DAC channel2 enable
      unsigned int BOFF2: 1; // DAC channel2 output buffer disable
      unsigned int TEN2: 1; // DAC channel2 trigger enable
      unsigned int TSEL2: 3; // DAC channel2 trigger selection
      unsigned int WAVE2: 2; // DAC channel2 noise/triangle wave generation enable
      unsigned int MAMP2: 4; // DAC channel2 mask/amplitude selector
      unsigned int DMAEN2: 1; // DAC channel2 DMA enable
      unsigned int DMAUDRIE2: 1; // DAC channel2 DMA underrun interrupt enable
      unsigned int : 2; // Reserved
} CR;
// software trigger register
 struct {
      unsigned int SWTRIG1: 1; // DAC channel1 software trigger
      unsigned int SWTRIG2: 1; // DAC channel2 software trigger
      unsigned int : 30; // Reserved
} SWTRIGR;
// channel1 12-bit right-aligned data holding register
 struct {
      unsigned int DACC1DHR: 12; // DAC channel1 12-bit right-aligned data
      unsigned int : 20; // Reserved
} DHR12R1;
// channel1 12-bit left aligned data holding register
 struct {
      unsigned int : 4; // Reserved
      unsigned int DACC1DHR: 12; // DAC channel1 12-bit left-aligned data
      unsigned int : 16; // Reserved
} DHR12L1;
// channel1 8-bit right aligned data holding register
 struct {
      unsigned int DACC1DHR: 8; // DAC channel1 8-bit right-aligned data
      unsigned int : 24; // Reserved
} DHR8R1;
// channel2 12-bit right aligned data holding register
 struct {
      unsigned int DACC2DHR: 12; // DAC channel2 12-bit right-aligned data
      unsigned int : 20; // Reserved
} DHR12R2;
// channel2 12-bit left aligned data holding register
 struct {
      unsigned int : 4; // Reserved
      unsigned int DACC2DHR: 12; // DAC channel2 12-bit left-aligned data
      unsigned int : 16; // Reserved
} DHR12L2;
// channel2 8-bit right-aligned data holding register
 struct {
      unsigned int DACC2DHR: 8; // DAC channel2 8-bit right-aligned data
      unsigned int : 24; // Reserved
} DHR8R2;
// Dual DAC 12-bit right-aligned data holding register
 struct {
      unsigned int DACC1DHR: 12; // DAC channel1 12-bit right-aligned data
      unsigned int : 4; // Reserved
      unsigned int DACC2DHR: 12; // DAC channel2 12-bit right-aligned data
      unsigned int : 4; // Reserved
} DHR12RD;
// DUAL DAC 12-bit left aligned data holding register
 struct {
      unsigned int : 4; // Reserved
      unsigned int DACC1DHR: 12; // DAC channel1 12-bit left-aligned data
      unsigned int : 4; // Reserved
      unsigned int DACC2DHR: 12; // DAC channel2 12-bit left-aligned data
} DHR12LD;
// DUAL DAC 8-bit right aligned data holding register
 struct {
      unsigned int DACC1DHR: 8; // DAC channel1 8-bit right-aligned data
      unsigned int DACC2DHR: 8; // DAC channel2 8-bit right-aligned data
      unsigned int : 16; // Reserved
} DHR8RD;
// channel1 data output register
 struct {
      unsigned int DACC1DOR: 12; // DAC channel1 data output
      unsigned int : 20; // Reserved
} DOR1;
// channel2 data output register
 struct {
      unsigned int DACC2DOR: 12; // DAC channel2 data output
      unsigned int : 20; // Reserved
} DOR2;
// status register
 struct {
      unsigned int : 13; // Reserved
      unsigned int DMAUDR1: 1; // DAC channel1 DMA underrun flag
      unsigned int : 15; // Reserved
      unsigned int DMAUDR2: 1; // DAC channel2 DMA underrun flag
      unsigned int : 2; // Reserved
} SR;
} SVD_DAC;
asm(".equ SVD_DAC, 0x40007400");
