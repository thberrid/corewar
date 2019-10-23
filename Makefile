# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 06:46:14 by abaurens          #+#    #+#              #
#    Updated: 2019/10/23 10:13:44 by abaurens         ###   ########.fr        #
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

#	default rule is all
.DEFAULT_GOAL :=	all

#
#	Common sources
#
SRC_COM	:=	$(addprefix ops/,$(OPS))\
			endianes.c

#	Virtual Machine
include $(COR).mk

#	Compiler
include $(ASM).mk

SRC_COR	:=	$(addprefix $(COR)/,$(SRC_COR)) $(SRC_COM)
SRC_ASM	:=	$(addprefix $(ASM)/,$(SRC_ASM)) $(SRC_COM)
OBJ_COR	:=	$(addprefix $(OBJD)/,$(SRC_COR:.c=.o))
OBJ_ASM	:=	$(addprefix $(OBJD)/,$(SRC_ASM:.c=.o))
SRC_COR	:=	$(addprefix $(SRCD)/,$(SRC_COR))
SRC_ASM	:=	$(addprefix $(SRCD)/,$(SRC_ASM))
DEP		:=	$(OBJ_ASM:.o=.d) $(OBJ_COR:.o=.d)

CFLAGS	:=	-I./includes -MMD -MP -W -Wall -Wextra -Werror

#
#	libft
#
CFLAGS	:=	$(CFLAGS) -I./$(dir $(LIB))includes
LDFLAGS	:=	-L./$(dir $(LIB)) -lft

all:	$(ASM) $(COR)

-include $(DEP)

$(ASM):	CFLAGS += -DASM=1
$(ASM):	$(LIB) $(OBJ_ASM)
	$(LINKER) $(ASM) $(OBJ_ASM) $(LDFLAGS)

$(COR):	CFLAGS += -DVM=0
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
	$(RM) $(TESTER)
	$(RM) $(OBJD)
	$(RM) $(ASM)
	$(RM) $(COR)
	$(RM) tests

cleanl: clean
	@make -C $(dir $(LIB)) clean

fcleanl: fclean
	@make -C $(dir $(LIB)) fclean

re:		fclean all

.PHONY: all clean fclean cleanl fcleanl re
