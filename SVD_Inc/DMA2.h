// DMA1
 extern struct {
// ISR
 struct {
      unsigned int GIF1: 1; // GIF1
      unsigned int TCIF1: 1; // TCIF1
      unsigned int HTIF1: 1; // HTIF1
      unsigned int TEIF1: 1; // TEIF1
      unsigned int GIF2: 1; // GIF2
      unsigned int TCIF2: 1; // TCIF2
      unsigned int HTIF2: 1; // HTIF2
      unsigned int TEIF2: 1; // TEIF2
      unsigned int GIF3: 1; // GIF3
      unsigned int TCIF3: 1; // TCIF3
      unsigned int HTIF3: 1; // HTIF3
      unsigned int TEIF3: 1; // TEIF3
      unsigned int GIF4: 1; // GIF4
      unsigned int TCIF4: 1; // TCIF4
      unsigned int HTIF4: 1; // HTIF4
      unsigned int TEIF4: 1; // TEIF4
      unsigned int GIF5: 1; // GIF5
      unsigned int TCIF5: 1; // TCIF5
      unsigned int HTIF5: 1; // HTIF5
      unsigned int TEIF5: 1; // TEIF5
      unsigned int GIF6: 1; // GIF6
      unsigned int TCIF6: 1; // TCIF6
      unsigned int HTIF6: 1; // HTIF6
      unsigned int TEIF6: 1; // TEIF6
      unsigned int GIF7: 1; // GIF7
      unsigned int TCIF7: 1; // TCIF7
      unsigned int HTIF7: 1; // HTIF7
      unsigned int TEIF7: 1; // TEIF7
      unsigned int : 4; // Reserved
} ISR;
// IFCR
 struct {
      unsigned int CGIF1: 1; // CGIF1
      unsigned int CTCIF1: 1; // CTCIF1
      unsigned int CHTIF1: 1; // CHTIF1
      unsigned int CTEIF1: 1; // CTEIF1
      unsigned int CGIF2: 1; // CGIF2
      unsigned int CTCIF2: 1; // CTCIF2
      unsigned int CHTIF2: 1; // CHTIF2
      unsigned int CTEIF2: 1; // CTEIF2
      unsigned int CGIF3: 1; // CGIF3
      unsigned int CTCIF3: 1; // CTCIF3
      unsigned int CHTIF3: 1; // CHTIF3
      unsigned int CTEIF3: 1; // CTEIF3
      unsigned int CGIF4: 1; // CGIF4
      unsigned int CTCIF4: 1; // CTCIF4
      unsigned int CHTIF4: 1; // CHTIF4
      unsigned int CTEIF4: 1; // CTEIF4
      unsigned int CGIF5: 1; // CGIF5
      unsigned int CTCIF5: 1; // CTCIF5
      unsigned int CHTIF5: 1; // CHTIF5
      unsigned int CTEIF5: 1; // CTEIF5
      unsigned int CGIF6: 1; // CGIF6
      unsigned int CTCIF6: 1; // CTCIF6
      unsigned int CHTIF6: 1; // CHTIF6
      unsigned int CTEIF6: 1; // CTEIF6
      unsigned int CGIF7: 1; // CGIF7
      unsigned int CTCIF7: 1; // CTCIF7
      unsigned int CHTIF7: 1; // CHTIF7
      unsigned int CTEIF7: 1; // CTEIF7
      unsigned int : 4; // Reserved
} IFCR;
// CCR1
 struct {
      unsigned int EN: 1; // EN
      unsigned int TCIE: 1; // TCIE
      unsigned int HTIE: 1; // HTIE
      unsigned int TEIE: 1; // TEIE
      unsigned int DIR: 1; // DIR
      unsigned int CIRC: 1; // CIRC
      unsigned int PINC: 1; // PINC
      unsigned int MINC: 1; // MINC
      unsigned int PSIZE: 2; // PSIZE
      unsigned int MSIZE: 2; // MSIZE
      unsigned int PL: 2; // PL
      unsigned int MEM2MEM: 1; // MEM2MEM
      unsigned int : 17; // Reserved
} CCR1;
// CNDTR1
 struct {
      unsigned int NDT: 16; // NDT
      unsigned int : 16; // Reserved
} CNDTR1;
// CPAR1
 struct {
      unsigned int PA: 32; // PA
} CPAR1;
// CMAR1
 struct {
      unsigned int MA: 32; // MA
} CMAR1;
      unsigned int : 32; // Reserved
// CCR2
 struct {
      unsigned int EN: 1; // EN
      unsigned int TCIE: 1; // TCIE
      unsigned int HTIE: 1; // HTIE
      unsigned int TEIE: 1; // TEIE
      unsigned int DIR: 1; // DIR
      unsigned int CIRC: 1; // CIRC
      unsigned int PINC: 1; // PINC
      unsigned int MINC: 1; // MINC
      unsigned int PSIZE: 2; // PSIZE
      unsigned int MSIZE: 2; // MSIZE
      unsigned int PL: 2; // PL
      unsigned int MEM2MEM: 1; // MEM2MEM
      unsigned int : 17; // Reserved
} CCR2;
// CNDTR2
 struct {
      unsigned int NDT: 16; // NDT
      unsigned int : 16; // Reserved
} CNDTR2;
// CPAR2
 struct {
      unsigned int PA: 32; // PA
} CPAR2;
// CMAR2
 struct {
      unsigned int MA: 32; // MA
} CMAR2;
      unsigned int : 32; // Reserved
// CCR3
 struct {
      unsigned int EN: 1; // EN
      unsigned int TCIE: 1; // TCIE
      unsigned int HTIE: 1; // HTIE
      unsigned int TEIE: 1; // TEIE
      unsigned int DIR: 1; // DIR
      unsigned int CIRC: 1; // CIRC
      unsigned int PINC: 1; // PINC
      unsigned int MINC: 1; // MINC
      unsigned int PSIZE: 2; // PSIZE
      unsigned int MSIZE: 2; // MSIZE
      unsigned int PL: 2; // PL
      unsigned int MEM2MEM: 1; // MEM2MEM
      unsigned int : 17; // Reserved
} CCR3;
// CNDTR3
 struct {
      unsigned int NDT: 16; // NDT
      unsigned int : 16; // Reserved
} CNDTR3;
// CPAR3
 struct {
      unsigned int PA: 32; // PA
} CPAR3;
// CMAR3
 struct {
      unsigned int MA: 32; // MA
} CMAR3;
      unsigned int : 32; // Reserved
// CCR4
 struct {
      unsigned int EN: 1; // EN
      unsigned int TCIE: 1; // TCIE
      unsigned int HTIE: 1; // HTIE
      unsigned int TEIE: 1; // TEIE
      unsigned int DIR: 1; // DIR
      unsigned int CIRC: 1; // CIRC
      unsigned int PINC: 1; // PINC
      unsigned int MINC: 1; // MINC
      unsigned int PSIZE: 2; // PSIZE
      unsigned int MSIZE: 2; // MSIZE
      unsigned int PL: 2; // PL
      unsigned int MEM2MEM: 1; // MEM2MEM
      unsigned int : 17; // Reserved
} CCR4;
// CNDTR4
 struct {
      unsigned int NDT: 16; // NDT
      unsigned int : 16; // Reserved
} CNDTR4;
// CPAR4
 struct {
      unsigned int PA: 32; // PA
} CPAR4;
// CMAR4
 struct {
      unsigned int MA: 32; // MA
} CMAR4;
      unsigned int : 32; // Reserved
// CCR5
 struct {
      unsigned int EN: 1; // EN
      unsigned int TCIE: 1; // TCIE
      unsigned int HTIE: 1; // HTIE
      unsigned int TEIE: 1; // TEIE
      unsigned int DIR: 1; // DIR
      unsigned int CIRC: 1; // CIRC
      unsigned int PINC: 1; // PINC
      unsigned int MINC: 1; // MINC
      unsigned int PSIZE: 2; // PSIZE
      unsigned int MSIZE: 2; // MSIZE
      unsigned int PL: 2; // PL
      unsigned int MEM2MEM: 1; // MEM2MEM
      unsigned int : 17; // Reserved
} CCR5;
// CNDTR5
 struct {
      unsigned int NDT: 16; // NDT
      unsigned int : 16; // Reserved
} CNDTR5;
// CPAR5
 struct {
      unsigned int PA: 32; // PA
} CPAR5;
// CMAR5
 struct {
      unsigned int MA: 32; // MA
} CMAR5;
      unsigned int : 32; // Reserved
// CCR6
 struct {
      unsigned int EN: 1; // EN
      unsigned int TCIE: 1; // TCIE
      unsigned int HTIE: 1; // HTIE
      unsigned int TEIE: 1; // TEIE
      unsigned int DIR: 1; // DIR
      unsigned int CIRC: 1; // CIRC
      unsigned int PINC: 1; // PINC
      unsigned int MINC: 1; // MINC
      unsigned int PSIZE: 2; // PSIZE
      unsigned int MSIZE: 2; // MSIZE
      unsigned int PL: 2; // PL
      unsigned int MEM2MEM: 1; // MEM2MEM
      unsigned int : 17; // Reserved
} CCR6;
// CNDTR6
 struct {
      unsigned int NDT: 16; // NDT
      unsigned int : 16; // Reserved
} CNDTR6;
// CPAR6
 struct {
      unsigned int PA: 32; // PA
} CPAR6;
// CMAR6
 struct {
      unsigned int MA: 32; // MA
} CMAR6;
      unsigned int : 32; // Reserved
// CCR7
 struct {
      unsigned int EN: 1; // EN
      unsigned int TCIE: 1; // TCIE
      unsigned int HTIE: 1; // HTIE
      unsigned int TEIE: 1; // TEIE
      unsigned int DIR: 1; // DIR
      unsigned int CIRC: 1; // CIRC
      unsigned int PINC: 1; // PINC
      unsigned int MINC: 1; // MINC
      unsigned int PSIZE: 2; // PSIZE
      unsigned int MSIZE: 2; // MSIZE
      unsigned int PL: 2; // PL
      unsigned int MEM2MEM: 1; // MEM2MEM
      unsigned int : 17; // Reserved
} CCR7;
// CNDTR7
 struct {
      unsigned int NDT: 16; // NDT
      unsigned int : 16; // Reserved
} CNDTR7;
// CPAR7
 struct {
      unsigned int PA: 32; // PA
} CPAR7;
// CMAR7
 struct {
      unsigned int MA: 32; // MA
} CMAR7;
} SVD_DMA2 __attribute__ ((packed));
asm(".equ SVD_DMA2, 0x40020400");
