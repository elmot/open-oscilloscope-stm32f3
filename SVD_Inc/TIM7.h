// TIM6
 extern struct {
// CR1
 struct {
      unsigned int CEN: 1; // CEN
      unsigned int UDIS: 1; // UDIS
      unsigned int URS: 1; // URS
      unsigned int OPM: 1; // OPM
      unsigned int : 3; // Reserved
      unsigned int ARPE: 1; // ARPE
      unsigned int : 3; // Reserved
      unsigned int UIFREMAP: 1; // UIFREMAP
      unsigned int : 20; // Reserved
} CR1;
// CR2
 struct {
      unsigned int : 4; // Reserved
      unsigned int MMS: 3; // MMS
      unsigned int : 25; // Reserved
} CR2;
      unsigned int : 32; // Reserved
// DIER
 struct {
      unsigned int UIE: 1; // UIE
      unsigned int : 7; // Reserved
      unsigned int UDE: 1; // UDE
      unsigned int : 23; // Reserved
} DIER;
// SR
 struct {
      unsigned int UIF: 1; // UIF
      unsigned int : 31; // Reserved
} SR;
// EGR
 struct {
      unsigned int UG: 1; // UG
      unsigned int : 31; // Reserved
} EGR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// CNT
 struct {
      unsigned int CNT: 16; // CNT
      unsigned int : 15; // Reserved
      unsigned int UIFCPY: 1; // UIFCPY
} CNT;
// PSC
 struct {
      unsigned int PSC: 16; // PSC
      unsigned int : 16; // Reserved
} PSC;
// ARR
 struct {
      unsigned int ARR: 16; // ARR
      unsigned int : 16; // Reserved
} ARR;
} SVD_TIM7 __attribute__ ((packed));
asm(".equ SVD_TIM7, 0x40001400");
