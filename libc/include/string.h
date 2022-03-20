#ifndef STRINGS_H
#define STRINGS_H

#include "../kernel/include/types.h"

#ifdef __cplusplus
extern "C"
{
#endif
    void int_to_ascii(int n, char str[]);
    void reverse(char s[]);
    int strlen(char s[]);
    void backspace(char s[]);
    void append(char s[], char n);
    int strcmp(char s1[], char s2[]);
    void memory_set(u8int *dest, u8int val, u32int len);
    void memory_copy(char *source, char *dest, int nbytes);

#ifdef __cplusplus
}
#endif
#endif
