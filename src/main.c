#include "gpio.h"
#include "mini_uart.h"
#include "utils.h"
#include "printf.h"

extern uint32_t vector_table_el2; //in vectors.S

void main()
{

    set_vbar_el2((uint32_t)&vector_table_el2);

    //for testing the correct setting of the vector table
    // this should generate a Data Abort (SError exception)
    //volatile int cont = *((volatile int *)0xffffffffffffffffull);

    uart_init(115200);

    printf("Hello World from EL%d.\r\n", get_current_el());
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