.POSIX:

ISODIR := iso
MULTIBOOT := $(ISODIR)/boot/main.elf
MAIN := monkeos.iso

.PHONY: clean run

$(MAIN):
	as -32 boot.S -o boot.o
	g++ -c kernel.cpp -ffreestanding -m32 -o kernel.o -std=c++11
	gcc -ffreestanding -m32 -nostdlib -o '$(MULTIBOOT)' -T linker.ld boot.o kernel.o -lgcc -lc
	grub-mkrescue -o '$@' '$(ISODIR)'

clean:
	rm -f *.o '$(MULTIBOOT)' '$(MAIN)'

run: $(MAIN)
	qemu-system-i386 -cdrom '$(MAIN)'