cmake_minimum_required (VERSION 3.8)
PROJECT (kernel)

INCLUDE_DIRECTORIES (include)

SET (CMAKE_CXX_FLAGS "-m32 -ffreestanding -fno-rtti -fno-exceptions -nostdlib -nostdinc -fno-stack-protector")
SET (CMAKE_C_FLAGS "-m32 -ffreestanding -fno-exceptions -nostdlib -nostdinc -fno-stack-protector")
#SET (CMAKE_EXE_LINKER_FLAGS "-m elf_i386 -T${CMAKE_CURRENT_LIST_DIR}/link.ld")
SET (CMAKE_ASM_NASM_OBJECT_FORMAT "elf")

ENABLE_LANGUAGE (ASM_NASM)
add_compile_options(-I ${CMAKE_CURRENT_SOURCE_DIR}/boot )


FILE (GLOB_RECURSE kernel_LIB_SOURCES "lib/*.c")
FILE (GLOB_RECURSE kernel_ASM_SOURCES "boot/*.asm")
FILE (GLOB_RECURSE kernel_C_SOURCES "kernel/*.c")
FILE (GLOB_RECURSE kernel_CPP_SOURCES "kernel/*.cpp")

ADD_LIBRARY (kernel.img STATIC
			${kernel_ASM_SOURCES}
			${kernel_C_SOURCES} 
			${kernel_CPP_SOURCES}
			${kernel_LIB_SOURCES}
			)

ADD_CUSTOM_COMMAND (TARGET kernel.img
	POST_BUILD
	COMMAND ld -m elf_i386 -T${CMAKE_CURRENT_LIST_DIR}/link.ld -o ../kernel.bin ${CMAKE_BINARY_DIR}/libkernel.img.a)
