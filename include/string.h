#ifndef STRINGS_H
#define STRINGS_H
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

#ifdef __cplusplus
}
#endif
#endif
