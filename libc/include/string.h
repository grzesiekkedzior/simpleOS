#ifndef STRINGS_H
#define STRINGS_H

#include "../kernel/include/types.h"

#ifdef __cplusplus
extern "C"
{
#endif
    void int_to_ascii(int n, char str[]);
    void reverse(char *s);
    int str_length(char *s);
#ifdef __cplusplus
}
class string {
public:
    string();
    string(char *s);

    void backspace(char s[]);
    void append(char s[], char n);
    int strcmp(char s1[], char s2[]);
    void memory_set(u8int *dest, u8int val, u32int len);
    void memory_copy(char *source, char *dest, int nbytes);
    void int_to_ascii(int n, char str[]);
    void reverse(char s[]);
    int length();
    // Copy the NULL-terminated string src into dest, and
    // return dest.
    char *strcpy(char *dest, char *src);
    // Concatenate the NULL-terminated string src onto
    // the end of dest, and return dest.
    char *strcat(char *dest, char *src);
    string operator=(char *rhs);
    char *getStr();
private:
    char *str = nullptr;
};
#endif
#endif
