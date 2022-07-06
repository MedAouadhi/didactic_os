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

#include "pi3bplus.h"

#define GPIO_SET    1
#define GPIO_RESET  0

typedef struct { 
    volatile uint32_t *GPSET;
    volatile uint32_t *GPCLR;
    volatile uint32_t *GPFSEL;
    volatile uint32_t *GPLEV;
    volatile uint32_t *GPPUPD;
    uint8_t setclr_index;
    uint8_t fsel_index;
    uint8_t pupd_index;
} gpio_ctrl_t;

#define FSEL_MASK       0x7
typedef enum {
    INPUT = 0,
    OUTPUT = 1,
    ALTFN0 = 4,
    ALTFN1 = 5,
    ALTFN2 = 6,
    ALTFN3 = 7,
    ALTFN4 = 3,
    ALTFN5 = 2
} e_fsel;

#define PUPD_MASK       0x3

typedef enum {
    NO_PULL=0,
    PULLUP,
    PULLDOWN
} e_pull;

void gpio_set(uint8_t gpio_num);
void gpio_reset(uint8_t gpio_num);
bool gpio_is_set(uint8_t gpio_num);
void gpio_alt_func(uint8_t gpio_num, e_fsel alt_func);
void gpio_pullup(uint8_t gpio_num);
void gpio_pulldown(uint8_t gpio_num);
void gpio_nopull(uint8_t gpio_num);


