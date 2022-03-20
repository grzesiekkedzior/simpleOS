#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "../types.h"
#include "kb.h"
#include "tty.h"

void handler_keyboard(u8int scancode);
void io_handler();

#endif