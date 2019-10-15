# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 06:46:14 by abaurens          #+#    #+#              #
#    Updated: 2019/10/15 08:51:56 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:=	gcc
RM		:=	rm -rf
LINKER	:=	gcc -o
LIB		:=	libft/libft.a
COR		:=	corewar
ASM		:=	asm

SRCD	:=	srcs
OBJD	:=	objs

#
#	Common sources
#
SRC_COM	:=	\
			op.c	\
			endianes.c

#
#	Virtual Machine
#
SRC_COR	:=	\
			main_1.c

#
#	Compiler
#
SRC_ASM	:=	\
			main_2.c

SRC_COR	:=	$(addprefix $(COR)/,$(SRC_COR)) $(SRC_COM)
SRC_ASM	:=	$(addprefix $(ASM)/,$(SRC_ASM)) $(SRC_COM)
OBJ_COR	:=	$(addprefix $(OBJD)/,$(SRC_COR:.c=.o))
OBJ_ASM	:=	$(addprefix $(OBJD)/,$(SRC_ASM:.c=.o))
SRC_COR	:=	$(addprefix $(SRCD)/,$(SRC_COR))
SRC_ASM	:=	$(addprefix $(SRCD)/,$(SRC_ASM))
DEP		:=	$(OBJ_COR:.o=.d) $(OBJ_ASM:.o=.d)

CFLAGS	:=	-I./includes -W -Wall -Wextra -Werror -MMD -MP

#
#	libft
#
CFLAGS	:=	$(CFLAGS) -I./$(dir $(LIB))includes
LDFLAGS	:=	-L./$(dir $(LIB)) -lft

all:	$(ASM) $(COR)

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
	make -C $(dir $(LIB)) clean

fcleanl: fclean
	make -C $(dir $(LIB)) fclean

re:		fclean all

.PHONY: all clean fclean cleanl fcleanl re
