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

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long  uint64_t;
typedef int bool;

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
                      uint32_t reserved8[22];
  /* 0xe4 */ volatile uint32_t GPIO_PUP_PDN_CNTRL_REG0; /* GPIO Pull-up / Pull-down Register 0 */
  /* 0xe8 */ volatile uint32_t GPIO_PUP_PDN_CNTRL_REG1; /* GPIO Pull-up / Pull-down Register 1 */
  /* 0xec */ volatile uint32_t GPIO_PUP_PDN_CNTRL_REG2; /* GPIO Pull-up / Pull-down Register 2 */
  /* 0xf0 */ volatile uint32_t GPIO_PUP_PDN_CNTRL_REG3; /* GPIO Pull-up / Pull-down Register 3 */
} GPIO_Type;                                    /*!< Size = 244 (0xf4)                                                         */


/* =========================================================================================================================== */
/* ================                                           UART0                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief ARM Prime Cell PL011 (UART0)
  */

typedef struct {                                /*!< (@ 0x3F201000) UART0 Structure                                            */
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000000) Data Register                                              */
    
    struct {
      __IOM uint32_t DATA       : 8;            /*!< [7..0] DATA                                                               */
      __IOM uint32_t FE         : 1;            /*!< [8..8] FE                                                                 */
      __IOM uint32_t PE         : 1;            /*!< [9..9] PE                                                                 */
      __IOM uint32_t BE         : 1;            /*!< [10..10] BE                                                               */
      __IOM uint32_t OE         : 1;            /*!< [11..11] OE                                                               */
            uint32_t  reserved          : 20;
    } bit;
  } DR;
  
  union {
    union {
      __IM  uint32_t reg;                       /*!< (@ 0x00000004) Receive Status Register                                    */
      
      struct {
        __IM  uint32_t FE       : 1;            /*!< [0..0] FE                                                                 */
        __IM  uint32_t PE       : 1;            /*!< [1..1] PE                                                                 */
        __IM  uint32_t BE       : 1;            /*!< [2..2] BE                                                                 */
        __IM  uint32_t OE       : 1;            /*!< [3..3] OE                                                                 */
              uint32_t reserved          : 28;
      } bit;
    } RSR;
    
    union {
      __OM  uint32_t reg;                       /*!< (@ 0x00000004) Error Clear Register                                       */
      
      struct {
        __OM  uint32_t FE       : 1;            /*!< [0..0] FE                                                                 */
        __OM  uint32_t PE       : 1;            /*!< [1..1] PE                                                                 */
        __OM  uint32_t BE       : 1;            /*!< [2..2] BE                                                                 */
        __OM  uint32_t OE       : 1;            /*!< [3..3] OE                                                                 */
              uint32_t reserved         : 28;
      } bit;
    } ECR;
  };
  __IM  uint32_t  RESERVED[4];
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000018) Flag Register                                              */
    
    struct {
      __IOM uint32_t CTS        : 1;            /*!< [0..0] CTS                                                                */
      __IOM uint32_t DSR        : 1;            /*!< [1..1] DSR                                                                */
      __IOM uint32_t DCD        : 1;            /*!< [2..2] DCD                                                                */
      __IOM uint32_t BUSY       : 1;            /*!< [3..3] BUSY                                                               */
      __IOM uint32_t RXFE       : 1;            /*!< [4..4] RXFE                                                               */
      __IOM uint32_t TXFF       : 1;            /*!< [5..5] TXFF                                                               */
      __IOM uint32_t RXFF       : 1;            /*!< [6..6] RXFF                                                               */
      __IOM uint32_t TXFE       : 1;            /*!< [7..7] TXFE                                                               */
      __IOM uint32_t RI         : 1;            /*!< [8..8] RI                                                                 */
            uint32_t reserved           : 23;
    } bit;
  } FR;
  __IM  uint32_t  RESERVED1[2];
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000024) Integer Baud Rate Register                                 */
    
    struct {
      __IOM uint32_t BAUDDIVINT : 16;           /*!< [15..0] BAUDDIVINT                                                        */
            uint32_t reserved           : 16;
    } bit;
  } IBRD;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000028) Fractional Baud Rate Register                              */
    
    struct {
      __IOM uint32_t BAUDDIVFRAC : 6;           /*!< [5..0] BAUDDIVFRAC                                                        */
            uint32_t reserved            : 26;
    } bit;
  } FBRD;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x0000002C) Line Control Register                                      */
    
    struct {
      __IOM uint32_t BRK        : 1;            /*!< [0..0] BRK                                                                */
      __IOM uint32_t PEN        : 1;            /*!< [1..1] PEN                                                                */
      __IOM uint32_t EPS        : 1;            /*!< [2..2] EPS                                                                */
      __IOM uint32_t STP2       : 1;            /*!< [3..3] STP2                                                               */
      __IOM uint32_t FEN        : 1;            /*!< [4..4] FEN                                                                */
      __IOM uint32_t WLEN       : 2;            /*!< [6..5] WLEN                                                               */
      __IOM uint32_t SPS        : 1;            /*!< [7..7] SPS                                                                */
            uint32_t reserved           : 24;
    } bit;
  } LCR_H;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000030) Control Register                                           */
    
    struct {
      __IOM uint32_t UARTEN     : 1;            /*!< [0..0] UARTEN                                                             */
      __IOM uint32_t SIREN      : 1;            /*!< [1..1] SIREN                                                              */
      __IOM uint32_t SIRLP      : 1;            /*!< [2..2] SIRLP                                                              */
            uint32_t reserved           : 5;
      __IOM uint32_t TXE        : 1;            /*!< [8..8] TXE                                                                */
      __IOM uint32_t RXE        : 1;            /*!< [9..9] RXE                                                                */
      __IOM uint32_t DTR        : 1;            /*!< [10..10] DTR                                                              */
      __IOM uint32_t RTS        : 1;            /*!< [11..11] RTS                                                              */
            uint32_t reserved1           : 2;
      __IOM uint32_t RTSEN      : 1;            /*!< [14..14] RTSEN                                                            */
      __IOM uint32_t CTSEN      : 1;            /*!< [15..15] CTSEN                                                            */
            uint32_t reserved2           : 16;
    } bit;
  } CR;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000034) Interrupt FIFO Level Select Register                       */
    
    struct {
      __IOM uint32_t TXIFLSEL   : 3;            /*!< [2..0] TXIFLSEL                                                           */
      __IOM uint32_t RXIFLSEL   : 3;            /*!< [5..3] RXIFLSEL                                                           */
            uint32_t reserved           : 26;
    } bit;
  } IFLS;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000038) Interrupt Mask set_Clear Register                          */
    
    struct {
      __IOM uint32_t RIMIM      : 1;            /*!< [0..0] RIMIM                                                              */
      __IOM uint32_t CTSMIM     : 1;            /*!< [1..1] CTSMIM                                                             */
      __IOM uint32_t DCDMIM     : 1;            /*!< [2..2] DCDMIM                                                             */
      __IOM uint32_t DSRMIM     : 1;            /*!< [3..3] DSRMIM                                                             */
      __IOM uint32_t RXIM       : 1;            /*!< [4..4] RXIM                                                               */
      __IOM uint32_t TXIM       : 1;            /*!< [5..5] TXIM                                                               */
      __IOM uint32_t RTIM       : 1;            /*!< [6..6] RTIM                                                               */
      __IOM uint32_t FEIM       : 1;            /*!< [7..7] FEIM                                                               */
      __IOM uint32_t PEIM       : 1;            /*!< [8..8] PEIM                                                               */
      __IOM uint32_t BEIM       : 1;            /*!< [9..9] BEIM                                                               */
      __IOM uint32_t OEIM       : 1;            /*!< [10..10] OEIM                                                             */
            uint32_t reserved           : 21;
    } bit;
  } IMSC;
  
  union {
    __IM  uint32_t reg;                         /*!< (@ 0x0000003C) Raw Interrupt Status Register                              */
    
    struct {
      __IM  uint32_t RIRMIS     : 1;            /*!< [0..0] RIRMIS                                                             */
      __IM  uint32_t CTSRMIS    : 1;            /*!< [1..1] CTSRMIS                                                            */
      __IM  uint32_t DCDRMIS    : 1;            /*!< [2..2] DCDRMIS                                                            */
      __IM  uint32_t DSRRMIS    : 1;            /*!< [3..3] DSRRMIS                                                            */
      __IM  uint32_t RXRIS      : 1;            /*!< [4..4] RXRIS                                                              */
      __IM  uint32_t TXRIS      : 1;            /*!< [5..5] TXRIS                                                              */
      __IM  uint32_t RTRIS      : 1;            /*!< [6..6] RTRIS                                                              */
      __IM  uint32_t FERIS      : 1;            /*!< [7..7] FERIS                                                              */
      __IM  uint32_t PERIS      : 1;            /*!< [8..8] PERIS                                                              */
      __IM  uint32_t BERIS      : 1;            /*!< [9..9] BERIS                                                              */
      __IM  uint32_t OERIS      : 1;            /*!< [10..10] OERIS                                                            */
            uint32_t reserved           : 21;
    } bit;
  } RIS;
  
  union {
    __IM  uint32_t reg;                         /*!< (@ 0x00000040) Masked Interrupt Status Register                           */
    
    struct {
      __IM  uint32_t RIMMIS     : 1;            /*!< [0..0] RIMMIS                                                             */
      __IM  uint32_t CTSMMIS    : 1;            /*!< [1..1] CTSMMIS                                                            */
      __IM  uint32_t DCDMMIS    : 1;            /*!< [2..2] DCDMMIS                                                            */
      __IM  uint32_t DSRMMIS    : 1;            /*!< [3..3] DSRMMIS                                                            */
      __IM  uint32_t RXMIS      : 1;            /*!< [4..4] RXMIS                                                              */
      __IM  uint32_t TXMIS      : 1;            /*!< [5..5] TXMIS                                                              */
      __IM  uint32_t RTMIS      : 1;            /*!< [6..6] RTMIS                                                              */
      __IM  uint32_t FEMIS      : 1;            /*!< [7..7] FEMIS                                                              */
      __IM  uint32_t PEMIS      : 1;            /*!< [8..8] PEMIS                                                              */
      __IM  uint32_t BEMIS      : 1;            /*!< [9..9] BEMIS                                                              */
      __IM  uint32_t OEMIS      : 1;            /*!< [10..10] OEMIS                                                            */
            uint32_t reserved           : 21;
    } bit;
  } MIS;
  
  union {
    __OM  uint32_t reg;                         /*!< (@ 0x00000044) Interrupt Clear Register                                   */
    
    struct {
      __OM  uint32_t RIMIC      : 1;            /*!< [0..0] RIMIC                                                              */
      __OM  uint32_t CTSMIC     : 1;            /*!< [1..1] CTSMIC                                                             */
      __OM  uint32_t DCDMIC     : 1;            /*!< [2..2] DCDMIC                                                             */
      __OM  uint32_t DSRMIC     : 1;            /*!< [3..3] DSRMIC                                                             */
      __OM  uint32_t RXIC       : 1;            /*!< [4..4] RXIC                                                               */
      __OM  uint32_t TXIC       : 1;            /*!< [5..5] TXIC                                                               */
      __OM  uint32_t RTIC       : 1;            /*!< [6..6] RTIC                                                               */
      __OM  uint32_t FEIC       : 1;            /*!< [7..7] FEIC                                                               */
      __OM  uint32_t PEIC       : 1;            /*!< [8..8] PEIC                                                               */
      __OM  uint32_t BEIC       : 1;            /*!< [9..9] BEIC                                                               */
      __OM  uint32_t OEIC       : 1;            /*!< [10..10] OEIC                                                             */
            uint32_t reserved           : 21;
    } bit;
  } ICR;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000048) DMA Control Register                                       */
    
    struct {
      __IOM uint32_t RXDMAE     : 1;            /*!< [0..0] RXDMAE                                                             */
      __IOM uint32_t TXDMAE     : 1;            /*!< [1..1] TXDMAE                                                             */
      __IOM uint32_t DMAONERR   : 1;            /*!< [2..2] DMAONERR                                                           */
            uint32_t reserved           : 29;
    } bit;
  } DMACR;
} ARM_UART_PL011_Type;                          /*!< Size = 76 (0x4c)                                                          */

/* =========================================================================================================================== */
/* ================                                           UART1                                           ================ */
/* =========================================================================================================================== */


/**
  * @brief Mini UART (UART1)
  */

typedef struct {                                /*!< (@ 0x3F215040) UART1 Structure                                            */
  
  union {
    union {
      __IOM uint32_t reg;                       /*!< (@ 0x00000000) I/O Data                                                   */
      
      struct {
        __IOM uint32_t DATA     : 8;            /*!< [7..0] FIFO access                                                        */
              uint32_t reserved         : 24;
      } bit;
    } IO;
    __IOM uint8_t BAUDL;                        /*!< (@ 0x00000000) Lower bits of baudrate when DLAB is set                    */
  };
  
  union {
    union {
      __IOM uint32_t reg;                       /*!< (@ 0x00000004) Interrupt Enable                                           */
      
      struct {
        __IOM uint32_t DATA_READY : 1;          /*!< [0..0] Receive FIFO has at least 1 byte                                   */
        __IOM uint32_t TX_READY : 1;            /*!< [1..1] Transmit FIFO is empty                                             */
              uint32_t          : 30;
      } bit;
    } IER;
    __IOM uint8_t BAUDH;                        /*!< (@ 0x00000004) High bits of baudrate when DLAB is set                     */
  };
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000008) Interrupt Identify                                         */
    
    struct {
      __IOM uint32_t nPENDING   : 1;            /*!< [0..0] No pending interrupt                                               */
      __IOM uint32_t DATA_READY : 1;            /*!< [1..1] Receive FIFO has at least 1 byte                                   */
      __IOM uint32_t TX_READY   : 1;            /*!< [2..2] Transmit FIFO is empty                                             */
            uint32_t            : 29;
    } bit;
  } IIR;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x0000000C) Line control                                               */
    
    struct {
      __IOM uint32_t DATA_SIZE  : 2;            /*!< [1..0] UART word size                                                     */
            uint32_t            : 4;
      __IOM uint32_t BREAK      : 1;            /*!< [6..6] Pull TX low continuously to send break                             */
      __IOM uint32_t DLAB       : 1;            /*!< [7..7] First two registers are baudrate                                   */
            uint32_t            : 24;
    } bit;
  } LCR;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000010) Modem Control                                              */
    
    struct {
            uint32_t            : 1;
      __IOM uint32_t RTS        : 1;            /*!< [1..1] RTS is low                                                         */
            uint32_t            : 30;
    } bit;
  } MCR;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000014) Line Status                                                */
    
    struct {
      __IOM uint32_t DATA_READY : 1;            /*!< [0..0] Receive FIFO has at least one byte                                 */
      __IOM uint32_t RX_OVERRUN : 1;            /*!< [1..1] Receive FIFO overrun                                               */
            uint32_t            : 3;
      __IOM uint32_t TX_EMPTY   : 1;            /*!< [5..5] Transmit FIFO has room for at least one byte                       */
      __IOM uint32_t TX_IDLE    : 1;            /*!< [6..6] Transmit FIFO empty and all bits shifted out                       */
            uint32_t            : 25;
    } bit;
  } LSR;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000018) Modem Status                                               */
    
    struct {
            uint32_t            : 4;
      __IOM uint32_t CTS        : 1;            /*!< [4..4] CTS is low                                                         */
            uint32_t            : 27;
    } bit;
  } MSR;
  __IOM uint8_t   SCRATCH;                      /*!< (@ 0x0000001C) Scratch                                                    */
  __IM  uint8_t   RESERVED;
  __IM  uint16_t  RESERVED1;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000020) Control                                                    */
    
    struct {
      __IOM uint32_t RX_ENABLE  : 1;            /*!< [0..0] Enable receive                                                     */
      __IOM uint32_t TX_ENABLE  : 1;            /*!< [1..1] Enable transmit                                                    */
      __IOM uint32_t RTS_ENABLE : 1;            /*!< [2..2] Enable auto receive flow control with RTS                          */
      __IOM uint32_t CTS_ENABLE : 1;            /*!< [3..3] Enable auto transmit flow control with CTS                         */
      __IOM uint32_t RTS_FIFO_LEVEL : 2;        /*!< [5..4] FIFO level to de-assert RTS                                        */
      __IOM uint32_t RTS_ASSERT : 1;            /*!< [6..6] RTS assert level                                                   */
      __IOM uint32_t CTS_ASSERT : 1;            /*!< [7..7] CTS assert level                                                   */
            uint32_t            : 24;
    } bit;
  } CNTL;
  
  union {
    __IOM uint32_t reg;                         /*!< (@ 0x00000024) Status                                                     */
    
    struct {
      __IOM uint32_t DATA_READY : 1;            /*!< [0..0] Receive FIFO has at least one symbol                               */
      __IOM uint32_t TX_READY   : 1;            /*!< [1..1] Transmit FIFO has space for at least one symbol                    */
      __IOM uint32_t RX_IDLE    : 1;            /*!< [2..2] Receiver is idle                                                   */
      __IOM uint32_t TX_IDLE    : 1;            /*!< [3..3] Transmitter is idle                                                */
      __IOM uint32_t RX_OVERRUN : 1;            /*!< [4..4] Receive FIFO overrun                                               */
      __IOM uint32_t TX_FULL    : 1;            /*!< [5..5] Transmit FIFO is full                                              */
      __IOM uint32_t RTS_STATUS : 1;            /*!< [6..6] RTS state                                                          */
      __IOM uint32_t CTS_STATUS : 1;            /*!< [7..7] CTS state                                                          */
      __IOM uint32_t TX_EMPTY   : 1;            /*!< [8..8] Transmit FIFO is completely empty                                  */
      __IOM uint32_t TX_DONE    : 1;            /*!< [9..9] Transmit FIFO is empty and transmitter is idle                     */
            uint32_t            : 6;
      __IOM uint32_t RX_FIFO_LEVEL : 4;         /*!< [19..16] How many entries are filled in the RX FIFO                       */
            uint32_t            : 4;
      __IOM uint32_t TX_FIFO_LEVEL : 4;         /*!< [27..24] How many entries are filled in the TX FIFO                       */
            uint32_t            : 4;
    } bit;
  } STAT;
  __IOM uint16_t  BAUD;                         /*!< (@ 0x00000028) Baudrate                                                   */
  __IM  uint16_t  RESERVED2;
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
#define UART1                       ((UART1_Type*)             UART1_BASE)
// #define SPI1                        ((SPI1_Type*)              SPI1_BASE)
// #define SPI2                        ((SPI1_Type*)              SPI2_BASE)
// #define LIC                         ((BCM_LIC_Type*)           LIC_BASE)
// #define USB_OTG_GLOBAL              ((USB_OTG_GLOBAL_Type*)    USB_OTG_GLOBAL_BASE)
// #define USB_OTG_HOST                ((USB_OTG_HOST_Type*)      USB_OTG_HOST_BASE)
// #define USB_OTG_DEVICE              ((USB_OTG_DEVICE_Type*)    USB_OTG_DEVICE_BASE)
// #define USB_OTG_PWRCLK              ((USB_OTG_PWRCLK_Type*)    USB_OTG_PWRCLK_BASE)
// #define EMMC                        ((Arasan_EMMC_Distributor_Type*)  EMMC_BASE)

/* End of group Device_Peripheral_declaration */