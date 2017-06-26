// General-purpose I/Os
 extern struct {
// GPIO port mode register
 struct {
      unsigned int MODER0: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER1: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER2: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER3: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER4: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER5: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER6: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER7: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER8: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER9: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER10: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER11: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER12: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER13: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER14: 2; // Port x configuration bits (y = 0..15)
      unsigned int MODER15: 2; // Port x configuration bits (y = 0..15)
} MODER;
// GPIO port output type register
 struct {
      unsigned int OT0: 1; // Port x configuration bit 0
      unsigned int OT1: 1; // Port x configuration bit 1
      unsigned int OT2: 1; // Port x configuration bit 2
      unsigned int OT3: 1; // Port x configuration bit 3
      unsigned int OT4: 1; // Port x configuration bit 4
      unsigned int OT5: 1; // Port x configuration bit 5
      unsigned int OT6: 1; // Port x configuration bit 6
      unsigned int OT7: 1; // Port x configuration bit 7
      unsigned int OT8: 1; // Port x configuration bit 8
      unsigned int OT9: 1; // Port x configuration bit 9
      unsigned int OT10: 1; // Port x configuration bit 10
      unsigned int OT11: 1; // Port x configuration bit 11
      unsigned int OT12: 1; // Port x configuration bit 12
      unsigned int OT13: 1; // Port x configuration bit 13
      unsigned int OT14: 1; // Port x configuration bit 14
      unsigned int OT15: 1; // Port x configuration bit 15
      unsigned int : 16; // Reserved
} OTYPER;
// GPIO port output speed register
 struct {
      unsigned int OSPEEDR0: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR1: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR2: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR3: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR4: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR5: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR6: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR7: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR8: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR9: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR10: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR11: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR12: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR13: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR14: 2; // Port x configuration bits (y = 0..15)
      unsigned int OSPEEDR15: 2; // Port x configuration bits (y = 0..15)
} OSPEEDR;
// GPIO port pull-up/pull-down register
 struct {
      unsigned int PUPDR0: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR1: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR2: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR3: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR4: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR5: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR6: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR7: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR8: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR9: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR10: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR11: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR12: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR13: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR14: 2; // Port x configuration bits (y = 0..15)
      unsigned int PUPDR15: 2; // Port x configuration bits (y = 0..15)
} PUPDR;
// GPIO port input data register
 struct {
      unsigned int IDR0: 1; // Port input data (y = 0..15)
      unsigned int IDR1: 1; // Port input data (y = 0..15)
      unsigned int IDR2: 1; // Port input data (y = 0..15)
      unsigned int IDR3: 1; // Port input data (y = 0..15)
      unsigned int IDR4: 1; // Port input data (y = 0..15)
      unsigned int IDR5: 1; // Port input data (y = 0..15)
      unsigned int IDR6: 1; // Port input data (y = 0..15)
      unsigned int IDR7: 1; // Port input data (y = 0..15)
      unsigned int IDR8: 1; // Port input data (y = 0..15)
      unsigned int IDR9: 1; // Port input data (y = 0..15)
      unsigned int IDR10: 1; // Port input data (y = 0..15)
      unsigned int IDR11: 1; // Port input data (y = 0..15)
      unsigned int IDR12: 1; // Port input data (y = 0..15)
      unsigned int IDR13: 1; // Port input data (y = 0..15)
      unsigned int IDR14: 1; // Port input data (y = 0..15)
      unsigned int IDR15: 1; // Port input data (y = 0..15)
      unsigned int : 16; // Reserved
} IDR;
// GPIO port output data register
 struct {
      unsigned int ODR0: 1; // Port output data (y = 0..15)
      unsigned int ODR1: 1; // Port output data (y = 0..15)
      unsigned int ODR2: 1; // Port output data (y = 0..15)
      unsigned int ODR3: 1; // Port output data (y = 0..15)
      unsigned int ODR4: 1; // Port output data (y = 0..15)
      unsigned int ODR5: 1; // Port output data (y = 0..15)
      unsigned int ODR6: 1; // Port output data (y = 0..15)
      unsigned int ODR7: 1; // Port output data (y = 0..15)
      unsigned int ODR8: 1; // Port output data (y = 0..15)
      unsigned int ODR9: 1; // Port output data (y = 0..15)
      unsigned int ODR10: 1; // Port output data (y = 0..15)
      unsigned int ODR11: 1; // Port output data (y = 0..15)
      unsigned int ODR12: 1; // Port output data (y = 0..15)
      unsigned int ODR13: 1; // Port output data (y = 0..15)
      unsigned int ODR14: 1; // Port output data (y = 0..15)
      unsigned int ODR15: 1; // Port output data (y = 0..15)
      unsigned int : 16; // Reserved
} ODR;
// GPIO port bit set/reset register
 struct {
      unsigned int BS0: 1; // Port x set bit y (y= 0..15)
      unsigned int BS1: 1; // Port x set bit y (y= 0..15)
      unsigned int BS2: 1; // Port x set bit y (y= 0..15)
      unsigned int BS3: 1; // Port x set bit y (y= 0..15)
      unsigned int BS4: 1; // Port x set bit y (y= 0..15)
      unsigned int BS5: 1; // Port x set bit y (y= 0..15)
      unsigned int BS6: 1; // Port x set bit y (y= 0..15)
      unsigned int BS7: 1; // Port x set bit y (y= 0..15)
      unsigned int BS8: 1; // Port x set bit y (y= 0..15)
      unsigned int BS9: 1; // Port x set bit y (y= 0..15)
      unsigned int BS10: 1; // Port x set bit y (y= 0..15)
      unsigned int BS11: 1; // Port x set bit y (y= 0..15)
      unsigned int BS12: 1; // Port x set bit y (y= 0..15)
      unsigned int BS13: 1; // Port x set bit y (y= 0..15)
      unsigned int BS14: 1; // Port x set bit y (y= 0..15)
      unsigned int BS15: 1; // Port x set bit y (y= 0..15)
      unsigned int BR0: 1; // Port x set bit y (y= 0..15)
      unsigned int BR1: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR2: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR3: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR4: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR5: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR6: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR7: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR8: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR9: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR10: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR11: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR12: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR13: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR14: 1; // Port x reset bit y (y = 0..15)
      unsigned int BR15: 1; // Port x reset bit y (y = 0..15)
} BSRR;
// GPIO port configuration lock register
 struct {
      unsigned int LCK0: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK1: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK2: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK3: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK4: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK5: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK6: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK7: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK8: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK9: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK10: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK11: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK12: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK13: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK14: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCK15: 1; // Port x lock bit y (y= 0..15)
      unsigned int LCKK: 1; // Lok Key
      unsigned int : 15; // Reserved
} LCKR;
// GPIO alternate function low register
 struct {
      unsigned int AFRL0: 4; // Alternate function selection for port x bit y (y = 0..7)
      unsigned int AFRL1: 4; // Alternate function selection for port x bit y (y = 0..7)
      unsigned int AFRL2: 4; // Alternate function selection for port x bit y (y = 0..7)
      unsigned int AFRL3: 4; // Alternate function selection for port x bit y (y = 0..7)
      unsigned int AFRL4: 4; // Alternate function selection for port x bit y (y = 0..7)
      unsigned int AFRL5: 4; // Alternate function selection for port x bit y (y = 0..7)
      unsigned int AFRL6: 4; // Alternate function selection for port x bit y (y = 0..7)
      unsigned int AFRL7: 4; // Alternate function selection for port x bit y (y = 0..7)
} AFRL;
// GPIO alternate function high register
 struct {
      unsigned int AFRH8: 4; // Alternate function selection for port x bit y (y = 8..15)
      unsigned int AFRH9: 4; // Alternate function selection for port x bit y (y = 8..15)
      unsigned int AFRH10: 4; // Alternate function selection for port x bit y (y = 8..15)
      unsigned int AFRH11: 4; // Alternate function selection for port x bit y (y = 8..15)
      unsigned int AFRH12: 4; // Alternate function selection for port x bit y (y = 8..15)
      unsigned int AFRH13: 4; // Alternate function selection for port x bit y (y = 8..15)
      unsigned int AFRH14: 4; // Alternate function selection for port x bit y (y = 8..15)
      unsigned int AFRH15: 4; // Alternate function selection for port x bit y (y = 8..15)
} AFRH;
// Port bit reset register
 struct {
      unsigned int BR0: 1; // Port x Reset bit y
      unsigned int BR1: 1; // Port x Reset bit y
      unsigned int BR2: 1; // Port x Reset bit y
      unsigned int BR3: 1; // Port x Reset bit y
      unsigned int BR4: 1; // Port x Reset bit y
      unsigned int BR5: 1; // Port x Reset bit y
      unsigned int BR6: 1; // Port x Reset bit y
      unsigned int BR7: 1; // Port x Reset bit y
      unsigned int BR8: 1; // Port x Reset bit y
      unsigned int BR9: 1; // Port x Reset bit y
      unsigned int BR10: 1; // Port x Reset bit y
      unsigned int BR11: 1; // Port x Reset bit y
      unsigned int BR12: 1; // Port x Reset bit y
      unsigned int BR13: 1; // Port x Reset bit y
      unsigned int BR14: 1; // Port x Reset bit y
      unsigned int BR15: 1; // Port x Reset bit y
      unsigned int : 16; // Reserved
} BRR;
} SVD_GPIOG;
asm(".equ SVD_GPIOG, 0x48001800");
