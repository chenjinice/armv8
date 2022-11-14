

GCC_PATH  = /home/chen/Desktop/optee_qemu/toolchains/aarch64/bin
QEMU_PATH = $(shell pwd)/../qemu/aarch64-softmmu
export PATH := $(PATH):$(GCC_PATH):$(QEMU_PATH)

CROSS_COMPILE = aarch64-linux-gnu-
O = out
CFLAGS += -g

TARGET = $(O)/test
ELF=$(TARGET).elf
BIN=$(TARGET).bin
ASM=$(TARGET).asm

# 源文件
SRCS += plat/start.s
SRCS += main.c
# 目标文件，最后需要加上out目录前缀
TMP1 = $(SRCS:%.c=%.o)
TMP2 = $(TMP1:%.s=%.o)
OBJS = $(addprefix $(O)/,$(TMP2))

all:$(BIN)

$(BIN):$(OBJS)
	$(CROSS_COMPILE)ld -T linker/link.lds $^ -o $(ELF)
	$(CROSS_COMPILE)objcopy -O binary $(ELF) $(BIN)
	$(CROSS_COMPILE)objdump -d $(ELF) > $(ASM)

$(O)/%.o:%.c
	@if [ ! -d $(dir $@) ];then mkdir -p $(dir $@);fi
	$(CROSS_COMPILE)gcc -c $< -o $@ $(CFLAGS)

$(O)/%.o:%.s
	@if [ ! -d $(dir $@) ];then mkdir -p $(dir $@);fi
	$(CROSS_COMPILE)gcc -c $< -o $@ $(CFLAGS)

run:$(BIN)
	qemu-system-aarch64 -M virt -cpu cortex-a57 -nographic -kernel $<

debug:$(ELF)
	qemu-system-aarch64 -M virt -cpu cortex-a57 -nographic -kernel $< -s -S

clean:
	-rm $(OBJS)
	-rm $(ELF)
	-rm $(BIN)
	-rm $(ASM)


