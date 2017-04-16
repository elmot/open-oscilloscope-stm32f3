// Flash
 extern struct {
// Flash access control register
 struct {
      unsigned int LATENCY: 3; // LATENCY
      unsigned int : 1; // Reserved
      unsigned int PRFTBE: 1; // PRFTBE
      unsigned int PRFTBS: 1; // PRFTBS
      unsigned int : 26; // Reserved
} ACR;
// Flash key register
 struct {
      unsigned int FKEYR: 32; // Flash Key
} KEYR;
// Flash option key register
 struct {
      unsigned int OPTKEYR: 32; // Option byte key
} OPTKEYR;
// Flash status register
 struct {
      unsigned int BSY: 1; // Busy
      unsigned int : 1; // Reserved
      unsigned int PGERR: 1; // Programming error
      unsigned int : 1; // Reserved
      unsigned int WRPRT: 1; // Write protection error
      unsigned int EOP: 1; // End of operation
      unsigned int : 26; // Reserved
} SR;
// Flash control register
 struct {
      unsigned int PG: 1; // Programming
      unsigned int PER: 1; // Page erase
      unsigned int MER: 1; // Mass erase
      unsigned int : 1; // Reserved
      unsigned int OPTPG: 1; // Option byte programming
      unsigned int OPTER: 1; // Option byte erase
      unsigned int STRT: 1; // Start
      unsigned int LOCK: 1; // Lock
      unsigned int : 1; // Reserved
      unsigned int OPTWRE: 1; // Option bytes write enable
      unsigned int ERRIE: 1; // Error interrupt enable
      unsigned int : 1; // Reserved
      unsigned int EOPIE: 1; // End of operation interrupt enable
      unsigned int FORCE_OPTLOAD: 1; // Force option byte loading
      unsigned int : 18; // Reserved
} CR;
// Flash address register
 struct {
      unsigned int FAR: 32; // Flash address
} AR;
      unsigned int : 32; // Reserved
// Option byte register
 struct {
      unsigned int OPTERR: 1; // Option byte error
      unsigned int LEVEL1_PROT: 1; // Level 1 protection status
      unsigned int LEVEL2_PROT: 1; // Level 2 protection status
      unsigned int : 5; // Reserved
      unsigned int WDG_SW: 1; // WDG_SW
      unsigned int nRST_STOP: 1; // nRST_STOP
      unsigned int nRST_STDBY: 1; // nRST_STDBY
      unsigned int : 1; // Reserved
      unsigned int BOOT1: 1; // BOOT1
      unsigned int VDDA_MONITOR: 1; // VDDA_MONITOR
      unsigned int SRAM_PARITY_CHECK: 1; // SRAM_PARITY_CHECK
      unsigned int : 1; // Reserved
      unsigned int Data0: 8; // Data0
      unsigned int Data1: 8; // Data1
} OBR;
// Write protection register
 struct {
      unsigned int WRP: 32; // Write protect
} WRPR;
} SVD_Flash __attribute__ ((packed));
asm(".equ SVD_Flash, 0x40022000");
