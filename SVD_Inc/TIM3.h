// General purpose timer
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
      unsigned int : 3; // Reserved
      unsigned int CCDS: 1; // Capture/compare DMA selection
      unsigned int MMS: 3; // Master mode selection
      unsigned int TI1S: 1; // TI1 selection
      unsigned int : 24; // Reserved
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
      unsigned int SMS_3: 1; // Slave mode selection bit3
      unsigned int : 15; // Reserved
} SMCR;
// DMA/Interrupt enable register
 struct {
      unsigned int UIE: 1; // Update interrupt enable
      unsigned int CC1IE: 1; // Capture/Compare 1 interrupt enable
      unsigned int CC2IE: 1; // Capture/Compare 2 interrupt enable
      unsigned int CC3IE: 1; // Capture/Compare 3 interrupt enable
      unsigned int CC4IE: 1; // Capture/Compare 4 interrupt enable
      unsigned int : 1; // Reserved
      unsigned int TIE: 1; // Trigger interrupt enable
      unsigned int : 1; // Reserved
      unsigned int UDE: 1; // Update DMA request enable
      unsigned int CC1DE: 1; // Capture/Compare 1 DMA request enable
      unsigned int CC2DE: 1; // Capture/Compare 2 DMA request enable
      unsigned int CC3DE: 1; // Capture/Compare 3 DMA request enable
      unsigned int CC4DE: 1; // Capture/Compare 4 DMA request enable
      unsigned int : 1; // Reserved
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
      unsigned int : 1; // Reserved
      unsigned int TIF: 1; // Trigger interrupt flag
      unsigned int : 2; // Reserved
      unsigned int CC1OF: 1; // Capture/Compare 1 overcapture flag
      unsigned int CC2OF: 1; // Capture/compare 2 overcapture flag
      unsigned int CC3OF: 1; // Capture/Compare 3 overcapture flag
      unsigned int CC4OF: 1; // Capture/Compare 4 overcapture flag
      unsigned int : 19; // Reserved
} SR;
// event generation register
 struct {
      unsigned int UG: 1; // Update generation
      unsigned int CC1G: 1; // Capture/compare 1 generation
      unsigned int CC2G: 1; // Capture/compare 2 generation
      unsigned int CC3G: 1; // Capture/compare 3 generation
      unsigned int CC4G: 1; // Capture/compare 4 generation
      unsigned int : 1; // Reserved
      unsigned int TG: 1; // Trigger generation
      unsigned int : 25; // Reserved
} EGR;
  union {
// capture/compare mode register 1 (output mode)
 struct {
      unsigned int CC1S: 2; // Capture/Compare 1 selection
      unsigned int OC1FE: 1; // Output compare 1 fast enable
      unsigned int OC1PE: 1; // Output compare 1 preload enable
      unsigned int OC1M: 3; // Output compare 1 mode
      unsigned int OC1CE: 1; // Output compare 1 clear enable
      unsigned int CC2S: 2; // Capture/Compare 2 selection
      unsigned int OC2FE: 1; // Output compare 2 fast enable
      unsigned int OC2PE: 1; // Output compare 2 preload enable
      unsigned int OC2M: 3; // Output compare 2 mode
      unsigned int OC2CE: 1; // Output compare 2 clear enable
      unsigned int OC1M_3: 1; // Output compare 1 mode bit 3
      unsigned int : 7; // Reserved
      unsigned int OC2M_3: 1; // Output compare 2 mode bit 3
      unsigned int : 7; // Reserved
} CCMR1_Output;
// capture/compare mode register 1 (input mode)
 struct {
      unsigned int CC1S: 2; // Capture/Compare 1 selection
      unsigned int IC1PSC: 2; // Input capture 1 prescaler
      unsigned int IC1F: 4; // Input capture 1 filter
      unsigned int CC2S: 2; // Capture/compare 2 selection
      unsigned int IC2PSC: 2; // Input capture 2 prescaler
      unsigned int IC2F: 4; // Input capture 2 filter
      unsigned int : 16; // Reserved
} CCMR1_Input;
  } CCMR1_Output_CCMR1_Input;
  union {
// capture/compare mode register 2 (output mode)
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
      unsigned int O24CE: 1; // Output compare 4 clear enable
      unsigned int OC3M_3: 1; // Output compare 3 mode bit3
      unsigned int : 7; // Reserved
      unsigned int OC4M_3: 1; // Output compare 4 mode bit3
      unsigned int : 7; // Reserved
} CCMR2_Output;
// capture/compare mode register 2 (input mode)
 struct {
      unsigned int CC3S: 2; // Capture/Compare 3 selection
      unsigned int IC3PSC: 2; // Input capture 3 prescaler
      unsigned int IC3F: 4; // Input capture 3 filter
      unsigned int CC4S: 2; // Capture/Compare 4 selection
      unsigned int IC4PSC: 2; // Input capture 4 prescaler
      unsigned int IC4F: 4; // Input capture 4 filter
      unsigned int : 16; // Reserved
} CCMR2_Input;
  } CCMR2_Output_CCMR2_Input;
// capture/compare enable register
 struct {
      unsigned int CC1E: 1; // Capture/Compare 1 output enable
      unsigned int CC1P: 1; // Capture/Compare 1 output Polarity
      unsigned int : 1; // Reserved
      unsigned int CC1NP: 1; // Capture/Compare 1 output Polarity
      unsigned int CC2E: 1; // Capture/Compare 2 output enable
      unsigned int CC2P: 1; // Capture/Compare 2 output Polarity
      unsigned int : 1; // Reserved
      unsigned int CC2NP: 1; // Capture/Compare 2 output Polarity
      unsigned int CC3E: 1; // Capture/Compare 3 output enable
      unsigned int CC3P: 1; // Capture/Compare 3 output Polarity
      unsigned int : 1; // Reserved
      unsigned int CC3NP: 1; // Capture/Compare 3 output Polarity
      unsigned int CC4E: 1; // Capture/Compare 4 output enable
      unsigned int CC4P: 1; // Capture/Compare 3 output Polarity
      unsigned int : 1; // Reserved
      unsigned int CC4NP: 1; // Capture/Compare 3 output Polarity
      unsigned int : 16; // Reserved
} CCER;
// counter
 struct {
      unsigned int CNTL: 16; // Low counter value
      unsigned int CNTH: 15; // High counter value
      unsigned int CNT_or_UIFCPY: 1; // if IUFREMAP=0 than CNT with read write access else UIFCPY with read only
                                access
                            
} CNT;
// prescaler
 struct {
      unsigned int PSC: 16; // Prescaler value
      unsigned int : 16; // Reserved
} PSC;
// auto-reload register
 struct {
      unsigned int ARRL: 16; // Low Auto-reload value
      unsigned int ARRH: 16; // High Auto-reload value
} ARR;
      unsigned int : 32; // Reserved
// capture/compare register 1
 struct {
      unsigned int CCR1L: 16; // Low Capture/Compare 1 value
      unsigned int CCR1H: 16; // High Capture/Compare 1 value (on TIM2)
} CCR1;
// capture/compare register 2
 struct {
      unsigned int CCR2L: 16; // Low Capture/Compare 2 value
      unsigned int CCR2H: 16; // High Capture/Compare 2 value (on TIM2)
} CCR2;
// capture/compare register 3
 struct {
      unsigned int CCR3L: 16; // Low Capture/Compare value
      unsigned int CCR3H: 16; // High Capture/Compare value (on TIM2)
} CCR3;
// capture/compare register 4
 struct {
      unsigned int CCR4L: 16; // Low Capture/Compare value
      unsigned int CCR4H: 16; // High Capture/Compare value (on TIM2)
} CCR4;
      unsigned int : 32; // Reserved
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
} SVD_TIM3;
asm(".equ SVD_TIM3, 0x40000400");
