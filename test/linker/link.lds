



SECTIONS{
	. = 0x40000000;
	.text : { *(.text) }
	.rodata : { *(.rodata) }
	.data : { *(.data) }
	.bss : { *(.bss COMMON) }
	
	. = ALIGN(4);
	. = . + 0x1000;
	stack_top = .;
}

