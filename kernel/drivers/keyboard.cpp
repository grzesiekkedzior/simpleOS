#include "../kernel/include/drivers/keyboard.h"
#include "../kernel/include/common.h"
#include "../include/drivers/kb.h"
#include "../include/drivers/tty.h"

bool is_left_shift_pressed;
bool is_right_shift_pressed;

void handler_keyboard(u8int scancode) {
    switch (scancode) {
    case LEFT_SHIFT:
        is_left_shift_pressed = true;
        return;
    case LEFT_SHIFT + 0x80:
        is_left_shift_pressed = false;
        return;
    case RIGHT_SHIFT:
        is_right_shift_pressed = true;
        return;
    case RIGHT_SHIFT + 0x80:
        is_right_shift_pressed = false;
        return;
    case ENTER:
        monitor_put(13);
        return;
    case SPACEBAR:
        monitor_put(' ');
        return;
    case BACKSPACE:
        monitor_put(BACKSPACE);
        return;
    case ARROW_UP:
        arrow_up();
        return;
    case ARROW_LEFT:
        arrow_left();
        return;
    case ARROW_RIGHT:
        arrow_right();
        return;
    case ARROW_DOWN:
        arrow_down();
        return;
    }
    char ascii = qwerty::translate(scancode, is_left_shift_pressed or is_right_shift_pressed);

    if (ascii != 0) monitor_put(ascii);
}

void io_handler() {
    while (true) {
        if (inb(0x64) & 0x1) {
            u8int scancode = inb(0x60);
            handler_keyboard(scancode);
        }
    }
}
