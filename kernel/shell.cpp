#include "include/shell.h"
#include "../kernel/include/drivers/tty.h"
#include "../kernel/include/drivers/keyboard.h"
#include "include/drivers/kb.h"
#include "../kernel/include/common.h"
#include "../libc/include/string.h"
#include "../kernel/include/shell.h"
#include "include/builtins_programms.h"

using namespace qwerty;

void shell::output_prompt() {
    monitor_put('>');
}

char shell::input_char(u8int scancode) {
    char ascii = handler_keyboard(scancode);
    monitor_put(ascii);
    return ascii;
}

int shell::is_command(char *str) {
    string s;
    for (int i = 0; i < 10; i++) {
        int b = s.strcmp(str, this->builtins[i]);
    if (b == 0) return 1;
    }
    
    return 0;
}
char *shell::input_line()
{
    buffer[0] = '\0';
    string str;
    u8int scancode = 0;
    char ascii = 0;

    while (true) {
        if (inb(0x64) & 0x1)
            scancode = inb(0x60);

        if (scancode != ENTER && scancode != BACKSPACE && scancode != 0) {
            ascii = input_char(scancode);
            str.append(buffer, ascii);
        } else if (scancode == BACKSPACE) {
            ascii = input_char(scancode);
            str.backspace(buffer);
        } else if (scancode == ENTER) {
            return buffer;
        }
        scancode = 0;
    }
}

// Choose program to start
int shell::start_process(char *command) {
    this->cmd = command;
    if (is_command(command)) {
        return 1;
    } 
    return 0;
}

void shell::process_executing(int process) {
    if (process) {
        switch (process)
        {
        case CALENDAR:
            monitor_write("calendar");
            break;
        
        default:
            break;
        }
    } else {
        monitor_write(this->cmd);
        monitor_write(": command not found");
    }
}

