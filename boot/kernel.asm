bits    32
%include "gdt.asm"
section         .text
        align   4
        dd      0x1BADB002
        dd      0x00
        dd      - (0x1BADB002+0x00)
        
global start
extern main                     ; this function is gonna be located in our c code(kernel.c)
start:
        cli                     ;clears the interrupts
        lgdt [gdt_descriptor]   ;load the GDT descriptor
        call main               ;send processor to continue execution from the kamin funtion in c code
        hlt                     ;halt the cpu(pause it from executing from this address
