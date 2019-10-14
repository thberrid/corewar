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

CMPT	:=	0

ifneq ($(SHELL),/bin/sh)
override SHELL := /bin/sh
endif

FCNT	:=	$(words $(SRC))

INCLDS	:=	-I$(ROOT)includes

LIB_MODE	?=	STATIC
ifneq ($(LIB_MODE),STATIC)
ifneq ($(LIB_MODE),SHARED)
ifneq ($(LIB_MODE),DYNAMIC)
LIB_MODE	:=	STATIC
endif
endif
endif

ifndef CFLAGS
override CFLAGS	=	$(INCLDS)
else
override CFLAGS += $(INCLDS)
endif
override CFLAGS	+= -MMD -MP -W -Wall -Wextra -Werror

OBJ		:=	$(addprefix $(OBJD)/,$(SRC:.c=.o))
SRC		:=	$(addprefix $(SRCD)/,$(SRC))
DEP		:=	$(OBJ:.o=.d)

LINE	:=	" [$(CYA)%d/%d$(NRM)] $(RED)%-$(MAX_LEN)s$(NRM) $(CYA)[%3d%%] \
[%3d / %3d] %s$(NRM)\n"

SUBID		?=	1
TOTAL_SIZE	?=	1
MAX_LEN		?=	1

ifneq ($(PWD), $(ROOT))
NAME	:=	$(addsuffix $(SUB_EXT),$(addprefix $(LIBS_D)/,$(NAME)))
endif

# RULES

ifeq ($(FANCY_MODE),TRUE)
%$(SUB_EXT):
	@$(call vinfo,Compiling...,TEXT)
	@if [[ $(CMPT) -eq 0 ]]; then printf "$(TEXT)\n"; fi
	$(eval FCNT	:= $(words $(LIBS)))
	$(eval CMPT := $(shell echo $(CMPT) + 1 | bc))
	@$(CC) $(basename $@) CFLAGS=$(CFLAGSTO) SUBID=$(CMPT) TOTAL_SIZE=$(FCNT) MAX_LEN=$(MAX_LEN)
else
%$(SUB_EXT):
	$(CC) $(basename $@) CFLAGS=$(CFLAGSTO) SUBID=$(CMPT) TOTAL_SIZE=$(FCNT) MAX_LEN=$(MAX_LEN)
endif
