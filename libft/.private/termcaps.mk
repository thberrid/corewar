# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    termcaps.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 19:29:12 by abaurens          #+#    #+#              #
#    Updated: 2019/07/04 01:35:40 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_TYPE	=	RGB

TPUT		:=	2>/dev/null tput

ENABELED	:=	$(if $(shell $(TPUT) -V),1,)

TCOL		:=	$(TPUT) setaf
TCOL		:=	$(if $(ENABELED),$(TPUT) setaf,printf '%d' > /dev/null)

ifeq ($(COLOR_TYPE),RGB)
BLK			=	$(call rgbcol,0, 0, 0)
RED			=	$(call rgbcol,255,0,0)
GRN			=	$(call rgbcol,0,255,0)
BLE			=	$(call rgbcol,0,0,255)
CYA			=	$(call rgbcol,0,255,255)
MAG			=	$(call rgbcol,255,0,255)
YEL			=	$(call rgbcol,255,255,0)
WHT			=	$(call rgbcol,255,255,255)
endif

#	Preffered
ifneq (,$(ENABELED))
GRN			?=	$(shell $(TCOL) 46)
BLE			?=	$(shell $(TCOL) 12)
CYA			?=	$(shell $(TCOL) 14)
MAG			?=	$(shell $(TCOL) 13)
RED			?=	$(shell $(TCOL) 9)
endif

#	Standard
BLK			?=	$(shell $(TCOL) 0)
RED			?=	$(shell $(TCOL) 1)
GRN			?=	$(shell $(TCOL) 2)
YEL			?=	$(shell $(TCOL) 3)
BLE			?=	$(shell $(TCOL) 4)
MAG			?=	$(shell $(TCOL) 5)
CYA			?=	$(shell $(TCOL) 6)
WHT			?=	$(shell $(TCOL) 7)

NRM			:=	$(if $(ENABELED),$(shell $(TPUT) sgr0),)
CURUP		:=	$(if $(ENABELED),$(shell $(TPUT) cuu1),\e[A)
CURSV		:=	$(shell $(TPUT) sc)
CURLD		:=	$(shell $(TPUT) rc)
CLEAR		:=	$(shell $(TPUT) el)
