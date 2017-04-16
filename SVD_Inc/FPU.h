// Floting point unit
 extern struct {
// Coprocessor Access Control Register
 struct {
      unsigned int CP0: 1; // Access privileges for coprocessor 0
      unsigned int : 1; // Reserved
      unsigned int CP1: 1; // Access privileges for coprocessor 1
      unsigned int : 1; // Reserved
      unsigned int CP2: 1; // Access privileges for coprocessor 2
      unsigned int : 1; // Reserved
      unsigned int CP3: 1; // Access privileges for coprocessor 3
      unsigned int : 1; // Reserved
      unsigned int CP4: 1; // Access privileges for coprocessor 4
      unsigned int : 1; // Reserved
      unsigned int CP5: 1; // Access privileges for coprocessor 5
      unsigned int : 1; // Reserved
      unsigned int CP6: 2; // Access privileges for coprocessor 6
      unsigned int CP7: 1; // Access privileges for coprocessor 7
      unsigned int : 5; // Reserved
      unsigned int CP10: 1; // Access privileges for coprocessor 10
      unsigned int : 1; // Reserved
      unsigned int CP11: 1; // Access privileges for coprocessor 11
      unsigned int : 9; // Reserved
} CPACR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// FP Context Control Register
 struct {
      unsigned int LSPACT: 1; // LSPACT
      unsigned int USER: 1; // USER
      unsigned int : 1; // Reserved
      unsigned int THREAD: 1; // THREAD
      unsigned int HFRDY: 1; // HFRDY
      unsigned int MMRDY: 1; // MMRDY
      unsigned int BFRDY: 1; // BFRDY
      unsigned int : 1; // Reserved
      unsigned int MONRDY: 1; // MONRDY
      unsigned int : 21; // Reserved
      unsigned int LSPEN: 1; // LSPEN
      unsigned int ASPEN: 1; // ASPEN
} FPCCR;
// FP Context Address Register
 struct {
      unsigned int : 3; // Reserved
      unsigned int ADDRESS: 29; // ADDRESS
} FPCAR;
// FP Default Status Control Register
 struct {
      unsigned int : 22; // Reserved
      unsigned int RMode: 2; // RMode
      unsigned int FZ: 1; // FZ
      unsigned int DN: 1; // DN
      unsigned int AHP: 1; // AHP
      unsigned int : 5; // Reserved
} FPDSCR;
// Media and VFP Feature Register 0
 struct {
      unsigned int A_SIMD: 4; // A_SIMD registers
      unsigned int Single_precision: 4; // Single_precision
      unsigned int Double_precision: 4; // Double_precision
      unsigned int FP_exception_trapping: 4; // FP exception trapping
      unsigned int Divide: 4; // Divide
      unsigned int Square_root: 4; // Square root
      unsigned int Short_vectors: 4; // Short vectors
      unsigned int FP_rounding_modes: 4; // FP rounding modes
} MVFR0;
// Media and VFP Feature Register 1
 struct {
      unsigned int FtZ_mode: 4; // FtZ mode
      unsigned int D_NaN_mode: 4; // D_NaN mode
      unsigned int : 16; // Reserved
      unsigned int FP_HPFP: 4; // FP HPFP
      unsigned int FP_fused_MAC: 4; // FP fused MAC
} MVFR1;
} SVD_FPU __attribute__ ((packed));
asm(".equ SVD_FPU, 0xe000ed88");
