#include "gpio.h"
#include "mini_uart.h"
#include "utils.h"
#include "printf.h"

void main()
{

    uart_init(115200);

    printf("Hello World\r\n");
    char msg[50] = {0};

    while(1) {
        memset(msg, 0, sizeof(msg));
        uart_gets(msg);
        /* remove the last newline char */
        msg[strlen(msg) - 1] = '\0';
        if (strstr((const char *)msg, (const char *)"hello") == 0) {
            printf("Hello back!\r\n");
            printf("Maa Salama!\r\n");
            break;
        } else {
            printf("I did not understand: %s.\r\n", msg);
        }
    }
    while(1);
}