// Reset and clock control
 extern struct {
// Clock control register
 struct {
      unsigned int HSION: 1; // Internal High Speed clock enable
      unsigned int HSIRDY: 1; // Internal High Speed clock ready flag
      unsigned int : 1; // Reserved
      unsigned int HSITRIM: 5; // Internal High Speed clock trimming
      unsigned int HSICAL: 8; // Internal High Speed clock Calibration
      unsigned int HSEON: 1; // External High Speed clock enable
      unsigned int HSERDY: 1; // External High Speed clock ready flag
      unsigned int HSEBYP: 1; // External High Speed clock Bypass
      unsigned int CSSON: 1; // Clock Security System enable
      unsigned int : 4; // Reserved
      unsigned int PLLON: 1; // PLL enable
      unsigned int PLLRDY: 1; // PLL clock ready flag
      unsigned int : 6; // Reserved
} CR;
// Clock configuration register (RCC_CFGR)
 struct {
      unsigned int SW: 2; // System clock Switch
      unsigned int SWS: 2; // System Clock Switch Status
      unsigned int HPRE: 4; // AHB prescaler
      unsigned int PPRE1: 3; // APB Low speed prescaler (APB1)
      unsigned int PPRE2: 3; // APB high speed prescaler (APB2)
      unsigned int : 1; // Reserved
      unsigned int PLLSRC: 2; // PLL entry clock source
      unsigned int PLLXTPRE: 1; // HSE divider for PLL entry
      unsigned int PLLMUL: 4; // PLL Multiplication Factor
      unsigned int USBPRES: 1; // USB prescaler
      unsigned int I2SSRC: 1; // I2S external clock source selection
      unsigned int MCO: 3; // Microcontroller clock output
      unsigned int : 1; // Reserved
      unsigned int MCOF: 1; // Microcontroller Clock Output Flag
      unsigned int : 3; // Reserved
} CFGR;
// Clock interrupt register (RCC_CIR)
 struct {
      unsigned int LSIRDYF: 1; // LSI Ready Interrupt flag
      unsigned int LSERDYF: 1; // LSE Ready Interrupt flag
      unsigned int HSIRDYF: 1; // HSI Ready Interrupt flag
      unsigned int HSERDYF: 1; // HSE Ready Interrupt flag
      unsigned int PLLRDYF: 1; // PLL Ready Interrupt flag
      unsigned int : 2; // Reserved
      unsigned int CSSF: 1; // Clock Security System Interrupt flag
      unsigned int LSIRDYIE: 1; // LSI Ready Interrupt Enable
      unsigned int LSERDYIE: 1; // LSE Ready Interrupt Enable
      unsigned int HSIRDYIE: 1; // HSI Ready Interrupt Enable
      unsigned int HSERDYIE: 1; // HSE Ready Interrupt Enable
      unsigned int PLLRDYIE: 1; // PLL Ready Interrupt Enable
      unsigned int : 3; // Reserved
      unsigned int LSIRDYC: 1; // LSI Ready Interrupt Clear
      unsigned int LSERDYC: 1; // LSE Ready Interrupt Clear
      unsigned int HSIRDYC: 1; // HSI Ready Interrupt Clear
      unsigned int HSERDYC: 1; // HSE Ready Interrupt Clear
      unsigned int PLLRDYC: 1; // PLL Ready Interrupt Clear
      unsigned int : 2; // Reserved
      unsigned int CSSC: 1; // Clock security system interrupt clear
      unsigned int : 8; // Reserved
} CIR;
// APB2 peripheral reset register (RCC_APB2RSTR)
 struct {
      unsigned int SYSCFGRST: 1; // SYSCFG and COMP reset
      unsigned int : 10; // Reserved
      unsigned int TIM1RST: 1; // TIM1 timer reset
      unsigned int SPI1RST: 1; // SPI 1 reset
      unsigned int TIM8RST: 1; // TIM8 timer reset
      unsigned int USART1RST: 1; // USART1 reset
      unsigned int : 1; // Reserved
      unsigned int TIM15RST: 1; // TIM15 timer reset
      unsigned int TIM16RST: 1; // TIM16 timer reset
      unsigned int TIM17RST: 1; // TIM17 timer reset
      unsigned int : 13; // Reserved
} APB2RSTR;
// APB1 peripheral reset register (RCC_APB1RSTR)
 struct {
      unsigned int TIM2RST: 1; // Timer 2 reset
      unsigned int TIM3RST: 1; // Timer 3 reset
      unsigned int TIM4RST: 1; // Timer 14 reset
      unsigned int : 1; // Reserved
      unsigned int TIM6RST: 1; // Timer 6 reset
      unsigned int TIM7RST: 1; // Timer 7 reset
      unsigned int : 5; // Reserved
      unsigned int WWDGRST: 1; // Window watchdog reset
      unsigned int : 2; // Reserved
      unsigned int SPI2RST: 1; // SPI2 reset
      unsigned int SPI3RST: 1; // SPI3 reset
      unsigned int : 1; // Reserved
      unsigned int USART2RST: 1; // USART 2 reset
      unsigned int USART3RST: 1; // USART3 reset
      unsigned int UART4RST: 1; // UART 4 reset
      unsigned int UART5RST: 1; // UART 5 reset
      unsigned int I2C1RST: 1; // I2C1 reset
      unsigned int I2C2RST: 1; // I2C2 reset
      unsigned int USBRST: 1; // USB reset
      unsigned int : 1; // Reserved
      unsigned int CANRST: 1; // CAN reset
      unsigned int : 2; // Reserved
      unsigned int PWRRST: 1; // Power interface reset
      unsigned int DACRST: 1; // DAC interface reset
      unsigned int : 2; // Reserved
} APB1RSTR;
// AHB Peripheral Clock enable register (RCC_AHBENR)
 struct {
      unsigned int DMAEN: 1; // DMA1 clock enable
      unsigned int DMA2EN: 1; // DMA2 clock enable
      unsigned int SRAMEN: 1; // SRAM interface clock enable
      unsigned int : 1; // Reserved
      unsigned int FLITFEN: 1; // FLITF clock enable
      unsigned int : 1; // Reserved
      unsigned int CRCEN: 1; // CRC clock enable
      unsigned int : 10; // Reserved
      unsigned int IOPAEN: 1; // I/O port A clock enable
      unsigned int IOPBEN: 1; // I/O port B clock enable
      unsigned int IOPCEN: 1; // I/O port C clock enable
      unsigned int IOPDEN: 1; // I/O port D clock enable
      unsigned int IOPEEN: 1; // I/O port E clock enable
      unsigned int IOPFEN: 1; // I/O port F clock enable
      unsigned int : 1; // Reserved
      unsigned int TSCEN: 1; // Touch sensing controller clock enable
      unsigned int : 3; // Reserved
      unsigned int ADC12EN: 1; // ADC1 and ADC2 clock enable
      unsigned int ADC34EN: 1; // ADC3 and ADC4 clock enable
      unsigned int : 2; // Reserved
} AHBENR;
// APB2 peripheral clock enable register (RCC_APB2ENR)
 struct {
      unsigned int SYSCFGEN: 1; // SYSCFG clock enable
      unsigned int : 10; // Reserved
      unsigned int TIM1EN: 1; // TIM1 Timer clock enable
      unsigned int SPI1EN: 1; // SPI 1 clock enable
      unsigned int TIM8EN: 1; // TIM8 Timer clock enable
      unsigned int USART1EN: 1; // USART1 clock enable
      unsigned int : 1; // Reserved
      unsigned int TIM15EN: 1; // TIM15 timer clock enable
      unsigned int TIM16EN: 1; // TIM16 timer clock enable
      unsigned int TIM17EN: 1; // TIM17 timer clock enable
      unsigned int : 13; // Reserved
} APB2ENR;
// APB1 peripheral clock enable register (RCC_APB1ENR)
 struct {
      unsigned int TIM2EN: 1; // Timer 2 clock enable
      unsigned int TIM3EN: 1; // Timer 3 clock enable
      unsigned int TIM4EN: 1; // Timer 4 clock enable
      unsigned int : 1; // Reserved
      unsigned int TIM6EN: 1; // Timer 6 clock enable
      unsigned int TIM7EN: 1; // Timer 7 clock enable
      unsigned int : 5; // Reserved
      unsigned int WWDGEN: 1; // Window watchdog clock enable
      unsigned int : 2; // Reserved
      unsigned int SPI2EN: 1; // SPI 2 clock enable
      unsigned int SPI3EN: 1; // SPI 3 clock enable
      unsigned int : 1; // Reserved
      unsigned int USART2EN: 1; // USART 2 clock enable
      unsigned int : 3; // Reserved
      unsigned int I2C1EN: 1; // I2C 1 clock enable
      unsigned int I2C2EN: 1; // I2C 2 clock enable
      unsigned int USBEN: 1; // USB clock enable
      unsigned int : 1; // Reserved
      unsigned int CANEN: 1; // CAN clock enable
      unsigned int : 2; // Reserved
      unsigned int PWREN: 1; // Power interface clock enable
      unsigned int DACEN: 1; // DAC interface clock enable
      unsigned int : 2; // Reserved
} APB1ENR;
// Backup domain control register (RCC_BDCR)
 struct {
      unsigned int LSEON: 1; // External Low Speed oscillator enable
      unsigned int LSERDY: 1; // External Low Speed oscillator ready
      unsigned int LSEBYP: 1; // External Low Speed oscillator bypass
      unsigned int LSEDRV: 2; // LSE oscillator drive capability
      unsigned int : 3; // Reserved
      unsigned int RTCSEL: 2; // RTC clock source selection
      unsigned int : 5; // Reserved
      unsigned int RTCEN: 1; // RTC clock enable
      unsigned int BDRST: 1; // Backup domain software reset
      unsigned int : 15; // Reserved
} BDCR;
// Control/status register (RCC_CSR)
 struct {
      unsigned int LSION: 1; // Internal low speed oscillator enable
      unsigned int LSIRDY: 1; // Internal low speed oscillator ready
      unsigned int : 22; // Reserved
      unsigned int RMVF: 1; // Remove reset flag
      unsigned int OBLRSTF: 1; // Option byte loader reset flag
      unsigned int PINRSTF: 1; // PIN reset flag
      unsigned int PORRSTF: 1; // POR/PDR reset flag
      unsigned int SFTRSTF: 1; // Software reset flag
      unsigned int IWDGRSTF: 1; // Independent watchdog reset flag
      unsigned int WWDGRSTF: 1; // Window watchdog reset flag
      unsigned int LPWRRSTF: 1; // Low-power reset flag
} CSR;
// AHB peripheral reset register
 struct {
      unsigned int : 17; // Reserved
      unsigned int IOPARST: 1; // I/O port A reset
      unsigned int IOPBRST: 1; // I/O port B reset
      unsigned int IOPCRST: 1; // I/O port C reset
      unsigned int IOPDRST: 1; // I/O port D reset
      unsigned int IOPERST: 1; // I/O port E reset
      unsigned int IOPFRST: 1; // I/O port F reset
      unsigned int : 1; // Reserved
      unsigned int TSCRST: 1; // Touch sensing controller reset
      unsigned int : 3; // Reserved
      unsigned int ADC12RST: 1; // ADC1 and ADC2 reset
      unsigned int ADC34RST: 1; // ADC3 and ADC4 reset
      unsigned int : 2; // Reserved
} AHBRSTR;
// Clock configuration register 2
 struct {
      unsigned int PREDIV: 4; // PREDIV division factor
      unsigned int ADC12PRES: 5; // ADC1 and ADC2 prescaler
      unsigned int ADC34PRES: 5; // ADC3 and ADC4 prescaler
      unsigned int : 18; // Reserved
} CFGR2;
// Clock configuration register 3
 struct {
      unsigned int USART1SW: 2; // USART1 clock source selection
      unsigned int : 2; // Reserved
      unsigned int I2C1SW: 1; // I2C1 clock source selection
      unsigned int I2C2SW: 1; // I2C2 clock source selection
      unsigned int : 2; // Reserved
      unsigned int TIM1SW: 1; // Timer1 clock source selection
      unsigned int TIM8SW: 1; // Timer8 clock source selection
      unsigned int : 6; // Reserved
      unsigned int USART2SW: 2; // USART2 clock source selection
      unsigned int USART3SW: 2; // USART3 clock source selection
      unsigned int UART4SW: 2; // UART4 clock source selection
      unsigned int UART5SW: 2; // UART5 clock source selection
      unsigned int : 8; // Reserved
} CFGR3;
} SVD_RCC __attribute__ ((packed));
asm(".equ SVD_RCC, 0x40021000");
