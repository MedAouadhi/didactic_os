/**
 * @file mini_uart.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * used: https://datasheets.raspberrypi.com/bcm2711/bcm2711-peripherals.pdf
 */
//#include "../bcm2837_lpa.h"


void uart_init(int baudrate)
{
    //UART1_Type *uart = UART1;

    //int sysclk = 250000000;
    /* calculate the baudrate register value */
    //uart->BAUD = (sysclk / (baurdate * 8)) - 1;

    /* clear interrupts */
}