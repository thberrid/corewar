# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 19:29:12 by abaurens          #+#    #+#              #
#    Updated: 2019/09/30 19:21:10 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LINKER	:=	gcc -r -nostdlib -o
NAME	:=	ftvectors

##	Generic vectors sources
VEC		:=	\
			op_v.c		\
			op_x.c		\
			op_1.c		\
			op_len.c	\
			op_dot.c	\
			op_cross.c

VECI	:=	$(addprefix veci/,$(VEC))
VECF	:=	$(addprefix vecf/,$(VEC))
VECD	:=	$(addprefix vecd/,$(VEC))
VEC		:=	new.c set.c $(VECI) $(VECF) $(VECD)

##	Vec2 sources
VEC2	:=
VECI	:=	$(addprefix veci/,$(VEC2))
VECF	:=	$(addprefix vecf/,$(VEC2))
VECD	:=	$(addprefix vecd/,$(VEC2))
VEC2	:=	$(VECI) $(VECF) $(VECD)

VEC2	:=	$(VEC) $(VEC2)
VEC2	:=	$(addprefix vec2/,$(VEC2))

##	Vec3 sources
VEC3	:=
VECI	:=	$(addprefix veci/,$(VEC3))
VECF	:=	$(addprefix vecf/,$(VEC3))
VECD	:=	$(addprefix vecd/,$(VEC3))
VEC3	:=	$(VECI) $(VECF) $(VECD)

VEC3	:=	$(VEC) $(VEC3)
VEC3	:=	$(addprefix vec3/,$(VEC3))

##	Vec4 sources
VEC4	:=
VECI	:=	$(addprefix veci/,$(VEC4))
VECF	:=	$(addprefix vecf/,$(VEC4))
VECD	:=	$(addprefix vecd/,$(VEC4))
VEC4	:=	$(VECI) $(VECF) $(VECD)

VEC4	:=	$(VEC) $(VEC4)
VEC4	:=	$(addprefix vec4/,$(VEC4))

SRC	:=	$(VEC4) $(VEC3) $(VEC2)

include variables.mk
include rules.mk
override CFLAGS	+=	-ansi -pedantic
