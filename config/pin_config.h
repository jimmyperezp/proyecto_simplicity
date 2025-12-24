#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[ACMP0]
// [ACMP0]$

// $[ACMP1]
// [ACMP1]$

// $[ADC0]
// [ADC0]$

// $[CMU]
// [CMU]$

// $[CSEN]
// [CSEN]$

// $[DBG]
// [DBG]$

// $[ETM]
// [ETM]$

// $[PTI]
// [PTI]$

// $[GPIO]
// [GPIO]$

// $[I2C0]
// [I2C0]$

// $[I2C1]
// [I2C1]$

// $[IDAC0]
// [IDAC0]$

// $[LESENSE]
// [LESENSE]$

// $[LETIMER0]
// [LETIMER0]$

// $[LEUART0]
// [LEUART0]$

// $[LFXO]
// [LFXO]$

// $[MODEM]
// [MODEM]$

// $[PCNT0]
// [PCNT0]$

// $[PCNT1]
// [PCNT1]$

// $[PCNT2]
// [PCNT2]$

// $[PRS.CH0]
// [PRS.CH0]$

// $[PRS.CH1]
// [PRS.CH1]$

// $[PRS.CH2]
// [PRS.CH2]$

// $[PRS.CH3]
// [PRS.CH3]$

// $[PRS.CH4]
// [PRS.CH4]$

// $[PRS.CH5]
// [PRS.CH5]$

// $[PRS.CH6]
// [PRS.CH6]$

// $[PRS.CH7]
// [PRS.CH7]$

// $[PRS.CH8]
// [PRS.CH8]$

// $[PRS.CH9]
// [PRS.CH9]$

// $[PRS.CH10]
// [PRS.CH10]$

// $[PRS.CH11]
// [PRS.CH11]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[USART0]
// USART0 CLK on PA2
#ifndef USART0_CLK_PORT                         
#define USART0_CLK_PORT                          gpioPortA
#endif
#ifndef USART0_CLK_PIN                          
#define USART0_CLK_PIN                           2
#endif
#ifndef USART0_CLK_LOC                          
#define USART0_CLK_LOC                           0
#endif

// USART0 CS on PB11
#ifndef USART0_CS_PORT                          
#define USART0_CS_PORT                           gpioPortB
#endif
#ifndef USART0_CS_PIN                           
#define USART0_CS_PIN                            11
#endif
#ifndef USART0_CS_LOC                           
#define USART0_CS_LOC                            3
#endif

// USART0 RX on PA4
#ifndef USART0_RX_PORT                          
#define USART0_RX_PORT                           gpioPortA
#endif
#ifndef USART0_RX_PIN                           
#define USART0_RX_PIN                            4
#endif
#ifndef USART0_RX_LOC                           
#define USART0_RX_LOC                            3
#endif

// USART0 TX on PA3
#ifndef USART0_TX_PORT                          
#define USART0_TX_PORT                           gpioPortA
#endif
#ifndef USART0_TX_PIN                           
#define USART0_TX_PIN                            3
#endif
#ifndef USART0_TX_LOC                           
#define USART0_TX_LOC                            3
#endif

// [USART0]$

// $[USART1]
// [USART1]$

// $[USART2]
// [USART2]$

// $[USART3]
// [USART3]$

// $[VDAC0]
// [VDAC0]$

// $[WTIMER0]
// [WTIMER0]$

// $[WTIMER1]
// [WTIMER1]$

// $[CUSTOM_PIN_NAME]
#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     0
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

