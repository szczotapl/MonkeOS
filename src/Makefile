.POSIX:

ISODIR := root
MULTIBOOT := $(ISODIR)/boot/main.elf
MAIN := monkeos.iso

.PHONY: clean run

$(MAIN):
	as -32 asm/boot.S -o boot.o
	g++ -c kernel.cpp -ffreestanding -m32 -o kernel.o -std=c++11
	mkdir -p $(ISODIR)/boot
	cp -r grub $(ISODIR)/boot
	gcc -ffreestanding -m32 -nostdlib -o '$(MULTIBOOT)' -T linker/linker.ld boot.o kernel.o -lgcc -lc
	grub-mkrescue -o '$@' '$(ISODIR)'

clean:
	rm -rf $(ISODIR)
	rm -f *.o '$(MULTIBOOT)' '$(MAIN)'

run: $(MAIN)
	qemu-system-i386 -cdrom '$(MAIN)' -debugcon file:/dev/stdout -boot d -d guest_errors,cpu_reset -monitor stdio