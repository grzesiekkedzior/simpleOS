#include "../include/string.h"

void int_to_ascii(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';

    reverse(str);
}

int strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void string::append(char s[], char n) {
    int len = strlen(s);
    s[len] = n;
    s[len + 1] = '\0';
}

void string::backspace(char s[]) {
    int len = strlen(s);
    s[len - 1] = '\0';
}

/* K&R
 * Returns <0 if s1<s2, 0 if s1==s2, >0 if s1>s2 */
int string::strcmp(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++)
        if (s1[i] == '\0')
            return 0;
            
    return s1[i] - s2[i];
}

void string::memory_copy(char *source, char *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++)
        *(dest + i) = *(source + i);
}

void string::memory_set(u8int *dest, u8int val, u32int len) {
    u8int *temp = (u8int *)dest;
    for (; len != 0; len--)
        *temp++ = val;
}

void string::reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void string::int_to_ascii(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';

    reverse(str);
}

int string::strlen(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}

char *string::strcpy(char *dest, char *src) {
    if (src == nullptr) return nullptr;

    char *ptr = dest;

    while (*src != '\0') {
        *dest = *src;
        ++dest;
        ++src;
    }
    *dest = '\0';

    return ptr;
}

char *string::strcat(char *dest, char *src) {
    if (src == nullptr) return nullptr;

    char *ptr = dest + strlen(dest);

    while (*src != '\0') {
        *ptr = *src;
        ++ptr;
        ++src;
    }

    *dest = '\0';

    return ptr;
}
