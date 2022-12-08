#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "../types.h"

char handler_keyboard(u8int scancode);
void io_handler();
char get_char();

#endif