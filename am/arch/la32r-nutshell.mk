include $(AM_HOME)/am/arch/isa/la32r.mk

AM_SRCS := nutshell/isa/la32r/trm.c \
           nutshell/common/mainargs.S \
           nutshell/common/uartlite.c \
           nutshell/common/ioe.c \
           nutshell/common/timer.c \
           dummy/input.c \
           dummy/video.c \
           dummy/audio.c \
           dummy/cte.c \
           dummy/vme.c \
           dummy/mpe.c \
           nutshell/isa/la32r/boot/start.S

CFLAGS  += -I$(AM_HOME)/am/src/nutshell/include -DISA_H=\"la32r.h\"

ASFLAGS += -DMAINARGS=\"$(mainargs)\"
.PHONY: $(AM_HOME)/am/src/nutshell/common/mainargs.S
# -L searchdir : Add path searchdir to the list of paths that ld will search for archive libraries and ld control scripts.
# -T scriptfile :  Use scriptfile as the linker script. 
LDFLAGS += -L $(AM_HOME)/am/src/nutshell/ldscript
LDFLAGS += -T $(AM_HOME)/am/src/nutshell/isa/la32r/boot/loader.ld

image:
	@echo + LD "->" $(BINARY_REL).elf
	@$(LD) $(LDFLAGS) --gc-sections -o $(BINARY).elf --start-group $(LINK_FILES) --end-group
	@$(OBJDUMP) -d $(BINARY).elf > $(BINARY).txt
	@echo + OBJCOPY "->" $(BINARY_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(BINARY).elf $(BINARY).bin

# ld:
# --gc-sections : aim to decrease bin size, see https://www.cnblogs.com/zqb-all/p/6128673.html
# --start-group & --end-group :  resolving circular dependences between several libraries, https://stackoverflow.com/questions/5651869

# objcopy:
#  -S --strip-all : Do not copy relocation and symbol information from the source file.
#  -O bfdname --output-target=bfdname : Write the output file using the object format bfdname.
# --set-section-flags sectionpattern=flags : Set the flags for any sections matching sectionpattern
