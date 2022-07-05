#include "gpio.h"

#define LED_PIN 29

void main()
{
    gpio_set(LED_PIN);
    gpio_reset(LED_PIN);
    while(1);
}