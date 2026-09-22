CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

MCU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard

CFLAGS = $(MCU) -std=c11 -Wall -Wextra -O2 -g3 \
         -ffunction-sections -fdata-sections \
         -Isrc

LDFLAGS = $(MCU) -T ld/linker.ld \
         -Wl,--gc-sections -Wl,-Map=build/firmware.map \
         -nostartfiles

SRCS = src/startup.c src/main.c
OBJS = $(SRCS:src/%.c=build/%.o)

all: build/firmware.bin

build:
	mkdir -p build

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build/firmware.elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
	$(SIZE) $@

build/firmware.bin: build/firmware.elf
	$(OBJCOPY) -O binary $< $@

flash: build/firmware.bin
	dfu-util -a 0 -s 0x08000000:leave -D build/firmware.bin

clean:
	rm -rf build

.PHONY: all flash clean
