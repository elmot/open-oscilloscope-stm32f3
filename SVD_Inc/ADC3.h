// Analog-to-Digital Converter
 extern struct {
// interrupt and status register
 struct {
      unsigned int ADRDY: 1; // ADRDY
      unsigned int EOSMP: 1; // EOSMP
      unsigned int EOC: 1; // EOC
      unsigned int EOS: 1; // EOS
      unsigned int OVR: 1; // OVR
      unsigned int JEOC: 1; // JEOC
      unsigned int JEOS: 1; // JEOS
      unsigned int AWD1: 1; // AWD1
      unsigned int AWD2: 1; // AWD2
      unsigned int AWD3: 1; // AWD3
      unsigned int JQOVF: 1; // JQOVF
      unsigned int : 21; // Reserved
} ISR;
// interrupt enable register
 struct {
      unsigned int ADRDYIE: 1; // ADRDYIE
      unsigned int EOSMPIE: 1; // EOSMPIE
      unsigned int EOCIE: 1; // EOCIE
      unsigned int EOSIE: 1; // EOSIE
      unsigned int OVRIE: 1; // OVRIE
      unsigned int JEOCIE: 1; // JEOCIE
      unsigned int JEOSIE: 1; // JEOSIE
      unsigned int AWD1IE: 1; // AWD1IE
      unsigned int AWD2IE: 1; // AWD2IE
      unsigned int AWD3IE: 1; // AWD3IE
      unsigned int JQOVFIE: 1; // JQOVFIE
      unsigned int : 21; // Reserved
} IER;
// control register
 struct {
      unsigned int ADEN: 1; // ADEN
      unsigned int ADDIS: 1; // ADDIS
      unsigned int ADSTART: 1; // ADSTART
      unsigned int JADSTART: 1; // JADSTART
      unsigned int ADSTP: 1; // ADSTP
      unsigned int JADSTP: 1; // JADSTP
      unsigned int : 22; // Reserved
      unsigned int ADVREGEN: 1; // ADVREGEN
      unsigned int DEEPPWD: 1; // DEEPPWD
      unsigned int ADCALDIF: 1; // ADCALDIF
      unsigned int ADCAL: 1; // ADCAL
} CR;
// configuration register
 struct {
      unsigned int DMAEN: 1; // DMAEN
      unsigned int DMACFG: 1; // DMACFG
      unsigned int : 1; // Reserved
      unsigned int RES: 2; // RES
      unsigned int ALIGN: 1; // ALIGN
      unsigned int EXTSEL: 4; // EXTSEL
      unsigned int EXTEN: 2; // EXTEN
      unsigned int OVRMOD: 1; // OVRMOD
      unsigned int CONT: 1; // CONT
      unsigned int AUTDLY: 1; // AUTDLY
      unsigned int AUTOFF: 1; // AUTOFF
      unsigned int DISCEN: 1; // DISCEN
      unsigned int DISCNUM: 3; // DISCNUM
      unsigned int JDISCEN: 1; // JDISCEN
      unsigned int JQM: 1; // JQM
      unsigned int AWD1SGL: 1; // AWD1SGL
      unsigned int AWD1EN: 1; // AWD1EN
      unsigned int JAWD1EN: 1; // JAWD1EN
      unsigned int JAUTO: 1; // JAUTO
      unsigned int AWDCH1CH: 5; // AWDCH1CH
      unsigned int : 1; // Reserved
} CFGR;
      unsigned int : 32; // Reserved
// sample time register 1
 struct {
      unsigned int : 3; // Reserved
      unsigned int SMP1: 3; // SMP1
      unsigned int SMP2: 3; // SMP2
      unsigned int SMP3: 3; // SMP3
      unsigned int SMP4: 3; // SMP4
      unsigned int SMP5: 3; // SMP5
      unsigned int SMP6: 3; // SMP6
      unsigned int SMP7: 3; // SMP7
      unsigned int SMP8: 3; // SMP8
      unsigned int SMP9: 3; // SMP9
      unsigned int : 2; // Reserved
} SMPR1;
// sample time register 2
 struct {
      unsigned int SMP10: 3; // SMP10
      unsigned int SMP11: 3; // SMP11
      unsigned int SMP12: 3; // SMP12
      unsigned int SMP13: 3; // SMP13
      unsigned int SMP14: 3; // SMP14
      unsigned int SMP15: 3; // SMP15
      unsigned int SMP16: 3; // SMP16
      unsigned int SMP17: 3; // SMP17
      unsigned int SMP18: 3; // SMP18
      unsigned int : 5; // Reserved
} SMPR2;
      unsigned int : 32; // Reserved
// watchdog threshold register 1
 struct {
      unsigned int LT1: 12; // LT1
      unsigned int : 4; // Reserved
      unsigned int HT1: 12; // HT1
      unsigned int : 4; // Reserved
} TR1;
// watchdog threshold register
 struct {
      unsigned int LT2: 8; // LT2
      unsigned int : 8; // Reserved
      unsigned int HT2: 8; // HT2
      unsigned int : 8; // Reserved
} TR2;
// watchdog threshold register 3
 struct {
      unsigned int LT3: 8; // LT3
      unsigned int : 8; // Reserved
      unsigned int HT3: 8; // HT3
      unsigned int : 8; // Reserved
} TR3;
      unsigned int : 32; // Reserved
// regular sequence register 1
 struct {
      unsigned int L3: 4; // L3
      unsigned int : 2; // Reserved
      unsigned int SQ1: 5; // SQ1
      unsigned int : 1; // Reserved
      unsigned int SQ2: 5; // SQ2
      unsigned int : 1; // Reserved
      unsigned int SQ3: 5; // SQ3
      unsigned int : 1; // Reserved
      unsigned int SQ4: 5; // SQ4
      unsigned int : 3; // Reserved
} SQR1;
// regular sequence register 2
 struct {
      unsigned int SQ5: 5; // SQ5
      unsigned int : 1; // Reserved
      unsigned int SQ6: 5; // SQ6
      unsigned int : 1; // Reserved
      unsigned int SQ7: 5; // SQ7
      unsigned int : 1; // Reserved
      unsigned int SQ8: 5; // SQ8
      unsigned int : 1; // Reserved
      unsigned int SQ9: 5; // SQ9
      unsigned int : 3; // Reserved
} SQR2;
// regular sequence register 3
 struct {
      unsigned int SQ10: 5; // SQ10
      unsigned int : 1; // Reserved
      unsigned int SQ11: 5; // SQ11
      unsigned int : 1; // Reserved
      unsigned int SQ12: 5; // SQ12
      unsigned int : 1; // Reserved
      unsigned int SQ13: 5; // SQ13
      unsigned int : 1; // Reserved
      unsigned int SQ14: 5; // SQ14
      unsigned int : 3; // Reserved
} SQR3;
// regular sequence register 4
 struct {
      unsigned int SQ15: 5; // SQ15
      unsigned int : 1; // Reserved
      unsigned int SQ16: 5; // SQ16
      unsigned int : 21; // Reserved
} SQR4;
// regular Data Register
 struct {
      unsigned int regularDATA: 16; // regularDATA
      unsigned int : 16; // Reserved
} DR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// injected sequence register
 struct {
      unsigned int JL: 2; // JL
      unsigned int JEXTSEL: 4; // JEXTSEL
      unsigned int JEXTEN: 2; // JEXTEN
      unsigned int JSQ1: 5; // JSQ1
      unsigned int : 1; // Reserved
      unsigned int JSQ2: 5; // JSQ2
      unsigned int : 1; // Reserved
      unsigned int JSQ3: 5; // JSQ3
      unsigned int : 1; // Reserved
      unsigned int JSQ4: 5; // JSQ4
      unsigned int : 1; // Reserved
} JSQR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// offset register 1
 struct {
      unsigned int OFFSET1: 12; // OFFSET1
      unsigned int : 14; // Reserved
      unsigned int OFFSET1_CH: 5; // OFFSET1_CH
      unsigned int OFFSET1_EN: 1; // OFFSET1_EN
} OFR1;
// offset register 2
 struct {
      unsigned int OFFSET2: 12; // OFFSET2
      unsigned int : 14; // Reserved
      unsigned int OFFSET2_CH: 5; // OFFSET2_CH
      unsigned int OFFSET2_EN: 1; // OFFSET2_EN
} OFR2;
// offset register 3
 struct {
      unsigned int OFFSET3: 12; // OFFSET3
      unsigned int : 14; // Reserved
      unsigned int OFFSET3_CH: 5; // OFFSET3_CH
      unsigned int OFFSET3_EN: 1; // OFFSET3_EN
} OFR3;
// offset register 4
 struct {
      unsigned int OFFSET4: 12; // OFFSET4
      unsigned int : 14; // Reserved
      unsigned int OFFSET4_CH: 5; // OFFSET4_CH
      unsigned int OFFSET4_EN: 1; // OFFSET4_EN
} OFR4;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// injected data register 1
 struct {
      unsigned int JDATA1: 16; // JDATA1
      unsigned int : 16; // Reserved
} JDR1;
// injected data register 2
 struct {
      unsigned int JDATA2: 16; // JDATA2
      unsigned int : 16; // Reserved
} JDR2;
// injected data register 3
 struct {
      unsigned int JDATA3: 16; // JDATA3
      unsigned int : 16; // Reserved
} JDR3;
// injected data register 4
 struct {
      unsigned int JDATA4: 16; // JDATA4
      unsigned int : 16; // Reserved
} JDR4;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// Analog Watchdog 2 Configuration Register
 struct {
      unsigned int : 1; // Reserved
      unsigned int AWD2CH: 18; // AWD2CH
      unsigned int : 13; // Reserved
} AWD2CR;
// Analog Watchdog 3 Configuration Register
 struct {
      unsigned int : 1; // Reserved
      unsigned int AWD3CH: 18; // AWD3CH
      unsigned int : 13; // Reserved
} AWD3CR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// Differential Mode Selection Register 2
 struct {
      unsigned int : 1; // Reserved
      unsigned int DIFSEL_1_15: 15; // Differential mode for channels 15 to 1
      unsigned int DIFSEL_16_18: 3; // Differential mode for channels 18 to 16
      unsigned int : 13; // Reserved
} DIFSEL;
// Calibration Factors
 struct {
      unsigned int CALFACT_S: 7; // CALFACT_S
      unsigned int : 9; // Reserved
      unsigned int CALFACT_D: 7; // CALFACT_D
      unsigned int : 9; // Reserved
} CALFACT;
} SVD_ADC3;
asm(".equ SVD_ADC3, 0x50000400");
