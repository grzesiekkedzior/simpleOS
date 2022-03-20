#include "../kernel/include/drivers/tty.h"
#include "../kernel/include/types.h"
#include "../kernel/include/time.h"
#include "../kernel/include/cpu.h"
#include "../kernel/include/drivers/keyboard.h"


extern "C" void set_idt();
extern "C"
{
#include "../kernel/include/isr.h"
#include "../kernel/gdt/gdt.h"
}

extern "C" int main()
{
    // Initialise the screen (by clearing it)
    gdt_init();
    set_idt();
    isr_install();
    monitor_clear();
    // Write out a sample string
    monitor_write("WELCOME\nTIME ");

    read_rtc();
    monitor_put('\n');
    cpu_detect();
    monitor_write("\n>");
    io_handler();


    return 0;
}
