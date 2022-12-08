#include "../kernel/include/drivers/keyboard.h"
#include "../kernel/include/common.h"
#include "../include/drivers/kb.h"
#include "../include/drivers/tty.h"

bool is_left_shift_pressed;
bool is_right_shift_pressed;

char handler_keyboard(u8int scancode) {
    switch (scancode) {
    case LEFT_SHIFT:
        is_left_shift_pressed = true;
        break;
    case LEFT_SHIFT + 0x80:
        is_left_shift_pressed = false;
        break;
    case RIGHT_SHIFT:
        is_right_shift_pressed = true;
        break;
    case RIGHT_SHIFT + 0x80:
        is_right_shift_pressed = false;
        break;
    case ENTER:
        monitor_put(13);
        break;
    // case SPACEBAR:
    //     monitor_put(' ');
    //     break;
    case BACKSPACE:
        monitor_put(BACKSPACE);
        break;
    case ARROW_UP:
        arrow_up();
        break;
    case ARROW_LEFT:
        arrow_left();
        break;
    case ARROW_RIGHT:
        arrow_right();
        break;
    case ARROW_DOWN:
        arrow_down();
        break;
    }
    char ascii = qwerty::translate(scancode, is_left_shift_pressed or is_right_shift_pressed);

    return ascii;
}

char get_char () {
    if (inb(0x64) & 0x1) {
        u8int scancode = inb(0x60);
        return handler_keyboard(scancode);
    }
    return 0;
}

void io_handler() {
    char ascii;
    while (true) {
        ascii = get_char();
        if (ascii != 0) monitor_put(ascii);
    }
}
