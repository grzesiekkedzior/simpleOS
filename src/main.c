// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
//           Made for JamesM's tutorials <www.jamesmolloy.co.uk>

#include "monitor.h"
#include "isr.h"

int main(struct multiboot *mboot_ptr)
{
    // Initialise the screen (by clearing it)
    monitor_clear();
    // Write out a sample string
    monitor_write("Welcome\n>");
    isr_install();
    monitor_write(readStr());
    
    return 0;
}
