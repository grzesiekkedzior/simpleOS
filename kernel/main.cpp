#include "monitor.h"
#include "types.h"
#include "time.h"
#include "cpu.h"
#include "kb.h"

extern "C" void set_idt();
extern "C"
{
#include "isr.h"
#include "gdt/gdt.h"
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
    readStr();

    return 0;
}
