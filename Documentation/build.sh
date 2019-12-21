nasm -f elf32 kernel.asm -o kasm.o
gcc -m32 -c -fno-stack-protector -std=c99 kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o kernel.bin kasm.o kc.o
qemu-system-x86_64 -kernel kernel.bin

