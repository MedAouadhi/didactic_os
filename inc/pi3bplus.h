/**
 * @file pi3bplus.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "types.h"

#define SYSCLK    250000000
#define BIT(x)  (1 << x)

#ifndef __IM                                    /*!< Fallback for older CMSIS versions                                         */
  #define __IM   volatile
#endif
#ifndef __OM                                    /*!< Fallback for older CMSIS versions                                         */
  #define __OM   volatile
#endif
#ifndef __IOM                                   /*!< Fallback for older CMSIS versions                                         */
  #define __IOM  volatile
#endif


typedef enum {
/* =======================================  ARM Cortex-A53 Specific Interrupt Numbers  ======================================= */
/* ========================================  bcm2837_lpa Specific Interrupt Numbers  ========================================= */
  TIMER_0_IRQn              =   0,              /*!< 0  Timer 0 matched                                                        */
  TIMER_1_IRQn              =   1,              /*!< 1  Timer 1 matched                                                        */
  TIMER_2_IRQn              =   2,              /*!< 2  Timer 2 matched                                                        */
  TIMER_3_IRQn              =   3,              /*!< 3  Timer 3 matched                                                        */
  USB_IRQn                  =   9,              /*!< 9  USB interrupt                                                          */
  AUX_IRQn                  =  29,              /*!< 29 Interrupt from AUX                                                     */
  GPIO0_IRQn                =  49,              /*!< 49 Interrupt from bank 0                                                  */
  GPIO1_IRQn                =  50,              /*!< 50 Interrupt from bank 1                                                  */
  GPIO2_IRQn                =  51,              /*!< 51 Interrupt from bank 2                                                  */
  GPIO_IRQn                 =  52,              /*!< 52 OR of all GPIO interrupts                                              */
  I2C_IRQn                  =  53,              /*!< 53 OR of all I2C interrupts                                               */
  SPI_IRQn                  =  54,              /*!< 54 OR of all SPI interrupts except 1 and 2                                */
  UART_IRQn                 =  57,              /*!< 57 OR of all UART interrupts except 1                                     */
  EMMC_IRQn                 =  62               /*!< 62 OR of EMMC and EMMC2                                                   */
} IRQn_Type;

/* =========================================================================================================================== */
/* ================                                           GPIO                                            ================ */
/* =========================================================================================================================== */




/**
  * @brief Pin level and mux control (GPIO)
  */

typedef struct {                                /*!< (@ 0x3F200000) GPIO Structure                                             */
  /* 0x00 */ volatile uint32_t GPFSEL0; /* GPIO Function Select 0 */ 
  /* 0x04 */ volatile uint32_t GPFSEL1; /* GPIO Function Select 1 */
  /* 0x08 */ volatile uint32_t GPFSEL2; /* GPIO Function Select 2 */
  /* 0x0c */ volatile uint32_t GPFSEL3; /* GPIO Function Select 3 */
  /* 0x10 */ volatile uint32_t GPFSEL4; /* GPIO Function Select 4 */
  /* 0x14 */ volatile uint32_t GPFSEL5; /* GPIO Function Select 5 */
                      uint32_t reserved;
  /* 0x1c */ volatile uint32_t GPSET0; /* GPIO Pin Output Set 0 */
  /* 0x20 */ volatile uint32_t GPSET1; /* GPIO Pin Output Set 1 */
                      uint32_t reserved1;
  /* 0x28 */ volatile uint32_t GPCLR0; /* GPIO Pin Output Clear 0 */
  /* 0x2c */ volatile uint32_t GPCLR1; /* GPIO Pin Output Clear 1 */
                      uint32_t reserved2;
  /* 0x34 */ volatile uint32_t GPLEV0; /* GPIO Pin Level 0 */
  /* 0x38 */ volatile uint32_t GPLEV1; /* GPIO Pin Level 1 */
  /* 0x40 */ volatile uint32_t GPEDS0; /* GPIO Pin Event Detect Status 0 */
  /* 0x44 */ volatile uint32_t GPEDS1; /* GPIO Pin Event Detect Status 1 */
  /* 0x4c */ volatile uint32_t GPREN0; /* GPIO Pin Rising Edge Detect Enable 0 */
  /* 0x50 */ volatile uint32_t GPREN1; /* GPIO Pin Rising Edge Detect Enable 1 */
                      uint32_t reserved3;
  /* 0x58 */ volatile uint32_t GPFEN0; /* GPIO Pin Falling Edge Detect Enable 0 */
  /* 0x5c */ volatile uint32_t GPFEN1; /* GPIO Pin Falling Edge Detect Enable 1 */
                      uint32_t reserved4;
  /* 0x64 */ volatile uint32_t GPHEN0; /* GPIO Pin High Detect Enable 0 */
  /* 0x68 */ volatile uint32_t GPHEN1; /* GPIO Pin High Detect Enable 1 */
                      uint32_t reserved5;
  /* 0x70 */ volatile uint32_t GPLEN0; /* GPIO Pin Low Detect Enable 0 */
  /* 0x74 */ volatile uint32_t GPLEN1; /* GPIO Pin Low Detect Enable 1 */
                      uint32_t reserved6[2];
  /* 0x7c */ volatile uint32_t GPAREN0; /* GPIO Pin Async. Rising Edge Detect 0 */
  /* 0x80 */ volatile uint32_t GPAREN1; /* GPIO Pin Async. Rising Edge Detect 1 */
                      uint32_t reserved7;
  /* 0x88 */ volatile uint32_t GPAFEN0; /* GPIO Pin Async. Falling Edge Detect 0 */
  /* 0x8c */ volatile uint32_t GPAFEN1; /* GPIO Pin Async. Falling Edge Detect 1 */
                      uint32_t reserved8;
  /* 0x94 */ volatile uint32_t GPPUD;  /* GPIO Pin Pull-up/down Enable */
  /* 0098 */ volatile uint32_t GPPUDCLK0; /* GPIO Pin Pull-up/down Enable Clock 0 */
  /* 009C */ volatile uint32_t GPPUDCLK1; /* GPIO Pin Pull-up/down Enable Clock 1 */
} GPIO_Type;                                    /*!< Size = 244 (0xf4)                                                         */


/* =========================================================================================================================== */
/* ================                                           UART1                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Mini UART (UART1)
  */

typedef struct {                                /*!< (@ 0x3F215000) UART1 Structure                                            */
/* 0x00 */ volatile uint32_t AUX_IRQ; /* Auxiliary Interrupt status */
/* 0x04 */ volatile uint32_t AUX_ENABLES; /* Auxiliary enables */
                    uint32_t reserved[14];
/* 0x40 */ volatile uint32_t AUX_MU_IO_REG;  /* Mini UART I/O Data */
/* 0x44 */ volatile uint32_t AUX_MU_IER_REG; /* Mini UART Interrupt Enable */
/* 0x48 */ volatile uint32_t AUX_MU_IIR_REG; /* Mini UART Interrupt Identify */
/* 0x4c */ volatile uint32_t AUX_MU_LCR_REG; /* Mini UART Line Control */
/* 0x50 */ volatile uint32_t AUX_MU_MCR_REG; /* Mini UART Modem Control */
/* 0x54 */ volatile uint32_t AUX_MU_LSR_REG; /* Mini UART Line Status */
/* 0x58 */ volatile uint32_t AUX_MU_MSR_REG; /* Mini UART Modem Status */
/* 0x5c */ volatile uint32_t AUX_MU_SCRATCH; /* Mini UART Scratch */
/* 0x60 */ volatile uint32_t AUX_MU_CNTL_REG; /* Mini UART Extra Control */
/* 0x64 */ volatile uint32_t AUX_MU_STAT_REG; /* Mini UART Extra Status */
/* 0x68 */ volatile uint32_t AUX_MU_BAUD_REG; /* Mini UART Baudrate */
} UART1_Type;                                   /*!< Size = 44 (0x2c)                                                          */


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define VCMAILBOX_BASE              0x3F00B880UL
#define CM_PCM_BASE                 0x3F101098UL
#define CM_PWM_BASE                 0x3F1010A0UL
#define GPIO_BASE                   0x3F200000UL
#define SYSTMR_BASE                 0x3F003000UL
#define UART0_BASE                  0x3F201000UL
#define SPI0_BASE                   0x3F204000UL
#define BSC0_BASE                   0x3F205000UL
#define PWM0_BASE                   0x3F20C000UL
#define BSC1_BASE                   0x3F804000UL
#define BSC2_BASE                   0x3F805000UL
#define AUX_BASE                    0x3F215000UL
#define UART1_BASE                  0x3F215040UL
#define SPI1_BASE                   0x3F215080UL
#define SPI2_BASE                   0x3F2150C0UL
#define LIC_BASE                    0x3F00B000UL
#define USB_OTG_GLOBAL_BASE         0x3F980000UL
#define USB_OTG_HOST_BASE           0x3F980400UL
#define USB_OTG_DEVICE_BASE         0x3F980800UL
#define USB_OTG_PWRCLK_BASE         0x3F980E00UL
#define EMMC_BASE                   0x3F300000UL

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


// #define VCMAILBOX                   ((VCMAILBOX_Type*)         VCMAILBOX_BASE)
// #define CM_PCM                      ((CM_PCM_Type*)            CM_PCM_BASE)
// #define CM_PWM                      ((CM_PCM_Type*)            CM_PWM_BASE)
#define GPIO                        ((GPIO_Type*)              GPIO_BASE)
// #define SYSTMR                      ((SYSTMR_Type*)            SYSTMR_BASE)
#define UART0                       ((ARM_UART_PL011_Type*)    UART0_BASE)
// #define SPI0                        ((SPI0_Type*)              SPI0_BASE)
// #define BSC0                        ((BSC0_Type*)              BSC0_BASE)
// #define PWM0                        ((PWM0_Type*)              PWM0_BASE)
// #define BSC1                        ((BSC0_Type*)              BSC1_BASE)
// #define BSC2                        ((BSC0_Type*)              BSC2_BASE)
// #define AUX                         ((AUX_Type*)               AUX_BASE)
#define UART1                       ((UART1_Type*)             AUX_BASE)
// #define SPI1                        ((SPI1_Type*)              SPI1_BASE)
// #define SPI2                        ((SPI1_Type*)              SPI2_BASE)
// #define LIC                         ((BCM_LIC_Type*)           LIC_BASE)
// #define USB_OTG_GLOBAL              ((USB_OTG_GLOBAL_Type*)    USB_OTG_GLOBAL_BASE)
// #define USB_OTG_HOST                ((USB_OTG_HOST_Type*)      USB_OTG_HOST_BASE)
// #define USB_OTG_DEVICE              ((USB_OTG_DEVICE_Type*)    USB_OTG_DEVICE_BASE)
// #define USB_OTG_PWRCLK              ((USB_OTG_PWRCLK_Type*)    USB_OTG_PWRCLK_BASE)
// #define EMMC                        ((Arasan_EMMC_Distributor_Type*)  EMMC_BASE)

/* End of group Device_Peripheral_declaration */