/**
 * @file gpio.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include "../pi3bplus.h"

#define GPIO_SET    1
#define GPIO_RESET  0

typedef struct { 
    volatile uint32_t *GPSET;
    volatile uint32_t *GPCLR;
    volatile uint32_t *GPFSEL;
    volatile uint32_t *GPLEV;
    uint8_t setclr_index;
    uint8_t fsel_index;
} gpio_ctrl_t;

#define FSEL_MASK       0x7
typedef enum {
    INPUT = 0,
    OUTPUT,
    ALTFN0,
    ALTFN1,
    ALTFN2,
    ALTFN3,
    ALTFN4,
    ALTFN5
} e_fsel;

void gpio_set(uint8_t gpio_num);
void gpio_reset(uint8_t gpio_num);
bool gpio_is_set(uint8_t gpio_num);
void gpio_alt_func(uint8_t gpio_num, e_fsel alt_func);


