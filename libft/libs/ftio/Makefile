# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 16:08:06 by abaurens          #+#    #+#              #
#    Updated: 2019/10/02 13:43:24 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LINKER	:=	gcc -r -nostdlib -o
NAME	:=	ftio

NO_NOTE	:=	':a;N;s/\n/&/1;Ta;/: note: .*ABI.*/!{P;D};:b;N;s/\n/&/3;Tb;d'

# SOURCES

STRCNV	:=	chtoa_base.c		\
			padded_lltoa.c		padded_ulltoa_hexa.c	\
			padded_ulltoa.c		padded_ulltoa_octal.c	\
			padded_ulltoa_bin.c	ft_ldtoa_scientific.c
STRCNV	:=	$(addprefix tostr_conv/, $(STRCNV))

IOCORE	:=	core.c		parse_args.c		\
			flags.c		ft_get_errno.c		\
			buffer.c	list_manager.c		\
			big_num.c	bankers_round.c		\
			unicode.c	floating_point.c	\
			arg_mgr.c	argument_getter.c	\
			ft_error.c	parser_functions.c	\
			preparse.c	va_lst_cpy.c
IOCORE	:=	$(addprefix core/, $(IOCORE))

BFLOAT	:=	add.c	utils.c		\
			mul.c	to_string.c	\
			set.c	instance.c
BFLOAT	:=	$(addprefix bfloat/, $(BFLOAT))

DRAGON	:=	bint.c		bint_div.c	bint_sub.c		\
			bint_add.c	bint_mul.c	bint_shift.c	\
			bint_cmp.c	bint_pow.c	bint_utils.c
DRAGON	:=	$(addprefix bigint/,$(DRAGON))
DRAGON	:=	$(DRAGON) dragon_buffer.c	ft_ldtoa.c
DRAGON	:=	$(addprefix dragon4/,$(DRAGON))

IOCONV	:=	$(addprefix uhexa/,uhexa.c h_len.c h_exotic.c)			\
			$(addprefix integer/,integer.c len.c exotic.c)			\
			$(addprefix length/,length.c l_len.c l_exotic.c)		\
			$(addprefix uoctal/,uoctal.c o_len.c o_exotic.c)		\
			$(addprefix ubinary/,ubinary.c b_len.c b_exotic.c)		\
			$(addprefix uinteger/,uinteger.c u_len.c u_exotic.c)	\
			char.c			npchar.c		string.c				\
			pointer.c		percent.c		dbl_hex.c				\
			npstring.c		iso_date.c		strerror.c				\
			dbl_compact.c	dbl_floating.c	dbl_scientific.c
IOCONV	:=	$(addprefix convert/,$(IOCONV))

GNL		:=	\
			gnl_rd_check.c	gnl_cat.c	gnl_buffer.c	\
			fdline.c		sfdline.c	cfdline.c
GNL		:=	$(addprefix gnl/,$(GNL))

SRC		:=	\
			$(DRAGON)	\
			$(IOCORE)	$(IOCONV)	\
			$(STRCNV)	$(BFLOAT)	\
			$(CMD_RD)	$(GNL)		\
			gnl.c				cgnl.c				sgnl.c				\
			ft_atoi.c			ft_atol.c			ft_itoa.c			\
			ft_flags.c			ft_debugf.c			ft_putstr.c			\
			ft_printf.c			ft_putnbr.c			ft_fprintf.c		\
			ft_sprintf.c		ft_dprintf.c		ft_snprintf.c		\
			ft_putchar.c		ft_putendl.c		ft_asprintf.c		\
			ft_putnbr_fd.c		ft_putstr_fd.c		ft_putendl_fd.c		\
			ft_atol_base.c		ft_putchar_fd.c		ft_printf_error.c	\
			ft_putnbr_base.c	ft_putnbr_base_fd.c


include variables.mk
override CFLAGS += -ansi -pedantic
include rules.mk
