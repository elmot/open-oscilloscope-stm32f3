// Touch sensing controller
 extern struct {
// control register
 struct {
      unsigned int TSCE: 1; // Touch sensing controller enable
      unsigned int START: 1; // Start a new acquisition
      unsigned int AM: 1; // Acquisition mode
      unsigned int SYNCPOL: 1; // Synchronization pin polarity
      unsigned int IODEF: 1; // I/O Default mode
      unsigned int MCV: 3; // Max count value
      unsigned int : 4; // Reserved
      unsigned int PGPSC: 3; // pulse generator prescaler
      unsigned int SSPSC: 1; // Spread spectrum prescaler
      unsigned int SSE: 1; // Spread spectrum enable
      unsigned int SSD: 7; // Spread spectrum deviation
      unsigned int CTPL: 4; // Charge transfer pulse low
      unsigned int CTPH: 4; // Charge transfer pulse high
} CR;
// interrupt enable register
 struct {
      unsigned int EOAIE: 1; // End of acquisition interrupt enable
      unsigned int MCEIE: 1; // Max count error interrupt enable
      unsigned int : 30; // Reserved
} IER;
// interrupt clear register
 struct {
      unsigned int EOAIC: 1; // End of acquisition interrupt clear
      unsigned int MCEIC: 1; // Max count error interrupt clear
      unsigned int : 30; // Reserved
} ICR;
// interrupt status register
 struct {
      unsigned int EOAF: 1; // End of acquisition flag
      unsigned int MCEF: 1; // Max count error flag
      unsigned int : 30; // Reserved
} ISR;
// I/O hysteresis control register
 struct {
      unsigned int G1_IO1: 1; // G1_IO1 Schmitt trigger hysteresis mode
      unsigned int G1_IO2: 1; // G1_IO2 Schmitt trigger hysteresis mode
      unsigned int G1_IO3: 1; // G1_IO3 Schmitt trigger hysteresis mode
      unsigned int G1_IO4: 1; // G1_IO4 Schmitt trigger hysteresis mode
      unsigned int G2_IO1: 1; // G2_IO1 Schmitt trigger hysteresis mode
      unsigned int G2_IO2: 1; // G2_IO2 Schmitt trigger hysteresis mode
      unsigned int G2_IO3: 1; // G2_IO3 Schmitt trigger hysteresis mode
      unsigned int G2_IO4: 1; // G2_IO4 Schmitt trigger hysteresis mode
      unsigned int G3_IO1: 1; // G3_IO1 Schmitt trigger hysteresis mode
      unsigned int G3_IO2: 1; // G3_IO2 Schmitt trigger hysteresis mode
      unsigned int G3_IO3: 1; // G3_IO3 Schmitt trigger hysteresis mode
      unsigned int G3_IO4: 1; // G3_IO4 Schmitt trigger hysteresis mode
      unsigned int G4_IO1: 1; // G4_IO1 Schmitt trigger hysteresis mode
      unsigned int G4_IO2: 1; // G4_IO2 Schmitt trigger hysteresis mode
      unsigned int G4_IO3: 1; // G4_IO3 Schmitt trigger hysteresis mode
      unsigned int G4_IO4: 1; // G4_IO4 Schmitt trigger hysteresis mode
      unsigned int G5_IO1: 1; // G5_IO1 Schmitt trigger hysteresis mode
      unsigned int G5_IO2: 1; // G5_IO2 Schmitt trigger hysteresis mode
      unsigned int G5_IO3: 1; // G5_IO3 Schmitt trigger hysteresis mode
      unsigned int G5_IO4: 1; // G5_IO4 Schmitt trigger hysteresis mode
      unsigned int G6_IO1: 1; // G6_IO1 Schmitt trigger hysteresis mode
      unsigned int G6_IO2: 1; // G6_IO2 Schmitt trigger hysteresis mode
      unsigned int G6_IO3: 1; // G6_IO3 Schmitt trigger hysteresis mode
      unsigned int G6_IO4: 1; // G6_IO4 Schmitt trigger hysteresis mode
      unsigned int G7_IO1: 1; // G7_IO1 Schmitt trigger hysteresis mode
      unsigned int G7_IO2: 1; // G7_IO2 Schmitt trigger hysteresis mode
      unsigned int G7_IO3: 1; // G7_IO3 Schmitt trigger hysteresis mode
      unsigned int G7_IO4: 1; // G7_IO4 Schmitt trigger hysteresis mode
      unsigned int G8_IO1: 1; // G8_IO1 Schmitt trigger hysteresis mode
      unsigned int G8_IO2: 1; // G8_IO2 Schmitt trigger hysteresis mode
      unsigned int G8_IO3: 1; // G8_IO3 Schmitt trigger hysteresis mode
      unsigned int G8_IO4: 1; // G8_IO4 Schmitt trigger hysteresis mode
} IOHCR;
      unsigned int : 32; // Reserved
// I/O analog switch control register
 struct {
      unsigned int G1_IO1: 1; // G1_IO1 analog switch enable
      unsigned int G1_IO2: 1; // G1_IO2 analog switch enable
      unsigned int G1_IO3: 1; // G1_IO3 analog switch enable
      unsigned int G1_IO4: 1; // G1_IO4 analog switch enable
      unsigned int G2_IO1: 1; // G2_IO1 analog switch enable
      unsigned int G2_IO2: 1; // G2_IO2 analog switch enable
      unsigned int G2_IO3: 1; // G2_IO3 analog switch enable
      unsigned int G2_IO4: 1; // G2_IO4 analog switch enable
      unsigned int G3_IO1: 1; // G3_IO1 analog switch enable
      unsigned int G3_IO2: 1; // G3_IO2 analog switch enable
      unsigned int G3_IO3: 1; // G3_IO3 analog switch enable
      unsigned int G3_IO4: 1; // G3_IO4 analog switch enable
      unsigned int G4_IO1: 1; // G4_IO1 analog switch enable
      unsigned int G4_IO2: 1; // G4_IO2 analog switch enable
      unsigned int G4_IO3: 1; // G4_IO3 analog switch enable
      unsigned int G4_IO4: 1; // G4_IO4 analog switch enable
      unsigned int G5_IO1: 1; // G5_IO1 analog switch enable
      unsigned int G5_IO2: 1; // G5_IO2 analog switch enable
      unsigned int G5_IO3: 1; // G5_IO3 analog switch enable
      unsigned int G5_IO4: 1; // G5_IO4 analog switch enable
      unsigned int G6_IO1: 1; // G6_IO1 analog switch enable
      unsigned int G6_IO2: 1; // G6_IO2 analog switch enable
      unsigned int G6_IO3: 1; // G6_IO3 analog switch enable
      unsigned int G6_IO4: 1; // G6_IO4 analog switch enable
      unsigned int G7_IO1: 1; // G7_IO1 analog switch enable
      unsigned int G7_IO2: 1; // G7_IO2 analog switch enable
      unsigned int G7_IO3: 1; // G7_IO3 analog switch enable
      unsigned int G7_IO4: 1; // G7_IO4 analog switch enable
      unsigned int G8_IO1: 1; // G8_IO1 analog switch enable
      unsigned int G8_IO2: 1; // G8_IO2 analog switch enable
      unsigned int G8_IO3: 1; // G8_IO3 analog switch enable
      unsigned int G8_IO4: 1; // G8_IO4 analog switch enable
} IOASCR;
      unsigned int : 32; // Reserved
// I/O sampling control register
 struct {
      unsigned int G1_IO1: 1; // G1_IO1 sampling mode
      unsigned int G1_IO2: 1; // G1_IO2 sampling mode
      unsigned int G1_IO3: 1; // G1_IO3 sampling mode
      unsigned int G1_IO4: 1; // G1_IO4 sampling mode
      unsigned int G2_IO1: 1; // G2_IO1 sampling mode
      unsigned int G2_IO2: 1; // G2_IO2 sampling mode
      unsigned int G2_IO3: 1; // G2_IO3 sampling mode
      unsigned int G2_IO4: 1; // G2_IO4 sampling mode
      unsigned int G3_IO1: 1; // G3_IO1 sampling mode
      unsigned int G3_IO2: 1; // G3_IO2 sampling mode
      unsigned int G3_IO3: 1; // G3_IO3 sampling mode
      unsigned int G3_IO4: 1; // G3_IO4 sampling mode
      unsigned int G4_IO1: 1; // G4_IO1 sampling mode
      unsigned int G4_IO2: 1; // G4_IO2 sampling mode
      unsigned int G4_IO3: 1; // G4_IO3 sampling mode
      unsigned int G4_IO4: 1; // G4_IO4 sampling mode
      unsigned int G5_IO1: 1; // G5_IO1 sampling mode
      unsigned int G5_IO2: 1; // G5_IO2 sampling mode
      unsigned int G5_IO3: 1; // G5_IO3 sampling mode
      unsigned int G5_IO4: 1; // G5_IO4 sampling mode
      unsigned int G6_IO1: 1; // G6_IO1 sampling mode
      unsigned int G6_IO2: 1; // G6_IO2 sampling mode
      unsigned int G6_IO3: 1; // G6_IO3 sampling mode
      unsigned int G6_IO4: 1; // G6_IO4 sampling mode
      unsigned int G7_IO1: 1; // G7_IO1 sampling mode
      unsigned int G7_IO2: 1; // G7_IO2 sampling mode
      unsigned int G7_IO3: 1; // G7_IO3 sampling mode
      unsigned int G7_IO4: 1; // G7_IO4 sampling mode
      unsigned int G8_IO1: 1; // G8_IO1 sampling mode
      unsigned int G8_IO2: 1; // G8_IO2 sampling mode
      unsigned int G8_IO3: 1; // G8_IO3 sampling mode
      unsigned int G8_IO4: 1; // G8_IO4 sampling mode
} IOSCR;
      unsigned int : 32; // Reserved
// I/O channel control register
 struct {
      unsigned int G1_IO1: 1; // G1_IO1 channel mode
      unsigned int G1_IO2: 1; // G1_IO2 channel mode
      unsigned int G1_IO3: 1; // G1_IO3 channel mode
      unsigned int G1_IO4: 1; // G1_IO4 channel mode
      unsigned int G2_IO1: 1; // G2_IO1 channel mode
      unsigned int G2_IO2: 1; // G2_IO2 channel mode
      unsigned int G2_IO3: 1; // G2_IO3 channel mode
      unsigned int G2_IO4: 1; // G2_IO4 channel mode
      unsigned int G3_IO1: 1; // G3_IO1 channel mode
      unsigned int G3_IO2: 1; // G3_IO2 channel mode
      unsigned int G3_IO3: 1; // G3_IO3 channel mode
      unsigned int G3_IO4: 1; // G3_IO4 channel mode
      unsigned int G4_IO1: 1; // G4_IO1 channel mode
      unsigned int G4_IO2: 1; // G4_IO2 channel mode
      unsigned int G4_IO3: 1; // G4_IO3 channel mode
      unsigned int G4_IO4: 1; // G4_IO4 channel mode
      unsigned int G5_IO1: 1; // G5_IO1 channel mode
      unsigned int G5_IO2: 1; // G5_IO2 channel mode
      unsigned int G5_IO3: 1; // G5_IO3 channel mode
      unsigned int G5_IO4: 1; // G5_IO4 channel mode
      unsigned int G6_IO1: 1; // G6_IO1 channel mode
      unsigned int G6_IO2: 1; // G6_IO2 channel mode
      unsigned int G6_IO3: 1; // G6_IO3 channel mode
      unsigned int G6_IO4: 1; // G6_IO4 channel mode
      unsigned int G7_IO1: 1; // G7_IO1 channel mode
      unsigned int G7_IO2: 1; // G7_IO2 channel mode
      unsigned int G7_IO3: 1; // G7_IO3 channel mode
      unsigned int G7_IO4: 1; // G7_IO4 channel mode
      unsigned int G8_IO1: 1; // G8_IO1 channel mode
      unsigned int G8_IO2: 1; // G8_IO2 channel mode
      unsigned int G8_IO3: 1; // G8_IO3 channel mode
      unsigned int G8_IO4: 1; // G8_IO4 channel mode
} IOCCR;
      unsigned int : 32; // Reserved
// I/O group control status register
 struct {
      unsigned int G1E: 1; // Analog I/O group x enable
      unsigned int G2E: 1; // Analog I/O group x enable
      unsigned int G3E: 1; // Analog I/O group x enable
      unsigned int G4E: 1; // Analog I/O group x enable
      unsigned int G5E: 1; // Analog I/O group x enable
      unsigned int G6E: 1; // Analog I/O group x enable
      unsigned int G7E: 1; // Analog I/O group x enable
      unsigned int G8E: 1; // Analog I/O group x enable
      unsigned int : 8; // Reserved
      unsigned int G1S: 1; // Analog I/O group x status
      unsigned int G2S: 1; // Analog I/O group x status
      unsigned int G3S: 1; // Analog I/O group x status
      unsigned int G4S: 1; // Analog I/O group x status
      unsigned int G5S: 1; // Analog I/O group x status
      unsigned int G6S: 1; // Analog I/O group x status
      unsigned int G7S: 1; // Analog I/O group x status
      unsigned int G8S: 1; // Analog I/O group x status
      unsigned int : 8; // Reserved
} IOGCSR;
// I/O group x counter register
 struct {
      unsigned int CNT: 14; // Counter value
      unsigned int : 18; // Reserved
} IOG1CR;
// I/O group x counter register
 struct {
      unsigned int CNT: 14; // Counter value
      unsigned int : 18; // Reserved
} IOG2CR;
// I/O group x counter register
 struct {
      unsigned int CNT: 14; // Counter value
      unsigned int : 18; // Reserved
} IOG3CR;
// I/O group x counter register
 struct {
      unsigned int CNT: 14; // Counter value
      unsigned int : 18; // Reserved
} IOG4CR;
// I/O group x counter register
 struct {
      unsigned int CNT: 14; // Counter value
      unsigned int : 18; // Reserved
} IOG5CR;
// I/O group x counter register
 struct {
      unsigned int CNT: 14; // Counter value
      unsigned int : 18; // Reserved
} IOG6CR;
// I/O group x counter register
 struct {
      unsigned int CNT: 14; // Counter value
      unsigned int : 18; // Reserved
} IOG7CR;
// I/O group x counter register
 struct {
      unsigned int CNT: 14; // Counter value
      unsigned int : 18; // Reserved
} IOG8CR;
} SVD_TSC;
asm(".equ SVD_TSC, 0x40024000");
