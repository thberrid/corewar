# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    functions.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 19:29:12 by abaurens          #+#    #+#              #
#    Updated: 2019/07/04 01:35:40 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifndef COLOR_TYPE
#include $(ROOT)private/termcaps.mk
#endif

###########################
#          Maths          #
###########################
define increment
@$(eval TMP = $(shell echo '$(1) + 1' | bc))
$(eval $(2) := $$(TMP))
endef

define purcent
$(shell echo '$(1)/$(2)*100'|bc -l|sed 's/^\./0./'|sed -E 's:\.[0-9]{20}::')
endef

define lerpi
$(shell Vmi=$(1);
		Vma=$(2);
		Vpr=$(3);
		dif=`echo "$$Vma - $$Vmi"|bc -l`;
		echo "$$Vpr * $$dif + $$Vmi"|bc -l|
		sed 's/^\./0./'|sed -E 's:\.[0-9]{20}::')
endef

define lerpf
$(shell Vmi=$(1);
		Vma=$(2);
		Vpr=$(3);
		dif=`echo "$$Vma - $$Vmi"|bc -l`;
		echo "$$Vpr * $$dif + $$Vmi"|bc -l|sed 's/^\./0./')
endef

define toint
$(shell echo '$(1)'|sed 's/^\./0./'|sed -E 's:\.[0-9]{20}::')
endef

define tofloat
$(shell echo '$(1)'|sed 's/^\./0./')
endef

define computei
$(shell echo '$(1)'|bc -l|sed 's/^\./0./'|sed -E 's:\.[0-9]{20}::')
endef

define computef
$(shell echo '$(1)'|bc -l|sed 's/^\./0./')
endef

###########################
#         termcaps        #
###########################
ifeq ($(COLOR_TYPE),RGB)
define rgbcol
$(shell LC_NUMERIC=C;printf '\e[38;2;%.f;%.f;%.fm' $(1) $(2) $(3))
endef
else
rgbcol	:=	$(MAG)
endif

###########################
#         Printing        #
###########################
define vinfo
	@$(eval LEN = $(shell printf '$(1)'|awk '{print length}'))
	@$(eval MOD = $(shell echo "$(LEN)%2"|bc))
	@$(eval DASH = $(shell seq 1 $(shell echo "37-$(LEN)/2"|bc)))
	$(eval FTRES = $(shell printf '$(GRN)<-';\
		for i in $(DASH); do printf "-"; done;\
		printf " $(1) "; if [[ $(MOD) -eq 0 ]]; then printf '-'; fi;\
		for i in $(DASH); do printf "-"; done;\
		printf '>$(NRM)'))
	$(eval $(2) := $$(FTRES))
endef

define pinfo
	@$(call vinfo,$(1),PINFO)
	@printf '$(PINFO)\n'
endef

define progressbar
@$(eval MAX = 42)
@$(eval NORM = $(shell echo '$(1)/100'|bc -l))
@$(eval NORM = $(call computef,$(1) / 100))
@$(eval R = $(call lerpf,255,0,$(NORM)))
@$(eval G = $(call lerpf,0,255,$(NORM)))
@$(eval B = $(call lerpf,0,255,$(NORM)))
@$(eval LEN = $(call computei,$(NORM) * $(MAX)))
@$(eval RES = $(shell LC_NUMERIC=C;
	printf '$(call rgbcol,$(R),$(G),$(B))[';
	for I in $(shell seq 1 $(MAX)); do
		if [[ $$I -le $(LEN) ]]; then
			printf '=';
		else
			printf ' ';
		fi;
	done;
	printf ']$(NRM)'))
$(eval $(2) := $$(RES))
endef

###########################
#    String processing    #
###########################
define filename
$(notdir $(basename $(1)))
endef

define libpath
$(LIBS_D)/$(1)$(SUB_EXT)
endef
