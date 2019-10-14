# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 19:29:12 by abaurens          #+#    #+#              #
#    Updated: 2019/09/30 19:05:27 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LINKER	:=	gcc -r -nostdlib -o
NAME	:=	ftmatrix

SRC		:=	\
			add.c		\
			sub.c		\
			mul.c		\
			null.c 		\
			invert.c	\
			mul_vec4.c	\
			identity.c	\
			determinant.c

include variables.mk
include rules.mk
override CFLAGS	+=	-ansi -pedantic
