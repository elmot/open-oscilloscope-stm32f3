// Debug support
 extern struct {
// MCU Device ID Code Register
 struct {
      unsigned int DEV_ID: 12; // Device Identifier
      unsigned int : 4; // Reserved
      unsigned int REV_ID: 16; // Revision Identifier
} IDCODE;
// Debug MCU Configuration Register
 struct {
      unsigned int DBG_SLEEP: 1; // Debug Sleep mode
      unsigned int DBG_STOP: 1; // Debug Stop Mode
      unsigned int DBG_STANDBY: 1; // Debug Standby Mode
      unsigned int : 2; // Reserved
      unsigned int TRACE_IOEN: 1; // Trace pin assignment control
      unsigned int TRACE_MODE: 2; // Trace pin assignment control
      unsigned int : 24; // Reserved
} CR;
// APB Low Freeze Register
 struct {
      unsigned int DBG_TIM2_STOP: 1; // Debug Timer 2 stopped when Core is halted
      unsigned int DBG_TIM3_STOP: 1; // Debug Timer 3 stopped when Core is halted
      unsigned int DBG_TIM4_STOP: 1; // Debug Timer 4 stopped when Core is halted
      unsigned int DBG_TIM5_STOP: 1; // Debug Timer 5 stopped when Core is halted
      unsigned int DBG_TIM6_STOP: 1; // Debug Timer 6 stopped when Core is halted
      unsigned int DBG_TIM7_STOP: 1; // Debug Timer 7 stopped when Core is halted
      unsigned int DBG_TIM12_STOP: 1; // Debug Timer 12 stopped when Core is halted
      unsigned int DBG_TIM13_STOP: 1; // Debug Timer 13 stopped when Core is halted
      unsigned int DBG_TIMER14_STOP: 1; // Debug Timer 14 stopped when Core is halted
      unsigned int DBG_TIM18_STOP: 1; // Debug Timer 18 stopped when Core is halted
      unsigned int DBG_RTC_STOP: 1; // Debug RTC stopped when Core is halted
      unsigned int DBG_WWDG_STOP: 1; // Debug Window Wachdog stopped when Core is halted
      unsigned int DBG_IWDG_STOP: 1; // Debug Independent Wachdog stopped when Core is halted
      unsigned int : 8; // Reserved
      unsigned int I2C1_SMBUS_TIMEOUT: 1; // SMBUS timeout mode stopped when Core is halted
      unsigned int I2C2_SMBUS_TIMEOUT: 1; // SMBUS timeout mode stopped when Core is halted
      unsigned int : 2; // Reserved
      unsigned int DBG_CAN_STOP: 1; // Debug CAN stopped when core is halted
      unsigned int : 6; // Reserved
} APB1FZ;
// APB High Freeze Register
 struct {
      unsigned int : 2; // Reserved
      unsigned int DBG_TIM15_STOP: 1; // Debug Timer 15 stopped when Core is halted
      unsigned int DBG_TIM16_STOP: 1; // Debug Timer 16 stopped when Core is halted
      unsigned int DBG_TIM17_STO: 1; // Debug Timer 17 stopped when Core is halted
      unsigned int DBG_TIM19_STOP: 1; // Debug Timer 19 stopped when Core is halted
      unsigned int : 26; // Reserved
} APB2FZ;
} SVD_DBGMCU __attribute__ ((packed));
asm(".equ SVD_DBGMCU, 0xe0042000");
