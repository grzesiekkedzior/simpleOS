#include "include/common.h"

// Write a byte out to the specified port.
void outb(u16int port, u8int value) {
    __asm__ volatile("outb %1, %0"
                     :
                     : "dN"(port), "a"(value));
}

u8int inb(u16int port) {
    u8int ret;
    __asm__ volatile("inb %1, %0"
                     : "=a"(ret)
                     : "dN"(port));
    return ret;
}

u16int inw(u16int port) {
    u16int ret;
    __asm__ volatile("inw %1, %0"
                     : "=a"(ret)
                     : "dN"(port));
    return ret;
}

// Copy len bytes from src to dest.
void memcpy(u8int *dest, const u8int *src, u32int len) {
    // TODO: implement this yourself!
}

// Write len copies of val into dest.
void memset(u8int *dest, u8int val, u32int len) {
    // TODO: implement this yourself!
}
