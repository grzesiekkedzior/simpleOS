#ifndef COMMON_H
#define COMMON_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);

#ifdef __cplusplus
}
#endif
#endif // COMMON_H
