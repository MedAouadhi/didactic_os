/**
 * @file gpio.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "gpio.h"

static void gpio_get_regs(uint8_t gpio_num, gpio_ctrl_t *gpctrl)
{
    if (gpio_num < 32) {
        gpctrl->setclr_index = gpio_num;
        gpctrl->GPSET = &GPIO->GPSET0;
        gpctrl->GPCLR = &GPIO->GPCLR0;
        gpctrl->GPLEV = &GPIO->GPLEV0;
    } else {
        gpctrl->setclr_index = gpio_num - 32;
        gpctrl->GPSET = &GPIO->GPSET1;
        gpctrl->GPCLR = &GPIO->GPCLR1;
        gpctrl->GPLEV = &GPIO->GPLEV1;
    }

    int reg_index = gpio_num / 10;
    gpctrl->fsel_index = gpio_num % 10;

    switch (reg_index)
    {
    case 0: gpctrl->GPFSEL = (volatile uint32_t *)&GPIO->GPFSEL0;  break;
    case 1: gpctrl->GPFSEL = (volatile uint32_t *)&GPIO->GPFSEL1;  break;
    case 2: gpctrl->GPFSEL = (volatile uint32_t *)&GPIO->GPFSEL2;  break;
    case 3: gpctrl->GPFSEL = (volatile uint32_t *)&GPIO->GPFSEL3;  break;
    case 4: gpctrl->GPFSEL = (volatile uint32_t *)&GPIO->GPFSEL4;  break;
    case 5: gpctrl->GPFSEL = (volatile uint32_t *)&GPIO->GPFSEL5;  break;
    }
}

void gpio_alt_func(uint8_t gpio_num, e_fsel alt_func)
{
    gpio_ctrl_t gpio;
    //get the register
    gpio_get_regs(gpio_num, &gpio);
    *gpio.GPFSEL &= ~(FSEL_MASK << (3 * gpio.fsel_index));
    *gpio.GPFSEL |= (alt_func << (3 * gpio.fsel_index));
}

void gpio_set(uint8_t gpio_num)
{
    gpio_ctrl_t gpio;
    //get the register
    gpio_get_regs(gpio_num, &gpio);
    //set the direction of the pin
    gpio_alt_func(gpio_num, OUTPUT);
    //set the gpio
    *gpio.GPSET |= (1 << gpio.setclr_index);
}

void gpio_reset(uint8_t gpio_num)
{
    gpio_ctrl_t gpio;
    //get the register
    gpio_get_regs(gpio_num, &gpio);
    gpio_alt_func(gpio_num, OUTPUT);
    //set the gpio
    *gpio.GPCLR |= (1 << gpio.setclr_index);
}



bool gpio_is_set(uint8_t gpio_num)
{
    gpio_ctrl_t gpio;
    //get the register
    gpio_get_regs(gpio_num, &gpio);
    if (*gpio.GPLEV & (1 << gpio.setclr_index))
        return 1;
    else
        return 0;
}
