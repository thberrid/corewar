# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 19:29:12 by abaurens          #+#    #+#              #
#    Updated: 2019/09/09 16:44:19 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LINKER	:=	gcc -r -nostdlib -o
NAME	:=	ftcipher

# SOURCES

CORE	:=	cipher_core.c
CORE	:=	$(addprefix core/, $(CORE))

SRC		:=	$(CORE)	\
			ft_cipher.c

include variables.mk
include rules.mk
override CFLAGS	+=	-ansi -pedantic
