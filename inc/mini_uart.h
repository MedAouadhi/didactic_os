/**
 * @file mini_uart.h
 * @author mohamed aouadhi
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "pi3bplus.h"

#define MINI_UART   UART1

void uart_init(int baudrate);
void uart_putc(char c);
char uart_getc(void);
void uart_puts(char *s);
void uart_gets(char *s);
void putc(void *p, char c);