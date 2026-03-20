CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-mcpu=cortex-m33 -mthumb -O2 -nostdlib -ffreestanding

all:
    $(CC) main.c -T link.ld $(CFLAGS) -o firmware.elf
    $(OBJCOPY) -O binary firmware.elf firmware.bin

clean:
    rm -f *.elf *.bin
