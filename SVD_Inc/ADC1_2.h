// Analog-to-Digital Converter
 extern struct {
// ADC Common status register
 struct {
      unsigned int ADDRDY_MST: 1; // ADDRDY_MST
      unsigned int EOSMP_MST: 1; // EOSMP_MST
      unsigned int EOC_MST: 1; // EOC_MST
      unsigned int EOS_MST: 1; // EOS_MST
      unsigned int OVR_MST: 1; // OVR_MST
      unsigned int JEOC_MST: 1; // JEOC_MST
      unsigned int JEOS_MST: 1; // JEOS_MST
      unsigned int AWD1_MST: 1; // AWD1_MST
      unsigned int AWD2_MST: 1; // AWD2_MST
      unsigned int AWD3_MST: 1; // AWD3_MST
      unsigned int JQOVF_MST: 1; // JQOVF_MST
      unsigned int : 5; // Reserved
      unsigned int ADRDY_SLV: 1; // ADRDY_SLV
      unsigned int EOSMP_SLV: 1; // EOSMP_SLV
      unsigned int EOC_SLV: 1; // End of regular conversion of the slave ADC
      unsigned int EOS_SLV: 1; // End of regular sequence flag of the slave ADC
      unsigned int OVR_SLV: 1; // Overrun flag of the slave ADC
      unsigned int JEOC_SLV: 1; // End of injected conversion flag of the slave ADC
      unsigned int JEOS_SLV: 1; // End of injected sequence flag of the slave ADC
      unsigned int AWD1_SLV: 1; // Analog watchdog 1 flag of the slave ADC
      unsigned int AWD2_SLV: 1; // Analog watchdog 2 flag of the slave ADC
      unsigned int AWD3_SLV: 1; // Analog watchdog 3 flag of the slave ADC
      unsigned int JQOVF_SLV: 1; // Injected Context Queue Overflow flag of the slave ADC
      unsigned int : 5; // Reserved
} CSR;
      unsigned int : 32; // Reserved
// ADC common control register
 struct {
      unsigned int MULT: 5; // Multi ADC mode selection
      unsigned int : 3; // Reserved
      unsigned int DELAY: 4; // Delay between 2 sampling phases
      unsigned int : 1; // Reserved
      unsigned int DMACFG: 1; // DMA configuration (for multi-ADC mode)
      unsigned int MDMA: 2; // Direct memory access mode for multi ADC mode
      unsigned int CKMODE: 2; // ADC clock mode
      unsigned int : 4; // Reserved
      unsigned int VREFEN: 1; // VREFINT enable
      unsigned int TSEN: 1; // Temperature sensor enable
      unsigned int VBATEN: 1; // VBAT enable
      unsigned int : 7; // Reserved
} CCR;
// ADC common regular data register for dual and triple modes
 struct {
      unsigned int RDATA_MST: 16; // Regular data of the master ADC
      unsigned int RDATA_SLV: 16; // Regular data of the slave ADC
} CDR;
} SVD_ADC1_2 __attribute__ ((packed));
asm(".equ SVD_ADC1_2, 0x50000300");
