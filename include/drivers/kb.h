#ifndef KB_H
#define KB_H
#include "../types.h"

namespace qwerty {
    #define LEFT_SHIFT 0x2A
    #define RIGHT_SHIFT 0x36
    #define ENTER 0x1C
    #define BACKSPACE 0x0E
    #define SPACEBAR 0x39
    #define ARROW_UP 0X48
    #define ARROW_LEFT 0X4B
    #define ARROW_RIGHT 0x4D
    #define ARROW_DOWN 0x50
    
    extern const char ascii_table[];
    char translate(u8int scancode, bool uppercase);
}

#endif
