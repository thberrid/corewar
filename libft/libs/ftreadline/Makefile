# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 13:46:46 by abaurens          #+#    #+#              #
#    Updated: 2019/10/02 21:45:52 by baurens          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LINKER	:=	gcc -r -nostdlib -o
NAME	:=	ftreadline

# SOURCES

KEYS	:=	key_up.c key_down.c key_left.c key_right.c key_end.c key_home.c
KEYS	:=	$(addprefix keys/, $(KEYS))

SRC		:=	$(KEYS) \
			ft_cmd/escape_sequences.c\
			ft_cmd/cmd_reader.c\
			ft_cmd/escape_sequences/escape_arrows.c\
			ft_cmd/escape_sequences/escape_end_begin.c\
			ft_dreadline.c\
			ft_inputrc.c	\
			ft_readline.c

include variables.mk
include rules.mk
override CFLAGS	+=	-ansi -pedantic
