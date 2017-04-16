// Basic timers
 extern struct {
// control register 1
 struct {
      unsigned int CEN: 1; // Counter enable
      unsigned int UDIS: 1; // Update disable
      unsigned int URS: 1; // Update request source
      unsigned int OPM: 1; // One-pulse mode
      unsigned int : 3; // Reserved
      unsigned int ARPE: 1; // Auto-reload preload enable
      unsigned int : 3; // Reserved
      unsigned int UIFREMAP: 1; // UIF status bit remapping
      unsigned int : 20; // Reserved
} CR1;
// control register 2
 struct {
      unsigned int : 4; // Reserved
      unsigned int MMS: 3; // Master mode selection
      unsigned int : 25; // Reserved
} CR2;
      unsigned int : 32; // Reserved
// DMA/Interrupt enable register
 struct {
      unsigned int UIE: 1; // Update interrupt enable
      unsigned int : 7; // Reserved
      unsigned int UDE: 1; // Update DMA request enable
      unsigned int : 23; // Reserved
} DIER;
// status register
 struct {
      unsigned int UIF: 1; // Update interrupt flag
      unsigned int : 31; // Reserved
} SR;
// event generation register
 struct {
      unsigned int UG: 1; // Update generation
      unsigned int : 31; // Reserved
} EGR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// counter
 struct {
      unsigned int CNT: 16; // Low counter value
      unsigned int : 15; // Reserved
      unsigned int UIFCPY: 1; // UIF Copy
} CNT;
// prescaler
 struct {
      unsigned int PSC: 16; // Prescaler value
      unsigned int : 16; // Reserved
} PSC;
// auto-reload register
 struct {
      unsigned int ARR: 16; // Low Auto-reload value
      unsigned int : 16; // Reserved
} ARR;
} SVD_TIM6 __attribute__ ((packed));
asm(".equ SVD_TIM6, 0x40001000");
