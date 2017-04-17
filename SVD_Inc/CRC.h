// cyclic redundancy check calculation unit
 extern struct {
// Data register
 struct {
      unsigned int DR: 32; // Data register bits
} DR;
// Independent data register
 struct {
      unsigned int IDR: 8; // General-purpose 8-bit data register bits
      unsigned int : 24; // Reserved
} IDR;
// Control register
 struct {
      unsigned int RESET: 1; // reset bit
      unsigned int : 2; // Reserved
      unsigned int POLYSIZE: 2; // Polynomial size
      unsigned int REV_IN: 2; // Reverse input data
      unsigned int REV_OUT: 1; // Reverse output data
      unsigned int : 24; // Reserved
} CR;
      unsigned int : 32; // Reserved
// Initial CRC value
 struct {
      unsigned int INIT: 32; // Programmable initial CRC value
} INIT;
// CRC polynomial
 struct {
      unsigned int POL: 32; // Programmable polynomial
} POL;
} SVD_CRC;
asm(".equ SVD_CRC, 0x40023000");
