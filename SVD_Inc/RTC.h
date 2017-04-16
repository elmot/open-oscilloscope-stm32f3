// Real-time clock
 extern struct {
// time register
 struct {
      unsigned int SU: 4; // Second units in BCD format
      unsigned int ST: 3; // Second tens in BCD format
      unsigned int : 1; // Reserved
      unsigned int MNU: 4; // Minute units in BCD format
      unsigned int MNT: 3; // Minute tens in BCD format
      unsigned int : 1; // Reserved
      unsigned int HU: 4; // Hour units in BCD format
      unsigned int HT: 2; // Hour tens in BCD format
      unsigned int PM: 1; // AM/PM notation
      unsigned int : 9; // Reserved
} TR;
// date register
 struct {
      unsigned int DU: 4; // Date units in BCD format
      unsigned int DT: 2; // Date tens in BCD format
      unsigned int : 2; // Reserved
      unsigned int MU: 4; // Month units in BCD format
      unsigned int MT: 1; // Month tens in BCD format
      unsigned int WDU: 3; // Week day units
      unsigned int YU: 4; // Year units in BCD format
      unsigned int YT: 4; // Year tens in BCD format
      unsigned int : 8; // Reserved
} DR;
// control register
 struct {
      unsigned int WCKSEL: 3; // Wakeup clock selection
      unsigned int TSEDGE: 1; // Time-stamp event active edge
      unsigned int REFCKON: 1; // Reference clock detection enable (50 or 60 Hz)
      unsigned int BYPSHAD: 1; // Bypass the shadow registers
      unsigned int FMT: 1; // Hour format
      unsigned int : 1; // Reserved
      unsigned int ALRAE: 1; // Alarm A enable
      unsigned int ALRBE: 1; // Alarm B enable
      unsigned int WUTE: 1; // Wakeup timer enable
      unsigned int TSE: 1; // Time stamp enable
      unsigned int ALRAIE: 1; // Alarm A interrupt enable
      unsigned int ALRBIE: 1; // Alarm B interrupt enable
      unsigned int WUTIE: 1; // Wakeup timer interrupt enable
      unsigned int TSIE: 1; // Time-stamp interrupt enable
      unsigned int ADD1H: 1; // Add 1 hour (summer time change)
      unsigned int SUB1H: 1; // Subtract 1 hour (winter time change)
      unsigned int BKP: 1; // Backup
      unsigned int COSEL: 1; // Calibration output selection
      unsigned int POL: 1; // Output polarity
      unsigned int OSEL: 2; // Output selection
      unsigned int COE: 1; // Calibration output enable
      unsigned int : 8; // Reserved
} CR;
// initialization and status register
 struct {
      unsigned int ALRAWF: 1; // Alarm A write flag
      unsigned int ALRBWF: 1; // Alarm B write flag
      unsigned int WUTWF: 1; // Wakeup timer write flag
      unsigned int SHPF: 1; // Shift operation pending
      unsigned int INITS: 1; // Initialization status flag
      unsigned int RSF: 1; // Registers synchronization flag
      unsigned int INITF: 1; // Initialization flag
      unsigned int INIT: 1; // Initialization mode
      unsigned int ALRAF: 1; // Alarm A flag
      unsigned int ALRBF: 1; // Alarm B flag
      unsigned int WUTF: 1; // Wakeup timer flag
      unsigned int TSF: 1; // Time-stamp flag
      unsigned int TSOVF: 1; // Time-stamp overflow flag
      unsigned int TAMP1F: 1; // Tamper detection flag
      unsigned int TAMP2F: 1; // RTC_TAMP2 detection flag
      unsigned int TAMP3F: 1; // RTC_TAMP3 detection flag
      unsigned int RECALPF: 1; // Recalibration pending Flag
      unsigned int : 15; // Reserved
} ISR;
// prescaler register
 struct {
      unsigned int PREDIV_S: 15; // Synchronous prescaler factor
      unsigned int : 1; // Reserved
      unsigned int PREDIV_A: 7; // Asynchronous prescaler factor
      unsigned int : 9; // Reserved
} PRER;
// wakeup timer register
 struct {
      unsigned int WUT: 16; // Wakeup auto-reload value bits
      unsigned int : 16; // Reserved
} WUTR;
      unsigned int : 32; // Reserved
// alarm A register
 struct {
      unsigned int SU: 4; // Second units in BCD format
      unsigned int ST: 3; // Second tens in BCD format
      unsigned int MSK1: 1; // Alarm A seconds mask
      unsigned int MNU: 4; // Minute units in BCD format
      unsigned int MNT: 3; // Minute tens in BCD format
      unsigned int MSK2: 1; // Alarm A minutes mask
      unsigned int HU: 4; // Hour units in BCD format
      unsigned int HT: 2; // Hour tens in BCD format
      unsigned int PM: 1; // AM/PM notation
      unsigned int MSK3: 1; // Alarm A hours mask
      unsigned int DU: 4; // Date units or day in BCD format
      unsigned int DT: 2; // Date tens in BCD format
      unsigned int WDSEL: 1; // Week day selection
      unsigned int MSK4: 1; // Alarm A date mask
} ALRMAR;
// alarm B register
 struct {
      unsigned int SU: 4; // Second units in BCD format
      unsigned int ST: 3; // Second tens in BCD format
      unsigned int MSK1: 1; // Alarm B seconds mask
      unsigned int MNU: 4; // Minute units in BCD format
      unsigned int MNT: 3; // Minute tens in BCD format
      unsigned int MSK2: 1; // Alarm B minutes mask
      unsigned int HU: 4; // Hour units in BCD format
      unsigned int HT: 2; // Hour tens in BCD format
      unsigned int PM: 1; // AM/PM notation
      unsigned int MSK3: 1; // Alarm B hours mask
      unsigned int DU: 4; // Date units or day in BCD format
      unsigned int DT: 2; // Date tens in BCD format
      unsigned int WDSEL: 1; // Week day selection
      unsigned int MSK4: 1; // Alarm B date mask
} ALRMBR;
// write protection register
 struct {
      unsigned int KEY: 8; // Write protection key
      unsigned int : 24; // Reserved
} WPR;
// sub second register
 struct {
      unsigned int SS: 16; // Sub second value
      unsigned int : 16; // Reserved
} SSR;
// shift control register
 struct {
      unsigned int SUBFS: 15; // Subtract a fraction of a second
      unsigned int : 16; // Reserved
      unsigned int ADD1S: 1; // Add one second
} SHIFTR;
// time stamp time register
 struct {
      unsigned int SU: 4; // Second units in BCD format
      unsigned int ST: 3; // Second tens in BCD format
      unsigned int : 1; // Reserved
      unsigned int MNU: 4; // Minute units in BCD format
      unsigned int MNT: 3; // Minute tens in BCD format
      unsigned int : 1; // Reserved
      unsigned int HU: 4; // Hour units in BCD format
      unsigned int HT: 2; // Hour tens in BCD format
      unsigned int PM: 1; // AM/PM notation
      unsigned int : 9; // Reserved
} TSTR;
// time stamp date register
 struct {
      unsigned int DU: 4; // Date units in BCD format
      unsigned int DT: 2; // Date tens in BCD format
      unsigned int : 2; // Reserved
      unsigned int MU: 4; // Month units in BCD format
      unsigned int MT: 1; // Month tens in BCD format
      unsigned int WDU: 3; // Week day units
      unsigned int : 16; // Reserved
} TSDR;
// timestamp sub second register
 struct {
      unsigned int SS: 16; // Sub second value
      unsigned int : 16; // Reserved
} TSSSR;
// calibration register
 struct {
      unsigned int CALM: 9; // Calibration minus
      unsigned int : 4; // Reserved
      unsigned int CALW16: 1; // Use a 16-second calibration cycle period
      unsigned int CALW8: 1; // Use an 8-second calibration cycle period
      unsigned int CALP: 1; // Increase frequency of RTC by 488.5 ppm
      unsigned int : 16; // Reserved
} CALR;
// tamper and alternate function configuration register
 struct {
      unsigned int TAMP1E: 1; // Tamper 1 detection enable
      unsigned int TAMP1TRG: 1; // Active level for tamper 1
      unsigned int TAMPIE: 1; // Tamper interrupt enable
      unsigned int TAMP2E: 1; // Tamper 2 detection enable
      unsigned int TAMP2TRG: 1; // Active level for tamper 2
      unsigned int TAMP3E: 1; // Tamper 3 detection enable
      unsigned int TAMP3TRG: 1; // Active level for tamper 3
      unsigned int TAMPTS: 1; // Activate timestamp on tamper detection event
      unsigned int TAMPFREQ: 3; // Tamper sampling frequency
      unsigned int TAMPFLT: 2; // Tamper filter count
      unsigned int TAMPPRCH: 2; // Tamper precharge duration
      unsigned int TAMPPUDIS: 1; // TAMPER pull-up disable
      unsigned int : 2; // Reserved
      unsigned int PC13VALUE: 1; // PC13 value
      unsigned int PC13MODE: 1; // PC13 mode
      unsigned int PC14VALUE: 1; // PC14 value
      unsigned int PC14MODE: 1; // PC 14 mode
      unsigned int PC15VALUE: 1; // PC15 value
      unsigned int PC15MODE: 1; // PC15 mode
      unsigned int : 8; // Reserved
} TAFCR;
// alarm A sub second register
 struct {
      unsigned int SS: 15; // Sub seconds value
      unsigned int : 9; // Reserved
      unsigned int MASKSS: 4; // Mask the most-significant bits starting at this bit
      unsigned int : 4; // Reserved
} ALRMASSR;
// alarm B sub second register
 struct {
      unsigned int SS: 15; // Sub seconds value
      unsigned int : 9; // Reserved
      unsigned int MASKSS: 4; // Mask the most-significant bits starting at this bit
      unsigned int : 4; // Reserved
} ALRMBSSR;
      unsigned int : 32; // Reserved
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP0R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP1R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP2R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP3R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP4R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP5R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP6R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP7R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP8R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP9R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP10R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP11R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP12R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP13R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP14R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP15R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP16R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP17R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP18R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP19R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP20R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP21R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP22R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP23R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP24R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP25R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP26R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP27R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP28R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP29R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP30R;
// backup register
 struct {
      unsigned int BKP: 32; // BKP
} BKP31R;
} SVD_RTC __attribute__ ((packed));
asm(".equ SVD_RTC, 0x40002800");
