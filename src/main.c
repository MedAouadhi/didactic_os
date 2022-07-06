#include "gpio.h"
#include "mini_uart.h"
#include "utils.h"


void main()
{

    uart_init(115200);

    uart_puts("\nHello World\r\n");
    char msg[50] = {0};

    while(1) {
        memset(msg, 0, sizeof(msg));
        uart_gets(msg);
        if (strstr((const char *)msg, (const char *)"hello\n") == 0) {
            uart_puts("Hello back!\r\n");
            uart_puts("Maa Salama!\r\n");
            break;
        } else {
            uart_puts("Come Again ?!\r\n");
        }
    }
    while(1);
}