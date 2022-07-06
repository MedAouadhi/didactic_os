/**
 * @file utils.c
 * @author Mohamed Aouadhi
 * @brief 
 * @version 0.1
 * @date 2022-07-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "types.h"

int strlen(const char *s)
{
    int count = 0;
    while (*s++ != '\0')
        count++;

    return count;
}

int strstr(const char *s1, const char *s2)
{
    if (strlen(s1) != strlen(s2))
        return -1;
    
    while (*s1 != '\0') {
        char diff = *s1 - *s2;
        if (diff != 0)
            return diff;
        s1++;
        s2++;
    }

    return 0;
}

void memset(void *addr, uint8_t val, int size)
{
    while (size--)
        *(uint8_t *)addr++ = val;
}