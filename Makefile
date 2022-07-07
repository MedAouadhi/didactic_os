SRC=src
OUT=build
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst src/%.c,build/%.o,$(SRCS))

ASMS = $(wildcard *.S)
ASM_OBJS = $(patsubst %.S,%.o,$(ASMS))

TOOLCHAIN=/usr/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-elf/bin/aarch64-elf
CFLAGS = -Wall -O0 -ffreestanding -nostdlib -nostartfiles -ggdb -Iinc

all: clean kernel8.img

$(OUT):
	@echo $(ASMS) 
	@mkdir -p $(OUT)

%.o: %.S
	@echo "CC $<"
	@${TOOLCHAIN}-gcc $(CFLAGS) -c  $< -o $@

$(OUT)/%.o: $(SRC)/%.c $(OUT)
	@echo "CC $<"
	@${TOOLCHAIN}-gcc $(CFLAGS) -c $< -o $@

kernel8.img:  $(OBJS) $(ASM_OBJS)
	@echo generating $@
	@${TOOLCHAIN}-ld -nostdlib -nostartfiles $(ASM_OBJS) $(OBJS) -T link.ld -o kernel8.elf -Map=output.map
	@${TOOLCHAIN}-objcopy -O binary kernel8.elf kernel8.img

clean:
	@rm kernel8.elf *.o *.map *.img >/dev/null 2>/dev/null || true
	@rm -rf build/

copy:
	@cp -f kernel8.img /media/mohamed/BOOT/