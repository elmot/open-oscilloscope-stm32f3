// TIM1
 extern struct {
// CR1
 struct {
      unsigned int CEN: 1; // CEN
      unsigned int UDIS: 1; // UDIS
      unsigned int URS: 1; // URS
      unsigned int OPM: 1; // OPM
      unsigned int DIR: 1; // DIR
      unsigned int CMS: 2; // CMS
      unsigned int ARPE: 1; // ARPE
      unsigned int CKD: 2; // CKD
      unsigned int : 1; // Reserved
      unsigned int UIFREMAP: 1; // UIFREMAP
      unsigned int : 20; // Reserved
} CR1;
// CR2
 struct {
      unsigned int CCPC: 1; // CCPC
      unsigned int : 1; // Reserved
      unsigned int CCUS: 1; // CCUS
      unsigned int CCDS: 1; // CCDS
      unsigned int MMS: 3; // MMS
      unsigned int TI1S: 1; // TI1S
      unsigned int OIS1: 1; // OIS1
      unsigned int OIS1N: 1; // OIS1N
      unsigned int OIS2: 1; // OIS2
      unsigned int OIS2N: 1; // OIS2N
      unsigned int OIS3: 1; // OIS3
      unsigned int OIS3N: 1; // OIS3N
      unsigned int OIS4: 1; // OIS4
      unsigned int : 1; // Reserved
      unsigned int OIS5: 1; // OIS5
      unsigned int : 1; // Reserved
      unsigned int OIS6: 1; // OIS6
      unsigned int : 1; // Reserved
      unsigned int MMS2: 4; // MMS2
      unsigned int : 8; // Reserved
} CR2;
// SMCR
 struct {
      unsigned int SMS: 3; // SMS
      unsigned int OCCS: 1; // OCCS
      unsigned int TS: 3; // TS
      unsigned int MSM: 1; // MSM
      unsigned int ETF: 4; // ETF
      unsigned int ETPS: 2; // ETPS
      unsigned int ECE: 1; // ECE
      unsigned int ETP: 1; // ETP
      unsigned int SMS3: 1; // SMS3
      unsigned int : 15; // Reserved
} SMCR;
// DIER
 struct {
      unsigned int UIE: 1; // UIE
      unsigned int CC1IE: 1; // CC1IE
      unsigned int CC2IE: 1; // CC2IE
      unsigned int CC3IE: 1; // CC3IE
      unsigned int CC4IE: 1; // CC4IE
      unsigned int COMIE: 1; // COMIE
      unsigned int TIE: 1; // TIE
      unsigned int BIE: 1; // BIE
      unsigned int UDE: 1; // UDE
      unsigned int CC1DE: 1; // CC1DE
      unsigned int CC2DE: 1; // CC2DE
      unsigned int CC3DE: 1; // CC3DE
      unsigned int CC4DE: 1; // CC4DE
      unsigned int COMDE: 1; // COMDE
      unsigned int TDE: 1; // TDE
      unsigned int : 17; // Reserved
} DIER;
// SR
 struct {
      unsigned int UIF: 1; // UIF
      unsigned int CC1IF: 1; // CC1IF
      unsigned int CC2IF: 1; // CC2IF
      unsigned int CC3IF: 1; // CC3IF
      unsigned int CC4IF: 1; // CC4IF
      unsigned int COMIF: 1; // COMIF
      unsigned int TIF: 1; // TIF
      unsigned int BIF: 1; // BIF
      unsigned int B2IF: 1; // B2IF
      unsigned int CC1OF: 1; // CC1OF
      unsigned int CC2OF: 1; // CC2OF
      unsigned int CC3OF: 1; // CC3OF
      unsigned int CC4OF: 1; // CC4OF
      unsigned int : 3; // Reserved
      unsigned int C5IF: 1; // C5IF
      unsigned int C6IF: 1; // C6IF
      unsigned int : 14; // Reserved
} SR;
// EGR
 struct {
      unsigned int UG: 1; // UG
      unsigned int CC1G: 1; // CC1G
      unsigned int CC2G: 1; // CC2G
      unsigned int CC3G: 1; // CC3G
      unsigned int CC4G: 1; // CC4G
      unsigned int COMG: 1; // COMG
      unsigned int TG: 1; // TG
      unsigned int BG: 1; // BG
      unsigned int B2G: 1; // B2G
      unsigned int : 23; // Reserved
} EGR;
// CCMR1_Output
 struct {
      unsigned int CC1S: 2; // CC1S
      unsigned int OC1FE: 1; // OC1FE
      unsigned int OC1PE: 1; // OC1PE
      unsigned int OC1M: 3; // OC1M
      unsigned int OC1CE: 1; // OC1CE
      unsigned int CC2S: 2; // CC2S
      unsigned int OC2FE: 1; // OC2FE
      unsigned int OC2PE: 1; // OC2PE
      unsigned int OC2M: 3; // OC2M
      unsigned int OC2CE: 1; // OC2CE
      unsigned int OC1M_3: 1; // OC1M_3
      unsigned int : 7; // Reserved
      unsigned int OC2M_3: 1; // OC2M_3
      unsigned int : 7; // Reserved
} CCMR1_Output;
// CCMR2_Output
 struct {
      unsigned int CC3S: 2; // CC3S
      unsigned int OC3FE: 1; // OC3FE
      unsigned int OC3PE: 1; // OC3PE
      unsigned int OC3M: 3; // OC3M
      unsigned int OC3CE: 1; // OC3CE
      unsigned int CC4S: 2; // CC4S
      unsigned int OC4FE: 1; // OC4FE
      unsigned int OC4PE: 1; // OC4PE
      unsigned int OC4M: 3; // OC4M
      unsigned int OC4CE: 1; // OC4CE
      unsigned int OC3M_3: 1; // OC3M_3
      unsigned int : 7; // Reserved
      unsigned int OC4M_3: 1; // OC4M_3
      unsigned int : 7; // Reserved
} CCMR2_Output;
// CCER
 struct {
      unsigned int CC1E: 1; // CC1E
      unsigned int CC1P: 1; // CC1P
      unsigned int CC1NE: 1; // CC1NE
      unsigned int CC1NP: 1; // CC1NP
      unsigned int CC2E: 1; // CC2E
      unsigned int CC2P: 1; // CC2P
      unsigned int CC2NE: 1; // CC2NE
      unsigned int CC2NP: 1; // CC2NP
      unsigned int CC3E: 1; // CC3E
      unsigned int CC3P: 1; // CC3P
      unsigned int CC3NE: 1; // CC3NE
      unsigned int CC3NP: 1; // CC3NP
      unsigned int CC4E: 1; // CC4E
      unsigned int CC4P: 1; // CC4P
      unsigned int : 1; // Reserved
      unsigned int CC4NP: 1; // CC4NP
      unsigned int CC5E: 1; // CC5E
      unsigned int CC5P: 1; // CC5P
      unsigned int : 2; // Reserved
      unsigned int CC6E: 1; // CC6E
      unsigned int CC6P: 1; // CC6P
      unsigned int : 10; // Reserved
} CCER;
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
// RCR
 struct {
      unsigned int REP: 16; // REP
      unsigned int : 16; // Reserved
} RCR;
// CCR1
 struct {
      unsigned int CCR1: 16; // CCR1
      unsigned int : 16; // Reserved
} CCR1;
// CCR2
 struct {
      unsigned int CCR2: 16; // CCR2
      unsigned int : 16; // Reserved
} CCR2;
// CCR3
 struct {
      unsigned int CCR3: 16; // CCR3
      unsigned int : 16; // Reserved
} CCR3;
// CCR4
 struct {
      unsigned int CCR4: 16; // CCR4
      unsigned int : 16; // Reserved
} CCR4;
// BDTR
 struct {
      unsigned int DTG: 8; // DTG
      unsigned int LOCK: 2; // LOCK
      unsigned int OSSI: 1; // OSSI
      unsigned int OSSR: 1; // OSSR
      unsigned int BKE: 1; // BKE
      unsigned int BKP: 1; // BKP
      unsigned int AOE: 1; // AOE
      unsigned int MOE: 1; // MOE
      unsigned int BKF: 4; // BKF
      unsigned int BK2F: 4; // BK2F
      unsigned int BK2E: 1; // BK2E
      unsigned int BK2P: 1; // BK2P
      unsigned int : 6; // Reserved
} BDTR;
// DCR
 struct {
      unsigned int DBA: 5; // DBA
      unsigned int : 3; // Reserved
      unsigned int DBL: 5; // DBL
      unsigned int : 19; // Reserved
} DCR;
// DMAR
 struct {
      unsigned int DMAB: 16; // DMAB
      unsigned int : 16; // Reserved
} DMAR;
      unsigned int : 32; // Reserved
// CCMR3_Output
 struct {
      unsigned int : 2; // Reserved
      unsigned int OC5FE: 1; // OC5FE
      unsigned int OC5PE: 1; // OC5PE
      unsigned int OC5M: 3; // OC5M
      unsigned int OC5CE: 1; // OC5CE
      unsigned int : 2; // Reserved
      unsigned int OC6FE: 1; // OC6FE
      unsigned int OC6PE: 1; // OC6PE
      unsigned int OC6M: 3; // OC6M
      unsigned int OC6CE: 1; // OC6CE
      unsigned int OC5M_3: 1; // OC5M_3
      unsigned int : 7; // Reserved
      unsigned int OC6M_3: 1; // OC6M_3
      unsigned int : 7; // Reserved
} CCMR3_Output;
// CCR5
 struct {
      unsigned int CCR5: 16; // CCR5
      unsigned int : 13; // Reserved
      unsigned int GC5C1: 1; // GC5C1
      unsigned int GC5C2: 1; // GC5C2
      unsigned int GC5C3: 1; // GC5C3
} CCR5;
// CCR6
 struct {
      unsigned int CCR6: 16; // CCR6
      unsigned int : 16; // Reserved
} CCR6;
// OR
 struct {
      unsigned int TIM1_ETR_ADC1_RMP: 2; // TIM1_ETR_ADC1_RMP
      unsigned int TIM1_ETR_ADC4_RMP: 2; // TIM1_ETR_ADC4_RMP
      unsigned int : 28; // Reserved
} OR;
} SVD_TIM20 __attribute__ ((packed));
asm(".equ SVD_TIM20, 0x40015000");
