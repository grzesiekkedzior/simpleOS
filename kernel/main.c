#include "monitor.h"
#include "isr.h"
#include "time.h"
#include "cpu.h"

int main()
{
    // Initialise the screen (by clearing it)
    monitor_clear();
    // Write out a sample string
    monitor_write("WELCOME\nTIME ");
    
    isr_install();

    read_rtc();
    monitor_put('\n');
    cpu_detect();
    
    monitor_write("\n>");
    readStr();
    
    return 0;
}
