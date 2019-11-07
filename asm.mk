#
#	here are the corewar's assembler compiler specific makefiles variables.
#	each variables declared here has to end with the '_ASM' sufix to prevent
#	conflicts with other modules.
#

#	general source definitions
SRC_ASM	:=	\
			asm.c \
			instruct_check.c \
			instruct_display.c \
			instruct_free.c \
			instruct_debug.c \
			utils.c \
			read.c

$(ASM):	CFLAGS += -I./includes/asm
