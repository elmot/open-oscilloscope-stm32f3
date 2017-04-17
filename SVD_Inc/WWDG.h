// Window watchdog
 extern struct {
// Control register
 struct {
      unsigned int T: 7; // 7-bit counter
      unsigned int WDGA: 1; // Activation bit
      unsigned int : 24; // Reserved
} CR;
// Configuration register
 struct {
      unsigned int W: 7; // 7-bit window value
      unsigned int WDGTB: 2; // Timer base
      unsigned int EWI: 1; // Early wakeup interrupt
      unsigned int : 22; // Reserved
} CFR;
// Status register
 struct {
      unsigned int EWIF: 1; // Early wakeup interrupt flag
      unsigned int : 31; // Reserved
} SR;
} SVD_WWDG;
asm(".equ SVD_WWDG, 0x40002c00");
