#
#	here are the corewar's virtual machine specific makefiles variables.
#	each variables declared here has to end with the '_COR' sufix to prevent
#	conflicts with other modules.
#

#	Operators files
OPS_COR	:=	\
			op_or.c		\
			op_ld.c		\
			op_st.c		\
			op_add.c	\
			op_sub.c	\
			op_and.c	\
			op_xor.c	\
			op_ldi.c	\
			op_sti.c	\
			op_lld.c	\
			op_aff.c	\
			op_lldi.c	\
			op_live.c	\
			op_zjmp.c	\
			op_fork.c	\
			op_lfork.c
OPS_COR	:=	$(addprefix ops/,$(OPS_COR))

#	general source definitions
SRC_COR	:=	$(OPS_COR)	\
			ocp.c		\
			loop.c		\
			utils.c		\
			arena.c		\
			corewar.c	\
			process.c	\
			cmd_parse.c

#
#	vm unit tests
#
TESTER	:=	tester

SRC_TST	:=	\
			main.c		\
			random.c	\
			file_gen.c
SRC_TST	:=	$(addprefix $(TESTER)/,$(SRC_TST)) $(SRC_COM)

OBJ_TST	:=	$(addprefix $(OBJD)/,$(SRC_TST:.c=.o))
SRC_TST	:=	$(addprefix $(SRCD)/,$(SRC_TST))
DEP_TST	:=	$(OBJ_TST:.o=.d)


-include $(DEP_TST)

$(COR):	CFLAGS += -ansi -pedantic -DVM

$(TESTER):	CFLAGS += -DTESTER=2
$(TESTER): $(OBJ_TST)
	$(LINKER) $(TESTER) $(OBJ_TST) $(LDFLAGS)
