SRC=src
OUT=build
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst src/%.c,build/%.o,$(SRCS))

CFLAGS = -Wall -O0 -ffreestanding -nostdlib -nostartfiles -ggdb -Iinc

all: clean kernel8.img

$(OUT):
	@mkdir -p $(OUT)

start.o: start.S
	@aarch64-elf-gcc $(CFLAGS) -c start.S -o start.o

$(OUT)/%.o: $(SRC)/%.c $(OUT)
	@echo "CC $<"
	@aarch64-elf-gcc $(CFLAGS) -c $< -o $@

kernel8.img: start.o $(OBJS)
	@echo generating $@
	@aarch64-elf-ld -nostdlib -nostartfiles start.o $(OBJS) -T link.ld -o kernel8.elf -Map=output.map
	@aarch64-elf-objcopy -O binary kernel8.elf kernel8.img

clean:
	@rm kernel8.elf *.o *.map *.img >/dev/null 2>/dev/null || true
	@rm -rf build/

copy:
	@cp -f kernel8.img /media/mohamed/BOOT/