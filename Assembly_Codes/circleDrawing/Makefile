ARMGNU ?= arm-none-eabi
DEBUG = ./debug/
SOURCE = ./source/
ASM_LIBRARIES = ../../libraries/asm/
C_LIBRARIES = ../../libraries/
LIST = ./debug/kernel.list
SYMBOLS = ./debug/kernel.nm
TARGET = ./kernel.img
UPLOADSCRIPT = ./run.sh
CFLAGS = -O1 -mfpu=vfp -mfloat-abi=softfp -march=armv6zk -mtune=arm1176jzf-s -nostartfiles -std=gnu11 -ggdb -Wreturn-local-addr -Wl,-T,linkerScript.ld,--no-wchar-size-warning
OBJECTS := $(wildcard $(SOURCE)*.c) $(wildcard $(SOURCE)*.s) $(wildcard $(ASM_LIBRARIES)*.s) $(wildcard $(ASM_LIBRARIES)*.a) $(wildcard $(C_LIBRARIES)src/*.c)

.PHONY: debug clean program all

all: $(TARGET) $(LIST)

$(TARGET) : $(DEBUG)output.elf
	$(ARMGNU)-objcopy $(DEBUG)output.elf -O binary $(TARGET)

$(LIST) : $(DEBUG)output.elf
	$(ARMGNU)-objdump -t -D $(DEBUG)output.elf > $(LIST)
	$(ARMGNU)-nm $(DEBUG)output.elf > $(SYMBOLS)

$(DEBUG)output.elf: $(OBJECTS)
	$(ARMGNU)-gcc $(CFLAGS) -I$(C_LIBRARIES) $(OBJECTS) -o $(DEBUG)output.elf

program:
	$(UPLOADSCRIPT)

jtag:
	-openocd -f openocd.cfg

clean:
	-rm -rf $(DEBUG)*
	-rm -f $(TARGET)
	-rm -f $(SYMBOLS)
	-rm -f $(LIST)
