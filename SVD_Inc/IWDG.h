// Independent watchdog
 extern struct {
// Key register
 struct {
      unsigned int KEY: 16; // Key value
      unsigned int : 16; // Reserved
} KR;
// Prescaler register
 struct {
      unsigned int PR: 3; // Prescaler divider
      unsigned int : 29; // Reserved
} PR;
// Reload register
 struct {
      unsigned int RL: 12; // Watchdog counter reload value
      unsigned int : 20; // Reserved
} RLR;
// Status register
 struct {
      unsigned int PVU: 1; // Watchdog prescaler value update
      unsigned int RVU: 1; // Watchdog counter reload value update
      unsigned int WVU: 1; // Watchdog counter window value update
      unsigned int : 29; // Reserved
} SR;
// Window register
 struct {
      unsigned int WIN: 12; // Watchdog counter window value
      unsigned int : 20; // Reserved
} WINR;
} SVD_IWDG __attribute__ ((packed));
asm(".equ SVD_IWDG, 0x40003000");
