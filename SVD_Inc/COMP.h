// Comparator
 extern struct {
// control and status register
 struct {
      unsigned int COMP1EN: 1; // Comparator 1 enable
      unsigned int COMP1_INP_DAC: 1; // COMP1_INP_DAC
      unsigned int COMP1MODE: 2; // Comparator 1 mode
      unsigned int COMP1INSEL: 3; // Comparator 1 inverting input selection
      unsigned int : 3; // Reserved
      unsigned int COMP1_OUT_SEL: 4; // Comparator 1 output selection
      unsigned int : 1; // Reserved
      unsigned int COMP1POL: 1; // Comparator 1 output polarity
      unsigned int COMP1HYST: 2; // Comparator 1 hysteresis
      unsigned int COMP1_BLANKING: 3; // Comparator 1 blanking source
      unsigned int : 9; // Reserved
      unsigned int COMP1OUT: 1; // Comparator 1 output
      unsigned int COMP1LOCK: 1; // Comparator 1 lock
} COMP1_CSR;
// control and status register
 struct {
      unsigned int COMP2EN: 1; // Comparator 2 enable
      unsigned int : 1; // Reserved
      unsigned int COMP2MODE: 2; // Comparator 2 mode
      unsigned int COMP2INSEL: 3; // Comparator 2 inverting input selection
      unsigned int COMP2INPSEL: 1; // Comparator 2 non inverted input selection
      unsigned int : 1; // Reserved
      unsigned int COMP2INMSEL: 1; // Comparator 1inverting input selection
      unsigned int COMP2_OUT_SEL: 4; // Comparator 2 output selection
      unsigned int : 1; // Reserved
      unsigned int COMP2POL: 1; // Comparator 2 output polarity
      unsigned int COMP2HYST: 2; // Comparator 2 hysteresis
      unsigned int COMP2_BLANKING: 3; // Comparator 2 blanking source
      unsigned int : 10; // Reserved
      unsigned int COMP2LOCK: 1; // Comparator 2 lock
} COMP2_CSR;
// control and status register
 struct {
      unsigned int COMP3EN: 1; // Comparator 3 enable
      unsigned int : 1; // Reserved
      unsigned int COMP3MODE: 2; // Comparator 3 mode
      unsigned int COMP3INSEL: 3; // Comparator 3 inverting input selection
      unsigned int COMP3INPSEL: 1; // Comparator 3 non inverted input selection
      unsigned int : 2; // Reserved
      unsigned int COMP3_OUT_SEL: 4; // Comparator 3 output selection
      unsigned int : 1; // Reserved
      unsigned int COMP3POL: 1; // Comparator 3 output polarity
      unsigned int COMP3HYST: 2; // Comparator 3 hysteresis
      unsigned int COMP3_BLANKING: 3; // Comparator 3 blanking source
      unsigned int : 9; // Reserved
      unsigned int COMP3OUT: 1; // Comparator 3 output
      unsigned int COMP3LOCK: 1; // Comparator 3 lock
} COMP3_CSR;
// control and status register
 struct {
      unsigned int COMP4EN: 1; // Comparator 4 enable
      unsigned int : 1; // Reserved
      unsigned int COMP4MODE: 2; // Comparator 4 mode
      unsigned int COMP4INSEL: 3; // Comparator 4 inverting input selection
      unsigned int COMP4INPSEL: 1; // Comparator 4 non inverted input selection
      unsigned int : 1; // Reserved
      unsigned int COM4WINMODE: 1; // Comparator 4 window mode
      unsigned int COMP4_OUT_SEL: 4; // Comparator 4 output selection
      unsigned int : 1; // Reserved
      unsigned int COMP4POL: 1; // Comparator 4 output polarity
      unsigned int COMP4HYST: 2; // Comparator 4 hysteresis
      unsigned int COMP4_BLANKING: 3; // Comparator 4 blanking source
      unsigned int : 9; // Reserved
      unsigned int COMP4OUT: 1; // Comparator 4 output
      unsigned int COMP4LOCK: 1; // Comparator 4 lock
} COMP4_CSR;
// control and status register
 struct {
      unsigned int COMP5EN: 1; // Comparator 5 enable
      unsigned int : 1; // Reserved
      unsigned int COMP5MODE: 2; // Comparator 5 mode
      unsigned int COMP5INSEL: 3; // Comparator 5 inverting input selection
      unsigned int COMP5INPSEL: 1; // Comparator 5 non inverted input selection
      unsigned int : 2; // Reserved
      unsigned int COMP5_OUT_SEL: 4; // Comparator 5 output selection
      unsigned int : 1; // Reserved
      unsigned int COMP5POL: 1; // Comparator 5 output polarity
      unsigned int COMP5HYST: 2; // Comparator 5 hysteresis
      unsigned int COMP5_BLANKING: 3; // Comparator 5 blanking source
      unsigned int : 9; // Reserved
      unsigned int COMP5OUT: 1; // Comparator51 output
      unsigned int COMP5LOCK: 1; // Comparator 5 lock
} COMP5_CSR;
// control and status register
 struct {
      unsigned int COMP6EN: 1; // Comparator 6 enable
      unsigned int : 1; // Reserved
      unsigned int COMP6MODE: 2; // Comparator 6 mode
      unsigned int COMP6INSEL: 3; // Comparator 6 inverting input selection
      unsigned int COMP6INPSEL: 1; // Comparator 6 non inverted input selection
      unsigned int : 1; // Reserved
      unsigned int COM6WINMODE: 1; // Comparator 6 window mode
      unsigned int COMP6_OUT_SEL: 4; // Comparator 6 output selection
      unsigned int : 1; // Reserved
      unsigned int COMP6POL: 1; // Comparator 6 output polarity
      unsigned int COMP6HYST: 2; // Comparator 6 hysteresis
      unsigned int COMP6_BLANKING: 3; // Comparator 6 blanking source
      unsigned int : 9; // Reserved
      unsigned int COMP6OUT: 1; // Comparator 6 output
      unsigned int COMP6LOCK: 1; // Comparator 6 lock
} COMP6_CSR;
// control and status register
 struct {
      unsigned int COMP7EN: 1; // Comparator 7 enable
      unsigned int : 1; // Reserved
      unsigned int COMP7MODE: 2; // Comparator 7 mode
      unsigned int COMP7INSEL: 3; // Comparator 7 inverting input selection
      unsigned int COMP7INPSEL: 1; // Comparator 7 non inverted input selection
      unsigned int : 2; // Reserved
      unsigned int COMP7_OUT_SEL: 4; // Comparator 7 output selection
      unsigned int : 1; // Reserved
      unsigned int COMP7POL: 1; // Comparator 7 output polarity
      unsigned int COMP7HYST: 2; // Comparator 7 hysteresis
      unsigned int COMP7_BLANKING: 3; // Comparator 7 blanking source
      unsigned int : 9; // Reserved
      unsigned int COMP7OUT: 1; // Comparator 7 output
      unsigned int COMP7LOCK: 1; // Comparator 7 lock
} COMP7_CSR;
} SVD_COMP __attribute__ ((packed));
asm(".equ SVD_COMP, 0x4001001c");
