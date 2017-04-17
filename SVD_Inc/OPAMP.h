// Operational amplifier
 extern struct {
// OPAMP1 control register
 struct {
      unsigned int OPAMP1_EN: 1; // OPAMP1 enable
      unsigned int FORCE_VP: 1; // FORCE_VP
      unsigned int VP_SEL: 2; // OPAMP1 Non inverting input selection
      unsigned int : 1; // Reserved
      unsigned int VM_SEL: 2; // OPAMP1 inverting input selection
      unsigned int TCM_EN: 1; // Timer controlled Mux mode enable
      unsigned int VMS_SEL: 1; // OPAMP1 inverting input secondary selection
      unsigned int VPS_SEL: 2; // OPAMP1 Non inverting input secondary selection
      unsigned int CALON: 1; // Calibration mode enable
      unsigned int CALSEL: 2; // Calibration selection
      unsigned int PGA_GAIN: 4; // Gain in PGA mode
      unsigned int USER_TRIM: 1; // User trimming enable
      unsigned int TRIMOFFSETP: 5; // Offset trimming value (PMOS)
      unsigned int TRIMOFFSETN: 5; // Offset trimming value (NMOS)
      unsigned int TSTREF: 1; // TSTREF
      unsigned int OUTCAL: 1; // OPAMP 1 ouput status flag
      unsigned int LOCK: 1; // OPAMP 1 lock
} OPAMP1_CR;
// OPAMP2 control register
 struct {
      unsigned int OPAMP2EN: 1; // OPAMP2 enable
      unsigned int FORCE_VP: 1; // FORCE_VP
      unsigned int VP_SEL: 2; // OPAMP2 Non inverting input selection
      unsigned int : 1; // Reserved
      unsigned int VM_SEL: 2; // OPAMP2 inverting input selection
      unsigned int TCM_EN: 1; // Timer controlled Mux mode enable
      unsigned int VMS_SEL: 1; // OPAMP2 inverting input secondary selection
      unsigned int VPS_SEL: 2; // OPAMP2 Non inverting input secondary selection
      unsigned int CALON: 1; // Calibration mode enable
      unsigned int CAL_SEL: 2; // Calibration selection
      unsigned int PGA_GAIN: 4; // Gain in PGA mode
      unsigned int USER_TRIM: 1; // User trimming enable
      unsigned int TRIMOFFSETP: 5; // Offset trimming value (PMOS)
      unsigned int TRIMOFFSETN: 5; // Offset trimming value (NMOS)
      unsigned int TSTREF: 1; // TSTREF
      unsigned int OUTCAL: 1; // OPAMP 2 ouput status flag
      unsigned int LOCK: 1; // OPAMP 2 lock
} OPAMP2_CR;
// OPAMP3 control register
 struct {
      unsigned int OPAMP3EN: 1; // OPAMP3 enable
      unsigned int FORCE_VP: 1; // FORCE_VP
      unsigned int VP_SEL: 2; // OPAMP3 Non inverting input selection
      unsigned int : 1; // Reserved
      unsigned int VM_SEL: 2; // OPAMP3 inverting input selection
      unsigned int TCM_EN: 1; // Timer controlled Mux mode enable
      unsigned int VMS_SEL: 1; // OPAMP3 inverting input secondary selection
      unsigned int VPS_SEL: 2; // OPAMP3 Non inverting input secondary selection
      unsigned int CALON: 1; // Calibration mode enable
      unsigned int CALSEL: 2; // Calibration selection
      unsigned int PGA_GAIN: 4; // Gain in PGA mode
      unsigned int USER_TRIM: 1; // User trimming enable
      unsigned int TRIMOFFSETP: 5; // Offset trimming value (PMOS)
      unsigned int TRIMOFFSETN: 5; // Offset trimming value (NMOS)
      unsigned int TSTREF: 1; // TSTREF
      unsigned int OUTCAL: 1; // OPAMP 3 ouput status flag
      unsigned int LOCK: 1; // OPAMP 3 lock
} OPAMP3_CR;
// OPAMP4 control register
 struct {
      unsigned int OPAMP4EN: 1; // OPAMP4 enable
      unsigned int FORCE_VP: 1; // FORCE_VP
      unsigned int VP_SEL: 2; // OPAMP4 Non inverting input selection
      unsigned int : 1; // Reserved
      unsigned int VM_SEL: 2; // OPAMP4 inverting input selection
      unsigned int TCM_EN: 1; // Timer controlled Mux mode enable
      unsigned int VMS_SEL: 1; // OPAMP4 inverting input secondary selection
      unsigned int VPS_SEL: 2; // OPAMP4 Non inverting input secondary selection
      unsigned int CALON: 1; // Calibration mode enable
      unsigned int CALSEL: 2; // Calibration selection
      unsigned int PGA_GAIN: 4; // Gain in PGA mode
      unsigned int USER_TRIM: 1; // User trimming enable
      unsigned int TRIMOFFSETP: 5; // Offset trimming value (PMOS)
      unsigned int TRIMOFFSETN: 5; // Offset trimming value (NMOS)
      unsigned int TSTREF: 1; // TSTREF
      unsigned int OUTCAL: 1; // OPAMP 4 ouput status flag
      unsigned int LOCK: 1; // OPAMP 4 lock
} OPAMP4_CR;
} SVD_OPAMP;
asm(".equ SVD_OPAMP, 0x40010038");
