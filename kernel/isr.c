#include "include/isr.h"
#include "include/drivers/tty.h"
#include "../libc/include/string.h"
#include "../kernel/include/common.h"

void set_idt_gate(int n, u32int handler);
void set_idt();

isr_t interrupt_handlers[256];

/* Can't do this with a loop because we need the address
 * of the function names */
void isr_install() {
    set_idt_gate(0, (u32int)isr0);
    set_idt_gate(1, (u32int)isr1);
    set_idt_gate(2, (u32int)isr2);
    set_idt_gate(3, (u32int)isr3);
    set_idt_gate(4, (u32int)isr4);
    set_idt_gate(5, (u32int)isr5);
    set_idt_gate(6, (u32int)isr6);
    set_idt_gate(7, (u32int)isr7);
    set_idt_gate(8, (u32int)isr8);
    set_idt_gate(9, (u32int)isr9);
    set_idt_gate(10, (u32int)isr10);
    set_idt_gate(11, (u32int)isr11);
    set_idt_gate(12, (u32int)isr12);
    set_idt_gate(13, (u32int)isr13);
    set_idt_gate(14, (u32int)isr14);
    set_idt_gate(15, (u32int)isr15);
    set_idt_gate(16, (u32int)isr16);
    set_idt_gate(17, (u32int)isr17);
    set_idt_gate(18, (u32int)isr18);
    set_idt_gate(19, (u32int)isr19);
    set_idt_gate(20, (u32int)isr20);
    set_idt_gate(21, (u32int)isr21);
    set_idt_gate(22, (u32int)isr22);
    set_idt_gate(23, (u32int)isr23);
    set_idt_gate(24, (u32int)isr24);
    set_idt_gate(25, (u32int)isr25);
    set_idt_gate(26, (u32int)isr26);
    set_idt_gate(27, (u32int)isr27);
    set_idt_gate(28, (u32int)isr28);
    set_idt_gate(29, (u32int)isr29);
    set_idt_gate(30, (u32int)isr30);
    set_idt_gate(31, (u32int)isr31);

    // Remap the PIC
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0); 

    // Install the IRQs
    set_idt_gate(32, (u32int)irq0);
    set_idt_gate(33, (u32int)irq1);
    set_idt_gate(34, (u32int)irq2);
    set_idt_gate(35, (u32int)irq3);
    set_idt_gate(36, (u32int)irq4);
    set_idt_gate(37, (u32int)irq5);
    set_idt_gate(38, (u32int)irq6);
    set_idt_gate(39, (u32int)irq7);
    set_idt_gate(40, (u32int)irq8);
    set_idt_gate(41, (u32int)irq9);
    set_idt_gate(42, (u32int)irq10);
    set_idt_gate(43, (u32int)irq11);
    set_idt_gate(44, (u32int)irq12);
    set_idt_gate(45, (u32int)irq13);
    set_idt_gate(46, (u32int)irq14);
    set_idt_gate(47, (u32int)irq15);

    set_idt(); // Load with ASM
}

/* To print the message which defines every exception */
char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void isr_handler(registers_t r) {
    monitor_write("Exception. System Halted! received interrupt: ");
    char s[3];
    int_to_ascii(r.int_no, s);
    monitor_write(s);
    monitor_write("\n");
    monitor_write(exception_messages[r.int_no]);
    monitor_write("\n");
    for (;;);
}

void register_interrupt_handler(u8int n, isr_t handler) {
    interrupt_handlers[n] = handler;
}

void irq_handler(registers_t r) {
    /* After every interrupt we need to send an EOI to the PICs
     * or they will not send another interrupt again */
    if (r.int_no >= 40) outb(0xA0, 0x20); /* slave */
    outb(0x20, 0x20); /* master */

    /* Handle the interrupt in a more modular way */
    if (interrupt_handlers[r.int_no] != 0) {
        isr_t handler = interrupt_handlers[r.int_no];
        handler(r);
    }
}
