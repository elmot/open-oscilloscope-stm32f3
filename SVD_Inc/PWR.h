// Power control
 extern struct {
// power control register
 struct {
      unsigned int LPDS: 1; // Low-power deep sleep
      unsigned int PDDS: 1; // Power down deepsleep
      unsigned int CWUF: 1; // Clear wakeup flag
      unsigned int CSBF: 1; // Clear standby flag
      unsigned int PVDE: 1; // Power voltage detector enable
      unsigned int PLS: 3; // PVD level selection
      unsigned int DBP: 1; // Disable backup domain write protection
      unsigned int : 23; // Reserved
} CR;
// power control/status register
 struct {
      unsigned int WUF: 1; // Wakeup flag
      unsigned int SBF: 1; // Standby flag
      unsigned int PVDO: 1; // PVD output
      unsigned int : 5; // Reserved
      unsigned int EWUP1: 1; // Enable WKUP1 pin
      unsigned int EWUP2: 1; // Enable WKUP2 pin
      unsigned int : 22; // Reserved
} CSR;
} SVD_PWR;
asm(".equ SVD_PWR, 0x40007000");
