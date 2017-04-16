// Advanced-timers
 extern struct {
// control register 1
 struct {
      unsigned int CEN: 1; // Counter enable
      unsigned int UDIS: 1; // Update disable
      unsigned int URS: 1; // Update request source
      unsigned int OPM: 1; // One-pulse mode
      unsigned int DIR: 1; // Direction
      unsigned int CMS: 2; // Center-aligned mode selection
      unsigned int ARPE: 1; // Auto-reload preload enable
      unsigned int CKD: 2; // Clock division
      unsigned int : 1; // Reserved
      unsigned int UIFREMAP: 1; // UIF status bit remapping
      unsigned int : 20; // Reserved
} CR1;
// control register 2
 struct {
      unsigned int CCPC: 1; // Capture/compare preloaded control
      unsigned int : 1; // Reserved
      unsigned int CCUS: 1; // Capture/compare control update selection
      unsigned int CCDS: 1; // Capture/compare DMA selection
      unsigned int MMS: 3; // Master mode selection
      unsigned int TI1S: 1; // TI1 selection
      unsigned int OIS1: 1; // Output Idle state 1
      unsigned int OIS1N: 1; // Output Idle state 1
      unsigned int OIS2: 1; // Output Idle state 2
      unsigned int OIS2N: 1; // Output Idle state 2
      unsigned int OIS3: 1; // Output Idle state 3
      unsigned int OIS3N: 1; // Output Idle state 3
      unsigned int OIS4: 1; // Output Idle state 4
      unsigned int : 1; // Reserved
      unsigned int OIS5: 1; // Output Idle state 5
      unsigned int : 1; // Reserved
      unsigned int OIS6: 1; // Output Idle state 6
      unsigned int : 1; // Reserved
      unsigned int MMS2: 4; // Master mode selection 2
      unsigned int : 8; // Reserved
} CR2;
// slave mode control register
 struct {
      unsigned int SMS: 3; // Slave mode selection
      unsigned int OCCS: 1; // OCREF clear selection
      unsigned int TS: 3; // Trigger selection
      unsigned int MSM: 1; // Master/Slave mode
      unsigned int ETF: 4; // External trigger filter
      unsigned int ETPS: 2; // External trigger prescaler
      unsigned int ECE: 1; // External clock enable
      unsigned int ETP: 1; // External trigger polarity
      unsigned int SMS3: 1; // Slave mode selection bit 3
      unsigned int : 15; // Reserved
} SMCR;
// DMA/Interrupt enable register
 struct {
      unsigned int UIE: 1; // Update interrupt enable
      unsigned int CC1IE: 1; // Capture/Compare 1 interrupt enable
      unsigned int CC2IE: 1; // Capture/Compare 2 interrupt enable
      unsigned int CC3IE: 1; // Capture/Compare 3 interrupt enable
      unsigned int CC4IE: 1; // Capture/Compare 4 interrupt enable
      unsigned int COMIE: 1; // COM interrupt enable
      unsigned int TIE: 1; // Trigger interrupt enable
      unsigned int BIE: 1; // Break interrupt enable
      unsigned int UDE: 1; // Update DMA request enable
      unsigned int CC1DE: 1; // Capture/Compare 1 DMA request enable
      unsigned int CC2DE: 1; // Capture/Compare 2 DMA request enable
      unsigned int CC3DE: 1; // Capture/Compare 3 DMA request enable
      unsigned int CC4DE: 1; // Capture/Compare 4 DMA request enable
      unsigned int COMDE: 1; // Reserved
      unsigned int TDE: 1; // Trigger DMA request enable
      unsigned int : 17; // Reserved
} DIER;
// status register
 struct {
      unsigned int UIF: 1; // Update interrupt flag
      unsigned int CC1IF: 1; // Capture/compare 1 interrupt flag
      unsigned int CC2IF: 1; // Capture/Compare 2 interrupt flag
      unsigned int CC3IF: 1; // Capture/Compare 3 interrupt flag
      unsigned int CC4IF: 1; // Capture/Compare 4 interrupt flag
      unsigned int COMIF: 1; // COM interrupt flag
      unsigned int TIF: 1; // Trigger interrupt flag
      unsigned int BIF: 1; // Break interrupt flag
      unsigned int B2IF: 1; // Break 2 interrupt flag
      unsigned int CC1OF: 1; // Capture/Compare 1 overcapture flag
      unsigned int CC2OF: 1; // Capture/compare 2 overcapture flag
      unsigned int CC3OF: 1; // Capture/Compare 3 overcapture flag
      unsigned int CC4OF: 1; // Capture/Compare 4 overcapture flag
      unsigned int : 3; // Reserved
      unsigned int C5IF: 1; // Capture/Compare 5 interrupt flag
      unsigned int C6IF: 1; // Capture/Compare 6 interrupt flag
      unsigned int : 14; // Reserved
} SR;
// event generation register
 struct {
      unsigned int UG: 1; // Update generation
      unsigned int CC1G: 1; // Capture/compare 1 generation
      unsigned int CC2G: 1; // Capture/compare 2 generation
      unsigned int CC3G: 1; // Capture/compare 3 generation
      unsigned int CC4G: 1; // Capture/compare 4 generation
      unsigned int COMG: 1; // Capture/Compare control update generation
      unsigned int TG: 1; // Trigger generation
      unsigned int BG: 1; // Break generation
      unsigned int B2G: 1; // Break 2 generation
      unsigned int : 23; // Reserved
} EGR;
// capture/compare mode register (output mode)
 struct {
      unsigned int CC1S: 2; // Capture/Compare 1 selection
      unsigned int OC1FE: 1; // Output Compare 1 fast enable
      unsigned int OC1PE: 1; // Output Compare 1 preload enable
      unsigned int OC1M: 3; // Output Compare 1 mode
      unsigned int OC1CE: 1; // Output Compare 1 clear enable
      unsigned int CC2S: 2; // Capture/Compare 2 selection
      unsigned int OC2FE: 1; // Output Compare 2 fast enable
      unsigned int OC2PE: 1; // Output Compare 2 preload enable
      unsigned int OC2M: 3; // Output Compare 2 mode
      unsigned int OC2CE: 1; // Output Compare 2 clear enable
      unsigned int OC1M_3: 1; // Output Compare 1 mode bit 3
      unsigned int : 7; // Reserved
      unsigned int OC2M_3: 1; // Output Compare 2 mode bit 3
      unsigned int : 7; // Reserved
} CCMR1_Output;
// capture/compare mode register (output mode)
 struct {
      unsigned int CC3S: 2; // Capture/Compare 3 selection
      unsigned int OC3FE: 1; // Output compare 3 fast enable
      unsigned int OC3PE: 1; // Output compare 3 preload enable
      unsigned int OC3M: 3; // Output compare 3 mode
      unsigned int OC3CE: 1; // Output compare 3 clear enable
      unsigned int CC4S: 2; // Capture/Compare 4 selection
      unsigned int OC4FE: 1; // Output compare 4 fast enable
      unsigned int OC4PE: 1; // Output compare 4 preload enable
      unsigned int OC4M: 3; // Output compare 4 mode
      unsigned int OC4CE: 1; // Output compare 4 clear enable
      unsigned int OC3M_3: 1; // Output Compare 3 mode bit 3
      unsigned int : 7; // Reserved
      unsigned int OC4M_3: 1; // Output Compare 4 mode bit 3
      unsigned int : 7; // Reserved
} CCMR2_Output;
// capture/compare enable register
 struct {
      unsigned int CC1E: 1; // Capture/Compare 1 output enable
      unsigned int CC1P: 1; // Capture/Compare 1 output Polarity
      unsigned int CC1NE: 1; // Capture/Compare 1 complementary output enable
      unsigned int CC1NP: 1; // Capture/Compare 1 output Polarity
      unsigned int CC2E: 1; // Capture/Compare 2 output enable
      unsigned int CC2P: 1; // Capture/Compare 2 output Polarity
      unsigned int CC2NE: 1; // Capture/Compare 2 complementary output enable
      unsigned int CC2NP: 1; // Capture/Compare 2 output Polarity
      unsigned int CC3E: 1; // Capture/Compare 3 output enable
      unsigned int CC3P: 1; // Capture/Compare 3 output Polarity
      unsigned int CC3NE: 1; // Capture/Compare 3 complementary output enable
      unsigned int CC3NP: 1; // Capture/Compare 3 output Polarity
      unsigned int CC4E: 1; // Capture/Compare 4 output enable
      unsigned int CC4P: 1; // Capture/Compare 3 output Polarity
      unsigned int : 1; // Reserved
      unsigned int CC4NP: 1; // Capture/Compare 4 output Polarity
      unsigned int CC5E: 1; // Capture/Compare 5 output enable
      unsigned int CC5P: 1; // Capture/Compare 5 output Polarity
      unsigned int : 2; // Reserved
      unsigned int CC6E: 1; // Capture/Compare 6 output enable
      unsigned int CC6P: 1; // Capture/Compare 6 output Polarity
      unsigned int : 10; // Reserved
} CCER;
// counter
 struct {
      unsigned int CNT: 16; // counter value
      unsigned int : 15; // Reserved
      unsigned int UIFCPY: 1; // UIF copy
} CNT;
// prescaler
 struct {
      unsigned int PSC: 16; // Prescaler value
      unsigned int : 16; // Reserved
} PSC;
// auto-reload register
 struct {
      unsigned int ARR: 16; // Auto-reload value
      unsigned int : 16; // Reserved
} ARR;
// repetition counter register
 struct {
      unsigned int REP: 16; // Repetition counter value
      unsigned int : 16; // Reserved
} RCR;
// capture/compare register 1
 struct {
      unsigned int CCR1: 16; // Capture/Compare 1 value
      unsigned int : 16; // Reserved
} CCR1;
// capture/compare register 2
 struct {
      unsigned int CCR2: 16; // Capture/Compare 2 value
      unsigned int : 16; // Reserved
} CCR2;
// capture/compare register 3
 struct {
      unsigned int CCR3: 16; // Capture/Compare 3 value
      unsigned int : 16; // Reserved
} CCR3;
// capture/compare register 4
 struct {
      unsigned int CCR4: 16; // Capture/Compare 3 value
      unsigned int : 16; // Reserved
} CCR4;
// break and dead-time register
 struct {
      unsigned int DTG: 8; // Dead-time generator setup
      unsigned int LOCK: 2; // Lock configuration
      unsigned int OSSI: 1; // Off-state selection for Idle mode
      unsigned int OSSR: 1; // Off-state selection for Run mode
      unsigned int BKE: 1; // Break enable
      unsigned int BKP: 1; // Break polarity
      unsigned int AOE: 1; // Automatic output enable
      unsigned int MOE: 1; // Main output enable
      unsigned int BKF: 4; // Break filter
      unsigned int BK2F: 4; // Break 2 filter
      unsigned int BK2E: 1; // Break 2 enable
      unsigned int BK2P: 1; // Break 2 polarity
      unsigned int : 6; // Reserved
} BDTR;
// DMA control register
 struct {
      unsigned int DBA: 5; // DMA base address
      unsigned int : 3; // Reserved
      unsigned int DBL: 5; // DMA burst length
      unsigned int : 19; // Reserved
} DCR;
// DMA address for full transfer
 struct {
      unsigned int DMAB: 16; // DMA register for burst accesses
      unsigned int : 16; // Reserved
} DMAR;
      unsigned int : 32; // Reserved
// capture/compare mode register 3 (output mode)
 struct {
      unsigned int : 2; // Reserved
      unsigned int OC5FE: 1; // Output compare 5 fast enable
      unsigned int OC5PE: 1; // Output compare 5 preload enable
      unsigned int OC5M: 3; // Output compare 5 mode
      unsigned int OC5CE: 1; // Output compare 5 clear enable
      unsigned int : 2; // Reserved
      unsigned int OC6FE: 1; // Output compare 6 fast enable
      unsigned int OC6PE: 1; // Output compare 6 preload enable
      unsigned int OC6M: 3; // Output compare 6 mode
      unsigned int OC6CE: 1; // Output compare 6 clear enable
      unsigned int OC5M_3: 1; // Outout Compare 5 mode bit 3
      unsigned int : 7; // Reserved
      unsigned int OC6M_3: 1; // Outout Compare 6 mode bit 3
      unsigned int : 7; // Reserved
} CCMR3_Output;
// capture/compare register 5
 struct {
      unsigned int CCR5: 16; // Capture/Compare 5 value
      unsigned int : 13; // Reserved
      unsigned int GC5C1: 1; // Group Channel 5 and Channel 1
      unsigned int GC5C2: 1; // Group Channel 5 and Channel 2
      unsigned int GC5C3: 1; // Group Channel 5 and Channel 3
} CCR5;
// capture/compare register 6
 struct {
      unsigned int CCR6: 16; // Capture/Compare 6 value
      unsigned int : 16; // Reserved
} CCR6;
// option registers
 struct {
      unsigned int TIM8_ETR_ADC2_RMP: 2; // TIM8_ETR_ADC2 remapping capability
      unsigned int TIM8_ETR_ADC3_RMP: 2; // TIM8_ETR_ADC3 remapping capability
      unsigned int : 28; // Reserved
} OR;
} SVD_TIM8 __attribute__ ((packed));
asm(".equ SVD_TIM8, 0x40013400");
