OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
TARGET(binary)

INPUT(./boot.o)
INPUT(./KERNEL)
#ifdef USE_INITRD
INPUT(FILESYSTEM)
#endif

PHYS_OFFSET = 0x10000000;

SECTIONS
{
	. = PHYS_OFFSET;
	.text : { boot.o }

	. = PHYS_OFFSET + 0x8000 - KERNEL_HDR_SZ;
	kernel = . + KERNEL_HDR_SZ;
	.kernel : { ./KERNEL }

	. = . + 0x2000000;

#ifdef USE_INITRD
	filesystem = .;
	.filesystem : { FILESYSTEM }
	fs_size = . - filesystem;
#endif

	.data : { *(.data) }
	.bss : { *(.bss) }
}
