# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 06:46:14 by abaurens          #+#    #+#              #
#    Updated: 2019/10/20 22:22:19 by baurens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc -g
RM		:=	rm -rf
LINKER	:=	gcc -g -o
LIB		:=	libft/libft.a
COR		:=	corewar
ASM		:=	asm

SRCD	:=	srcs
OBJD	:=	objs

#
#	Operators files
#
OPS		:=	\
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
#
#	Common sources
#
SRC_COM	:=	$(addprefix ops/,$(OPS))\
			op.c	\
			endianes.c

#
#	Virtual Machine
#
SRC_COR	:=	\
			arena.c		\
			corewar.c	\
			cmd_parse.c

#
#	Compiler
#
SRC_ASM	:=	\
			asm.c \
			check_instru.c \
			ft_bprint.c \
			instruct_display.c \
			instruct_free.c \
			read.c

SRC_COR	:=	$(addprefix $(COR)/,$(SRC_COR)) $(SRC_COM)
SRC_ASM	:=	$(addprefix $(ASM)/,$(SRC_ASM)) $(SRC_COM)
OBJ_COR	:=	$(addprefix $(OBJD)/,$(SRC_COR:.c=.o))
OBJ_ASM	:=	$(addprefix $(OBJD)/,$(SRC_ASM:.c=.o))
SRC_COR	:=	$(addprefix $(SRCD)/,$(SRC_COR))
SRC_ASM	:=	$(addprefix $(SRCD)/,$(SRC_ASM))
DEP		:=	$(OBJ_ASM:.o=.d)

CFLAGS	:=	-I./includes -MMD -MP -W -Wall -Wextra -Werror

#
#	libft
#
CFLAGS	:=	$(CFLAGS) -I./$(dir $(LIB))includes
LDFLAGS	:=	-L./$(dir $(LIB)) -lft

all:	$(ASM)
#$(COR)

-include $(DEP)

$(ASM):	$(LIB) $(OBJ_ASM)
	$(LINKER) $(ASM) $(OBJ_ASM) $(LDFLAGS)

$(COR):	$(LIB) $(OBJ_COR)
	$(LINKER) $(COR) $(OBJ_COR) $(LDFLAGS)

$(OBJD)/%.o:	$(SRCD)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIB):	$(dir $(LIB))Makefile
	@make -C $(dir $(LIB))

clean:
	$(RM) $(OBJD)

fclean:
	$(RM) $(OBJD)
	$(RM) $(ASM)
	$(RM) $(COR)

cleanl: clean
	@make -C $(dir $(LIB)) clean

fcleanl: fclean
	@make -C $(dir $(LIB)) fclean

re:		fclean all

.PHONY: all clean fclean cleanl fcleanl re
