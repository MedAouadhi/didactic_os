/**
 * @file utils.h
 * @author Mohamed Aouadhi
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define UNMASK_IRQS()   asm volatile("msr DAIFClr, #0b0011")
#define MASK_IRQS()   asm volatile("msr DAIFSet, #0b0011")

int strlen(const char *s);
int strstr(const char *s1, const char *s2);
void memset(void *addr, uint8_t val, int size);
uint32_t get_current_el(void);
void set_vbar_el2(uint32_t vbar);
