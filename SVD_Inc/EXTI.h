// External interrupt/event controller
 extern struct {
// Interrupt mask register
 struct {
      unsigned int MR0: 1; // Interrupt Mask on line 0
      unsigned int MR1: 1; // Interrupt Mask on line 1
      unsigned int MR2: 1; // Interrupt Mask on line 2
      unsigned int MR3: 1; // Interrupt Mask on line 3
      unsigned int MR4: 1; // Interrupt Mask on line 4
      unsigned int MR5: 1; // Interrupt Mask on line 5
      unsigned int MR6: 1; // Interrupt Mask on line 6
      unsigned int MR7: 1; // Interrupt Mask on line 7
      unsigned int MR8: 1; // Interrupt Mask on line 8
      unsigned int MR9: 1; // Interrupt Mask on line 9
      unsigned int MR10: 1; // Interrupt Mask on line 10
      unsigned int MR11: 1; // Interrupt Mask on line 11
      unsigned int MR12: 1; // Interrupt Mask on line 12
      unsigned int MR13: 1; // Interrupt Mask on line 13
      unsigned int MR14: 1; // Interrupt Mask on line 14
      unsigned int MR15: 1; // Interrupt Mask on line 15
      unsigned int MR16: 1; // Interrupt Mask on line 16
      unsigned int MR17: 1; // Interrupt Mask on line 17
      unsigned int MR18: 1; // Interrupt Mask on line 18
      unsigned int MR19: 1; // Interrupt Mask on line 19
      unsigned int MR20: 1; // Interrupt Mask on line 20
      unsigned int MR21: 1; // Interrupt Mask on line 21
      unsigned int MR22: 1; // Interrupt Mask on line 22
      unsigned int MR23: 1; // Interrupt Mask on line 23
      unsigned int MR24: 1; // Interrupt Mask on line 24
      unsigned int MR25: 1; // Interrupt Mask on line 25
      unsigned int MR26: 1; // Interrupt Mask on line 26
      unsigned int MR27: 1; // Interrupt Mask on line 27
      unsigned int MR28: 1; // Interrupt Mask on line 28
      unsigned int MR29: 1; // Interrupt Mask on line 29
      unsigned int MR30: 1; // Interrupt Mask on line 30
      unsigned int MR31: 1; // Interrupt Mask on line 31
} IMR1;
// Event mask register
 struct {
      unsigned int MR0: 1; // Event Mask on line 0
      unsigned int MR1: 1; // Event Mask on line 1
      unsigned int MR2: 1; // Event Mask on line 2
      unsigned int MR3: 1; // Event Mask on line 3
      unsigned int MR4: 1; // Event Mask on line 4
      unsigned int MR5: 1; // Event Mask on line 5
      unsigned int MR6: 1; // Event Mask on line 6
      unsigned int MR7: 1; // Event Mask on line 7
      unsigned int MR8: 1; // Event Mask on line 8
      unsigned int MR9: 1; // Event Mask on line 9
      unsigned int MR10: 1; // Event Mask on line 10
      unsigned int MR11: 1; // Event Mask on line 11
      unsigned int MR12: 1; // Event Mask on line 12
      unsigned int MR13: 1; // Event Mask on line 13
      unsigned int MR14: 1; // Event Mask on line 14
      unsigned int MR15: 1; // Event Mask on line 15
      unsigned int MR16: 1; // Event Mask on line 16
      unsigned int MR17: 1; // Event Mask on line 17
      unsigned int MR18: 1; // Event Mask on line 18
      unsigned int MR19: 1; // Event Mask on line 19
      unsigned int MR20: 1; // Event Mask on line 20
      unsigned int MR21: 1; // Event Mask on line 21
      unsigned int MR22: 1; // Event Mask on line 22
      unsigned int MR23: 1; // Event Mask on line 23
      unsigned int MR24: 1; // Event Mask on line 24
      unsigned int MR25: 1; // Event Mask on line 25
      unsigned int MR26: 1; // Event Mask on line 26
      unsigned int MR27: 1; // Event Mask on line 27
      unsigned int MR28: 1; // Event Mask on line 28
      unsigned int MR29: 1; // Event Mask on line 29
      unsigned int MR30: 1; // Event Mask on line 30
      unsigned int MR31: 1; // Event Mask on line 31
} EMR1;
// Rising Trigger selection register
 struct {
      unsigned int TR0: 1; // Rising trigger event configuration of line 0
      unsigned int TR1: 1; // Rising trigger event configuration of line 1
      unsigned int TR2: 1; // Rising trigger event configuration of line 2
      unsigned int TR3: 1; // Rising trigger event configuration of line 3
      unsigned int TR4: 1; // Rising trigger event configuration of line 4
      unsigned int TR5: 1; // Rising trigger event configuration of line 5
      unsigned int TR6: 1; // Rising trigger event configuration of line 6
      unsigned int TR7: 1; // Rising trigger event configuration of line 7
      unsigned int TR8: 1; // Rising trigger event configuration of line 8
      unsigned int TR9: 1; // Rising trigger event configuration of line 9
      unsigned int TR10: 1; // Rising trigger event configuration of line 10
      unsigned int TR11: 1; // Rising trigger event configuration of line 11
      unsigned int TR12: 1; // Rising trigger event configuration of line 12
      unsigned int TR13: 1; // Rising trigger event configuration of line 13
      unsigned int TR14: 1; // Rising trigger event configuration of line 14
      unsigned int TR15: 1; // Rising trigger event configuration of line 15
      unsigned int TR16: 1; // Rising trigger event configuration of line 16
      unsigned int TR17: 1; // Rising trigger event configuration of line 17
      unsigned int TR18: 1; // Rising trigger event configuration of line 18
      unsigned int TR19: 1; // Rising trigger event configuration of line 19
      unsigned int TR20: 1; // Rising trigger event configuration of line 20
      unsigned int TR21: 1; // Rising trigger event configuration of line 21
      unsigned int TR22: 1; // Rising trigger event configuration of line 22
      unsigned int : 6; // Reserved
      unsigned int TR29: 1; // Rising trigger event configuration of line 29
      unsigned int TR30: 1; // Rising trigger event configuration of line 30
      unsigned int TR31: 1; // Rising trigger event configuration of line 31
} RTSR1;
// Falling Trigger selection register
 struct {
      unsigned int TR0: 1; // Falling trigger event configuration of line 0
      unsigned int TR1: 1; // Falling trigger event configuration of line 1
      unsigned int TR2: 1; // Falling trigger event configuration of line 2
      unsigned int TR3: 1; // Falling trigger event configuration of line 3
      unsigned int TR4: 1; // Falling trigger event configuration of line 4
      unsigned int TR5: 1; // Falling trigger event configuration of line 5
      unsigned int TR6: 1; // Falling trigger event configuration of line 6
      unsigned int TR7: 1; // Falling trigger event configuration of line 7
      unsigned int TR8: 1; // Falling trigger event configuration of line 8
      unsigned int TR9: 1; // Falling trigger event configuration of line 9
      unsigned int TR10: 1; // Falling trigger event configuration of line 10
      unsigned int TR11: 1; // Falling trigger event configuration of line 11
      unsigned int TR12: 1; // Falling trigger event configuration of line 12
      unsigned int TR13: 1; // Falling trigger event configuration of line 13
      unsigned int TR14: 1; // Falling trigger event configuration of line 14
      unsigned int TR15: 1; // Falling trigger event configuration of line 15
      unsigned int TR16: 1; // Falling trigger event configuration of line 16
      unsigned int TR17: 1; // Falling trigger event configuration of line 17
      unsigned int TR18: 1; // Falling trigger event configuration of line 18
      unsigned int TR19: 1; // Falling trigger event configuration of line 19
      unsigned int TR20: 1; // Falling trigger event configuration of line 20
      unsigned int TR21: 1; // Falling trigger event configuration of line 21
      unsigned int TR22: 1; // Falling trigger event configuration of line 22
      unsigned int : 6; // Reserved
      unsigned int TR29: 1; // Falling trigger event configuration of line 29
      unsigned int TR30: 1; // Falling trigger event configuration of line 30.
      unsigned int TR31: 1; // Falling trigger event configuration of line 31
} FTSR1;
// Software interrupt event register
 struct {
      unsigned int SWIER0: 1; // Software Interrupt on line 0
      unsigned int SWIER1: 1; // Software Interrupt on line 1
      unsigned int SWIER2: 1; // Software Interrupt on line 2
      unsigned int SWIER3: 1; // Software Interrupt on line 3
      unsigned int SWIER4: 1; // Software Interrupt on line 4
      unsigned int SWIER5: 1; // Software Interrupt on line 5
      unsigned int SWIER6: 1; // Software Interrupt on line 6
      unsigned int SWIER7: 1; // Software Interrupt on line 7
      unsigned int SWIER8: 1; // Software Interrupt on line 8
      unsigned int SWIER9: 1; // Software Interrupt on line 9
      unsigned int SWIER10: 1; // Software Interrupt on line 10
      unsigned int SWIER11: 1; // Software Interrupt on line 11
      unsigned int SWIER12: 1; // Software Interrupt on line 12
      unsigned int SWIER13: 1; // Software Interrupt on line 13
      unsigned int SWIER14: 1; // Software Interrupt on line 14
      unsigned int SWIER15: 1; // Software Interrupt on line 15
      unsigned int SWIER16: 1; // Software Interrupt on line 16
      unsigned int SWIER17: 1; // Software Interrupt on line 17
      unsigned int SWIER18: 1; // Software Interrupt on line 18
      unsigned int SWIER19: 1; // Software Interrupt on line 19
      unsigned int SWIER20: 1; // Software Interrupt on line 20
      unsigned int SWIER21: 1; // Software Interrupt on line 21
      unsigned int SWIER22: 1; // Software Interrupt on line 22
      unsigned int : 6; // Reserved
      unsigned int SWIER29: 1; // Software Interrupt on line 29
      unsigned int SWIER30: 1; // Software Interrupt on line 309
      unsigned int SWIER31: 1; // Software Interrupt on line 319
} SWIER1;
// Pending register
 struct {
      unsigned int PR0: 1; // Pending bit 0
      unsigned int PR1: 1; // Pending bit 1
      unsigned int PR2: 1; // Pending bit 2
      unsigned int PR3: 1; // Pending bit 3
      unsigned int PR4: 1; // Pending bit 4
      unsigned int PR5: 1; // Pending bit 5
      unsigned int PR6: 1; // Pending bit 6
      unsigned int PR7: 1; // Pending bit 7
      unsigned int PR8: 1; // Pending bit 8
      unsigned int PR9: 1; // Pending bit 9
      unsigned int PR10: 1; // Pending bit 10
      unsigned int PR11: 1; // Pending bit 11
      unsigned int PR12: 1; // Pending bit 12
      unsigned int PR13: 1; // Pending bit 13
      unsigned int PR14: 1; // Pending bit 14
      unsigned int PR15: 1; // Pending bit 15
      unsigned int PR16: 1; // Pending bit 16
      unsigned int PR17: 1; // Pending bit 17
      unsigned int PR18: 1; // Pending bit 18
      unsigned int PR19: 1; // Pending bit 19
      unsigned int PR20: 1; // Pending bit 20
      unsigned int PR21: 1; // Pending bit 21
      unsigned int PR22: 1; // Pending bit 22
      unsigned int : 6; // Reserved
      unsigned int PR29: 1; // Pending bit 29
      unsigned int PR30: 1; // Pending bit 30
      unsigned int PR31: 1; // Pending bit 31
} PR1;
// Interrupt mask register
 struct {
      unsigned int MR32: 1; // Interrupt Mask on external/internal line 32
      unsigned int MR33: 1; // Interrupt Mask on external/internal line 33
      unsigned int MR34: 1; // Interrupt Mask on external/internal line 34
      unsigned int MR35: 1; // Interrupt Mask on external/internal line 35
      unsigned int : 28; // Reserved
} IMR2;
// Event mask register
 struct {
      unsigned int MR32: 1; // Event mask on external/internal line 32
      unsigned int MR33: 1; // Event mask on external/internal line 33
      unsigned int MR34: 1; // Event mask on external/internal line 34
      unsigned int MR35: 1; // Event mask on external/internal line 35
      unsigned int : 28; // Reserved
} EMR2;
// Rising Trigger selection register
 struct {
      unsigned int TR32: 1; // Rising trigger event configuration bit of line 32
      unsigned int TR33: 1; // Rising trigger event configuration bit of line 33
      unsigned int : 30; // Reserved
} RTSR2;
// Falling Trigger selection register
 struct {
      unsigned int TR32: 1; // Falling trigger event configuration bit of line 32
      unsigned int TR33: 1; // Falling trigger event configuration bit of line 33
      unsigned int : 30; // Reserved
} FTSR2;
// Software interrupt event register
 struct {
      unsigned int SWIER32: 1; // Software interrupt on line 32
      unsigned int SWIER33: 1; // Software interrupt on line 33
      unsigned int : 30; // Reserved
} SWIER2;
// Pending register
 struct {
      unsigned int PR32: 1; // Pending bit on line 32
      unsigned int PR33: 1; // Pending bit on line 33
      unsigned int : 30; // Reserved
} PR2;
} SVD_EXTI;
asm(".equ SVD_EXTI, 0x40010400");
