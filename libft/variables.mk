# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 19:29:12 by abaurens          #+#    #+#              #
#    Updated: 2019/07/04 01:35:40 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################
#        YOU CAN EDIT THIS        #
###################################

RM		:=	rm -rf
CP		:=	cp -rf
LN		:=	ln -s
AR		:=	ar -rc
CC		:=	gcc
MKDIR	:=	mkdir -p

SRCD	:=	srcs
OBJD	:=	objs

## either STATIC(.a) or DYNAMIC/SHARED(.so)
LIB_MODE	:=	STATIC

SUB_EXT	:=	.ao

###################################
#        BUT NOT EDIT THIS        #
###################################
include .private/dep.mk
ifeq ($(CAN_RUN),TRUE)
PWD		:=	$(dir $(abspath $(firstword $(MAKEFILE_LIST))))
ROOT	:=	$(shell echo $(PWD) | sed 's:libft/.*:libft/:g')
PVMK	:=	$(ROOT).private/
LIBS_D	:=	$(ROOT)libs
include $(PVMK)termcaps.mk
include $(PVMK)functions.mk
include $(PVMK)variables.mk
endif
