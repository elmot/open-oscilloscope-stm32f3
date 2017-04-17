// DMA controller 1
 extern struct {
// DMA interrupt status register (DMA_ISR)
 struct {
      unsigned int GIF1: 1; // Channel 1 Global interrupt flag
      unsigned int TCIF1: 1; // Channel 1 Transfer Complete flag
      unsigned int HTIF1: 1; // Channel 1 Half Transfer Complete flag
      unsigned int TEIF1: 1; // Channel 1 Transfer Error flag
      unsigned int GIF2: 1; // Channel 2 Global interrupt flag
      unsigned int TCIF2: 1; // Channel 2 Transfer Complete flag
      unsigned int HTIF2: 1; // Channel 2 Half Transfer Complete flag
      unsigned int TEIF2: 1; // Channel 2 Transfer Error flag
      unsigned int GIF3: 1; // Channel 3 Global interrupt flag
      unsigned int TCIF3: 1; // Channel 3 Transfer Complete flag
      unsigned int HTIF3: 1; // Channel 3 Half Transfer Complete flag
      unsigned int TEIF3: 1; // Channel 3 Transfer Error flag
      unsigned int GIF4: 1; // Channel 4 Global interrupt flag
      unsigned int TCIF4: 1; // Channel 4 Transfer Complete flag
      unsigned int HTIF4: 1; // Channel 4 Half Transfer Complete flag
      unsigned int TEIF4: 1; // Channel 4 Transfer Error flag
      unsigned int GIF5: 1; // Channel 5 Global interrupt flag
      unsigned int TCIF5: 1; // Channel 5 Transfer Complete flag
      unsigned int HTIF5: 1; // Channel 5 Half Transfer Complete flag
      unsigned int TEIF5: 1; // Channel 5 Transfer Error flag
      unsigned int GIF6: 1; // Channel 6 Global interrupt flag
      unsigned int TCIF6: 1; // Channel 6 Transfer Complete flag
      unsigned int HTIF6: 1; // Channel 6 Half Transfer Complete flag
      unsigned int TEIF6: 1; // Channel 6 Transfer Error flag
      unsigned int GIF7: 1; // Channel 7 Global interrupt flag
      unsigned int TCIF7: 1; // Channel 7 Transfer Complete flag
      unsigned int HTIF7: 1; // Channel 7 Half Transfer Complete flag
      unsigned int TEIF7: 1; // Channel 7 Transfer Error flag
      unsigned int : 4; // Reserved
} ISR;
// DMA interrupt flag clear register (DMA_IFCR)
 struct {
      unsigned int CGIF1: 1; // Channel 1 Global interrupt clear
      unsigned int CTCIF1: 1; // Channel 1 Transfer Complete clear
      unsigned int CHTIF1: 1; // Channel 1 Half Transfer clear
      unsigned int CTEIF1: 1; // Channel 1 Transfer Error clear
      unsigned int CGIF2: 1; // Channel 2 Global interrupt clear
      unsigned int CTCIF2: 1; // Channel 2 Transfer Complete clear
      unsigned int CHTIF2: 1; // Channel 2 Half Transfer clear
      unsigned int CTEIF2: 1; // Channel 2 Transfer Error clear
      unsigned int CGIF3: 1; // Channel 3 Global interrupt clear
      unsigned int CTCIF3: 1; // Channel 3 Transfer Complete clear
      unsigned int CHTIF3: 1; // Channel 3 Half Transfer clear
      unsigned int CTEIF3: 1; // Channel 3 Transfer Error clear
      unsigned int CGIF4: 1; // Channel 4 Global interrupt clear
      unsigned int CTCIF4: 1; // Channel 4 Transfer Complete clear
      unsigned int CHTIF4: 1; // Channel 4 Half Transfer clear
      unsigned int CTEIF4: 1; // Channel 4 Transfer Error clear
      unsigned int CGIF5: 1; // Channel 5 Global interrupt clear
      unsigned int CTCIF5: 1; // Channel 5 Transfer Complete clear
      unsigned int CHTIF5: 1; // Channel 5 Half Transfer clear
      unsigned int CTEIF5: 1; // Channel 5 Transfer Error clear
      unsigned int CGIF6: 1; // Channel 6 Global interrupt clear
      unsigned int CTCIF6: 1; // Channel 6 Transfer Complete clear
      unsigned int CHTIF6: 1; // Channel 6 Half Transfer clear
      unsigned int CTEIF6: 1; // Channel 6 Transfer Error clear
      unsigned int CGIF7: 1; // Channel 7 Global interrupt clear
      unsigned int CTCIF7: 1; // Channel 7 Transfer Complete clear
      unsigned int CHTIF7: 1; // Channel 7 Half Transfer clear
      unsigned int CTEIF7: 1; // Channel 7 Transfer Error clear
      unsigned int : 4; // Reserved
} IFCR;
// DMA channel configuration register (DMA_CCR)
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt enable
      unsigned int HTIE: 1; // Half Transfer interrupt enable
      unsigned int TEIE: 1; // Transfer error interrupt enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel Priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR1;
// DMA channel 1 number of data register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR1;
// DMA channel 1 peripheral address register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR1;
// DMA channel 1 memory address register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR1;
      unsigned int : 32; // Reserved
// DMA channel configuration register (DMA_CCR)
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt enable
      unsigned int HTIE: 1; // Half Transfer interrupt enable
      unsigned int TEIE: 1; // Transfer error interrupt enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel Priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR2;
// DMA channel 2 number of data register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR2;
// DMA channel 2 peripheral address register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR2;
// DMA channel 2 memory address register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR2;
      unsigned int : 32; // Reserved
// DMA channel configuration register (DMA_CCR)
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt enable
      unsigned int HTIE: 1; // Half Transfer interrupt enable
      unsigned int TEIE: 1; // Transfer error interrupt enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel Priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR3;
// DMA channel 3 number of data register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR3;
// DMA channel 3 peripheral address register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR3;
// DMA channel 3 memory address register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR3;
      unsigned int : 32; // Reserved
// DMA channel configuration register (DMA_CCR)
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt enable
      unsigned int HTIE: 1; // Half Transfer interrupt enable
      unsigned int TEIE: 1; // Transfer error interrupt enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel Priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR4;
// DMA channel 4 number of data register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR4;
// DMA channel 4 peripheral address register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR4;
// DMA channel 4 memory address register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR4;
      unsigned int : 32; // Reserved
// DMA channel configuration register (DMA_CCR)
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt enable
      unsigned int HTIE: 1; // Half Transfer interrupt enable
      unsigned int TEIE: 1; // Transfer error interrupt enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel Priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR5;
// DMA channel 5 number of data register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR5;
// DMA channel 5 peripheral address register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR5;
// DMA channel 5 memory address register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR5;
      unsigned int : 32; // Reserved
// DMA channel configuration register (DMA_CCR)
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt enable
      unsigned int HTIE: 1; // Half Transfer interrupt enable
      unsigned int TEIE: 1; // Transfer error interrupt enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel Priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR6;
// DMA channel 6 number of data register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR6;
// DMA channel 6 peripheral address register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR6;
// DMA channel 6 memory address register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR6;
      unsigned int : 32; // Reserved
// DMA channel configuration register (DMA_CCR)
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt enable
      unsigned int HTIE: 1; // Half Transfer interrupt enable
      unsigned int TEIE: 1; // Transfer error interrupt enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel Priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR7;
// DMA channel 7 number of data register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR7;
// DMA channel 7 peripheral address register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR7;
// DMA channel 7 memory address register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR7;
} SVD_DMA2;
asm(".equ SVD_DMA2, 0x40020400");
