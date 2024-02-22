USER = $(shell whoami)
HOST = $(shell hostname)

# Check what OS we're running. Should work on Linux and macOS.
OSTYPE = $(shell uname)

# Target defs for Linux cross compiler.
TARGET = i386-apple-darwin8

# Definitions for compiler
CC := clang

# Definitions for linker
ifeq ($(OSTYPE),Linux)
	LD := /opt/cross/bin/$(TARGET)-ld
else
	LD := ld
endif

# Flags for mach-o linker
LDFLAGS := -static \
           -segalign 0x1000 \
           -segaddr __TEXT 0x00400000 \
           -sectalign __TEXT __text 0x1000 \
           -sectalign __DATA __common 0x1000 \
           -sectalign __DATA __bss 0x1000 \

DEFINES := 

CFLAGS := -Wall -nostdlib -fno-stack-protector -fshort-wchar -fno-builtin -O0 --target=$(TARGET) -Iinclude -Iinclude/uefi -Iinclude/uefi/Ia32 $(DEFINES)

OBJS = start.o console.o utils.o vsprintf.o libatv.o ioports.o macho.o time.o

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
mach_kernel: $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@
all: mach_kernel

clean:
	rm -f *.o mach_kernel