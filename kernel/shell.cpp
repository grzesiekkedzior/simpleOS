#include "include/shell.h"
#include "../kernel/include/drivers/tty.h"
#include "../kernel/include/drivers/keyboard.h"
#include "include/drivers/kb.h"
#include "../kernel/include/common.h"
#include "../libc/include/string.h"

using namespace qwerty;

void shell::output_prompt()
{
    monitor_put('>');
}

char *shell::input_line()
{
    buffer[0] = '\0';
    string str;
    u8int scancode = 0;
    char ascii = 0;

    while (true)
    {
        if (inb(0x64) & 0x1) {
            scancode = inb(0x60);
        }
        
        if (scancode != ENTER && scancode!= 0) {
            ascii = handler_keyboard(scancode);
            monitor_put(ascii);
            str.append(buffer, ascii);
            scancode = 0;
        } else if (scancode == ENTER) {
            return buffer;
        }
    }
}

int shell::start_process(char *command)
{
    return 0;
}

int shell::process_executing(int process)
{
    return 0;
}