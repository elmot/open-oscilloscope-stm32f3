// ADC1_2
 extern struct {
// CSR
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
      unsigned int EOC_SLV: 1; // EOC_SLV
      unsigned int EOS_SLV: 1; // EOS_SLV
      unsigned int OVR_SLV: 1; // OVR_SLV
      unsigned int JEOC_SLV: 1; // JEOC_SLV
      unsigned int JEOS_SLV: 1; // JEOS_SLV
      unsigned int AWD1_SLV: 1; // AWD1_SLV
      unsigned int AWD2_SLV: 1; // AWD2_SLV
      unsigned int AWD3_SLV: 1; // AWD3_SLV
      unsigned int JQOVF_SLV: 1; // JQOVF_SLV
      unsigned int : 5; // Reserved
} CSR;
      unsigned int : 32; // Reserved
// CCR
 struct {
      unsigned int MULT: 5; // MULT
      unsigned int : 3; // Reserved
      unsigned int DELAY: 4; // DELAY
      unsigned int : 1; // Reserved
      unsigned int DMACFG: 1; // DMACFG
      unsigned int MDMA: 2; // MDMA
      unsigned int CKMODE: 2; // CKMODE
      unsigned int : 4; // Reserved
      unsigned int VREFEN: 1; // VREFEN
      unsigned int TSEN: 1; // TSEN
      unsigned int VBATEN: 1; // VBATEN
      unsigned int : 7; // Reserved
} CCR;
// CDR
 struct {
      unsigned int RDATA_MST: 16; // RDATA_MST
      unsigned int RDATA_SLV: 16; // RDATA_SLV
} CDR;
} SVD_ADC3_4 __attribute__ ((packed));
asm(".equ SVD_ADC3_4, 0x50000700");
