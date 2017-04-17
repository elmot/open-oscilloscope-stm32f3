// System configuration controller
 extern struct {
// configuration register 1
 struct {
      unsigned int MEM_MODE: 2; // Memory mapping selection bits
      unsigned int : 3; // Reserved
      unsigned int USB_IT_RMP: 1; // USB interrupt remap
      unsigned int TIM1_ITR_RMP: 1; // Timer 1 ITR3 selection
      unsigned int DAC_TRIG_RMP: 1; // DAC trigger remap (when TSEL = 001)
      unsigned int ADC24_DMA_RMP: 1; // ADC24 DMA remapping bit
      unsigned int : 2; // Reserved
      unsigned int TIM16_DMA_RMP: 1; // TIM16 DMA request remapping bit
      unsigned int TIM17_DMA_RMP: 1; // TIM17 DMA request remapping bit
      unsigned int TIM6_DAC1_DMA_RMP: 1; // TIM6 and DAC1 DMA request remapping bit
      unsigned int TIM7_DAC2_DMA_RMP: 1; // TIM7 and DAC2 DMA request remapping bit
      unsigned int : 1; // Reserved
      unsigned int I2C_PB6_FM: 1; // Fast Mode Plus (FM+) driving capability activation bits.
      unsigned int I2C_PB7_FM: 1; // Fast Mode Plus (FM+) driving capability activation bits.
      unsigned int I2C_PB8_FM: 1; // Fast Mode Plus (FM+) driving capability activation bits.
      unsigned int I2C_PB9_FM: 1; // Fast Mode Plus (FM+) driving capability activation bits.
      unsigned int I2C1_FM: 1; // I2C1 Fast Mode Plus
      unsigned int I2C2_FM: 1; // I2C2 Fast Mode Plus
      unsigned int ENCODER_MODE: 2; // Encoder mode
      unsigned int : 2; // Reserved
      unsigned int FPU_IT: 6; // Interrupt enable bits from FPU
} CFGR1;
// CCM SRAM protection register
 struct {
      unsigned int PAGE0_WP: 1; // CCM SRAM page write protection bit
      unsigned int PAGE1_WP: 1; // CCM SRAM page write protection bit
      unsigned int PAGE2_WP: 1; // CCM SRAM page write protection bit
      unsigned int PAGE3_WP: 1; // CCM SRAM page write protection bit
      unsigned int PAGE4_WP: 1; // CCM SRAM page write protection bit
      unsigned int PAGE5_WP: 1; // CCM SRAM page write protection bit
      unsigned int PAGE6_WP: 1; // CCM SRAM page write protection bit
      unsigned int PAGE7_WP: 1; // CCM SRAM page write protection bit
      unsigned int : 24; // Reserved
} RCR;
// external interrupt configuration register 1
 struct {
      unsigned int EXTI0: 4; // EXTI 0 configuration bits
      unsigned int EXTI1: 4; // EXTI 1 configuration bits
      unsigned int EXTI2: 4; // EXTI 2 configuration bits
      unsigned int EXTI3: 4; // EXTI 3 configuration bits
      unsigned int : 16; // Reserved
} EXTICR1;
// external interrupt configuration register 2
 struct {
      unsigned int EXTI4: 4; // EXTI 4 configuration bits
      unsigned int EXTI5: 4; // EXTI 5 configuration bits
      unsigned int EXTI6: 4; // EXTI 6 configuration bits
      unsigned int EXTI7: 4; // EXTI 7 configuration bits
      unsigned int : 16; // Reserved
} EXTICR2;
// external interrupt configuration register 3
 struct {
      unsigned int EXTI8: 4; // EXTI 8 configuration bits
      unsigned int EXTI9: 4; // EXTI 9 configuration bits
      unsigned int EXTI10: 4; // EXTI 10 configuration bits
      unsigned int EXTI11: 4; // EXTI 11 configuration bits
      unsigned int : 16; // Reserved
} EXTICR3;
// external interrupt configuration register 4
 struct {
      unsigned int EXTI12: 4; // EXTI 12 configuration bits
      unsigned int EXTI13: 4; // EXTI 13 configuration bits
      unsigned int EXTI14: 4; // EXTI 14 configuration bits
      unsigned int EXTI15: 4; // EXTI 15 configuration bits
      unsigned int : 16; // Reserved
} EXTICR4;
// configuration register 2
 struct {
      unsigned int LOCUP_LOCK: 1; // Cortex-M0 LOCKUP bit enable bit
      unsigned int SRAM_PARITY_LOCK: 1; // SRAM parity lock bit
      unsigned int PVD_LOCK: 1; // PVD lock enable bit
      unsigned int : 1; // Reserved
      unsigned int BYP_ADD_PAR: 1; // Bypass address bit 29 in parity calculation
      unsigned int : 3; // Reserved
      unsigned int SRAM_PEF: 1; // SRAM parity flag
      unsigned int : 23; // Reserved
} CFGR2;
} SVD_SYSCFG;
asm(".equ SVD_SYSCFG, 0x40010000");
