EXE = hellomake

SRC_DIR = src
OBJ_DIR = obj
ASM_OBJECT = obj/kasm.o
INTERRUPT_OBJECT = obj/interrupt.o
GDT_OBJECT = obj/gdt.o

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CPPFLAGS += -Iinclude
CFLAGS += -m32 -c -fno-stack-protector -std=c99
LDPARAMS += -m elf_i386
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

kernel.bin: link.ld $(OBJ)
	ld $(LDPARAMS) -T $< -o $@ $(ASM_OBJECT) $(INTERRUPT_OBJECT) $(OBJ)  
