// TIM2
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
      unsigned int : 3; // Reserved
      unsigned int CCDS: 1; // CCDS
      unsigned int MMS: 3; // MMS
      unsigned int TI1S: 1; // TI1S
      unsigned int : 24; // Reserved
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
      unsigned int SMS_3: 1; // SMS_3
      unsigned int : 15; // Reserved
} SMCR;
// DIER
 struct {
      unsigned int UIE: 1; // UIE
      unsigned int CC1IE: 1; // CC1IE
      unsigned int CC2IE: 1; // CC2IE
      unsigned int CC3IE: 1; // CC3IE
      unsigned int CC4IE: 1; // CC4IE
      unsigned int : 1; // Reserved
      unsigned int TIE: 1; // TIE
      unsigned int : 1; // Reserved
      unsigned int UDE: 1; // UDE
      unsigned int CC1DE: 1; // CC1DE
      unsigned int CC2DE: 1; // CC2DE
      unsigned int CC3DE: 1; // CC3DE
      unsigned int CC4DE: 1; // CC4DE
      unsigned int : 1; // Reserved
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
      unsigned int : 1; // Reserved
      unsigned int TIF: 1; // TIF
      unsigned int : 2; // Reserved
      unsigned int CC1OF: 1; // CC1OF
      unsigned int CC2OF: 1; // CC2OF
      unsigned int CC3OF: 1; // CC3OF
      unsigned int CC4OF: 1; // CC4OF
      unsigned int : 19; // Reserved
} SR;
// EGR
 struct {
      unsigned int UG: 1; // UG
      unsigned int CC1G: 1; // CC1G
      unsigned int CC2G: 1; // CC2G
      unsigned int CC3G: 1; // CC3G
      unsigned int CC4G: 1; // CC4G
      unsigned int : 1; // Reserved
      unsigned int TG: 1; // TG
      unsigned int : 25; // Reserved
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
      unsigned int O24CE: 1; // O24CE
      unsigned int OC3M_3: 1; // OC3M_3
      unsigned int : 7; // Reserved
      unsigned int OC4M_3: 1; // OC4M_3
      unsigned int : 7; // Reserved
} CCMR2_Output;
// CCER
 struct {
      unsigned int CC1E: 1; // CC1E
      unsigned int CC1P: 1; // CC1P
      unsigned int : 1; // Reserved
      unsigned int CC1NP: 1; // CC1NP
      unsigned int CC2E: 1; // CC2E
      unsigned int CC2P: 1; // CC2P
      unsigned int : 1; // Reserved
      unsigned int CC2NP: 1; // CC2NP
      unsigned int CC3E: 1; // CC3E
      unsigned int CC3P: 1; // CC3P
      unsigned int : 1; // Reserved
      unsigned int CC3NP: 1; // CC3NP
      unsigned int CC4E: 1; // CC4E
      unsigned int CC4P: 1; // CC4P
      unsigned int : 1; // Reserved
      unsigned int CC4NP: 1; // CC4NP
      unsigned int : 16; // Reserved
} CCER;
// CNT
 struct {
      unsigned int CNTL: 16; // CNTL
      unsigned int CNTH: 15; // CNTH
      unsigned int CNT_or_UIFCPY: 1; // CNT_or_UIFCPY
} CNT;
// PSC
 struct {
      unsigned int PSC: 16; // PSC
      unsigned int : 16; // Reserved
} PSC;
// ARR
 struct {
      unsigned int ARRL: 16; // ARRL
      unsigned int ARRH: 16; // ARRH
} ARR;
      unsigned int : 32; // Reserved
// CCR1
 struct {
      unsigned int CCR1L: 16; // CCR1L
      unsigned int CCR1H: 16; // CCR1H
} CCR1;
// CCR2
 struct {
      unsigned int CCR2L: 16; // CCR2L
      unsigned int CCR2H: 16; // CCR2H
} CCR2;
// CCR3
 struct {
      unsigned int CCR3L: 16; // CCR3L
      unsigned int CCR3H: 16; // CCR3H
} CCR3;
// CCR4
 struct {
      unsigned int CCR4L: 16; // CCR4L
      unsigned int CCR4H: 16; // CCR4H
} CCR4;
      unsigned int : 32; // Reserved
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
} SVD_TIM3 __attribute__ ((packed));
asm(".equ SVD_TIM3, 0x40000400");
