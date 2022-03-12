#include "../../include/monitor.h"
#include "../../include/drivers/kb.h"

namespace qwerty
{
    const char ascii_table[] = {
        0, 0, '1', '2',
        '3', '4', '5', '6',
        '7', '8', '9', '0',
        '-', '=', 0, 0,
        'q', 'w', 'e', 'r',
        't', 'y', 'u', 'i',
        'o', 'p', '[', ']',
        0, 0, 'a', 's',
        'd', 'f', 'g', 'h',
        'j', 'k', 'l', ';',
        '\'', '`', 0, '\\',
        'z', 'x', 'c', 'v',
        'b', 'n', 'm', ',',
        '.', '/', 0, '*',
        0, ' '};

    // only letters and numbers no special characters
    char translate(u8int scancode, bool uppercase)
    {
        if (scancode > 58)
            return 0;

        if (uppercase)
        {
            return ascii_table[scancode] - 32;
        }
        else
            return ascii_table[scancode];
    }

}
