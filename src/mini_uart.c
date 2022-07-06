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

#include "gpio.h"
#include "mini_uart.h"

void uart_init(int baudrate)
{
    UART1_Type *uart = MINI_UART;

    //configure TX and RX pins of MINI_UART 
    // TX1 = GP14, RX1= GP15
    gpio_alt_func(29, OUTPUT);
    gpio_alt_func(14, ALTFN5);
    gpio_alt_func(15, ALTFN5);

    /* Remove the pullup and pulldown resistor from the tx and rx pins */
    gpio_nopull(14);
    gpio_nopull(15);

    /* Enable the uart */
    uart->AUX_ENABLES |= 1;

    /* Disable Tx and Rx in init */
    uart->AUX_MU_CNTL_REG &= ~0x3;

    /* calculate the baudrate register value */
    uart->AUX_MU_BAUD_REG = (uint16_t)((SYSCLK / (baudrate * 8)) - 1);

    /* Enable 8bit mode*/
    uart->AUX_MU_LCR_REG |= BIT(0);

    /* Set RTS to be always HIGH */
    uart->AUX_MU_MCR_REG |= BIT(1);

    /* clear interrupts */
    uart->AUX_MU_IER_REG &= ~0x3;

    /* Enable Tx and Rx */
    uart->AUX_MU_CNTL_REG |= 0x3;
}

void uart_putc(char c)
{
    UART1_Type *uart = MINI_UART;
    while(!(uart->AUX_MU_LSR_REG & BIT(5)));
    uart->AUX_MU_IO_REG = c;
}

char uart_getc(void)
{
    UART1_Type *uart = MINI_UART;
    while(!(uart->AUX_MU_LSR_REG & BIT(0)));
    gpio_set(29);
    //TODO replace this with a timer
    for (volatile int j=0; j<10000; j++);
    gpio_reset(29);
    return uart->AUX_MU_IO_REG & 0xFF;
}

void uart_puts(char *s)
{
    while(*s)
        uart_putc(*s++);
}

void uart_gets(char *s)
{
    char c = '\0';
    do {
        c = uart_getc();
        if (c == '\r')
            c = '\n';
        *s++ = c;
    } while(c != '\n');
}