#include "../kernel/include/drivers/tty.h"
#include "../kernel/include/types.h"
#include "../kernel/include/time.h"
#include "../kernel/include/cpu.h"
#include "../kernel/include/drivers/keyboard.h"
#include "../kernel/include/shell.h"
#include "../libc/include/string.h"

void init();

extern "C" void set_idt();
extern "C"
{
#include "../kernel/include/isr.h"
#include "../kernel/gdt/gdt.h"
}

shell sh;
string str;

extern "C" int main()
{
    init();
    do {
        sh.output_prompt();
        char * arr = sh.input_line();
        monitor_put('\n');
        
        if (strlen(arr) != 0) {
            sh.output_prompt();
            monitor_write(arr);
            monitor_put('\n');
        }
        
    } while (true);

    return 0;
}

void init()
{
    // Initialise the screen (by clearing it)
    gdt_init();
    set_idt();
    isr_install();
    monitor_clear();
    monitor_write("TIME ");
    read_rtc();
    monitor_put('\n');
    cpu_detect();
    monitor_put('\n');
}
