#
#	here are the corewar's assembler compiler specific makefiles variables.
#	each variables declared here has to end with the '_ASM' sufix to prevent
#	conflicts with other modules.
#

#	general source definitions
SRC_ASM	:=	\
			asm.c \
			instruct_check.c \
			check_get.c \
			check_getparam.c \
			check_str.c \
			instruct_display.c \
			instruct_free.c \
			instruct_get.c \
			instruct_debug.c \
			debug_default.c \
			debug_push.c \
			utils.c \
			read.c \
			read_utils.c

$(ASM):	CFLAGS += -I./includes/asm
