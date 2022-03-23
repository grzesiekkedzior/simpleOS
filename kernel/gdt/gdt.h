#ifndef GDT_H
#define GDT_H

#include "../include/types.h"

// This structure contains the value of one GDT entry.
// We use the attribute 'packed' to tell GCC not to change
// any of the alignment in the structure.
typedef struct gdt_descr {
	u16int limit_low; 	// The lower 16 bits of the limit.
	u16int base_low; 	// The lower 16 bits of the base.
	u8int base_middle;	// The next 8 bits of the base.
	//It means Accessed bit. Set it to 0. When the segment is accessed the CPU sets this to 1
	u8int access;
	// It means Granularity bit. If 0, the limit is in 1 B blocks (byte granularity), if 1,
	//the limit is in 4 KiB blocks (page granularity)
	u8int granularity;
	//It means Size bit. If 0, the selector defines 16 bit protected mode. If 1,
	//the selector defines 32 bit protected mode. We can have both 16 bit and 32-bit selectors at once
	u8int base_high;
} __attribute__((packed)) gdt_descr_t;

typedef struct gdt_ptr {
	u16int limit; // The upper 16 bits of all selector limits.
	u32int base;  // The address of the first gdt_entry_t struct.
} __attribute__((packed)) gdt_ptr_t;

extern void gdt_init();

static void gdt_set_desc(gdt_descr_t* descr, u32int base, u32int limit, u8int access, u8int granularity);

static void gdt_set(gdt_ptr_t* gdt_ptr);


#endif