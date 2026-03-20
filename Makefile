TARGET = firmware
SDK_PATH = ./sdk
CC = arm-none-eabi-gcc
CFLAGS = -I$(SDK_PATH)/devices -I$(SDK_PATH)/boards -O2 -mcpu=cortex-m33 -mthumb

all:
    $(CC) main.c -T link.ld $(CFLAGS) -o $(TARGET).elf
    arm-none-eabi-objcopy -O binary $(TARGET).elf $(TARGET).bin

clean:
    rm -f *.elf *.bin
