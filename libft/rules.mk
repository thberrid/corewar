# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 19:29:12 by abaurens          #+#    #+#              #
#    Updated: 2019/07/04 01:35:40 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(NAME):	$(OBJ)
	@$(LINKER) $(NAME) $(OBJ) $(strip $(LDFLAGS))
ifeq ($(LINKER), ar rc)
	@ranlib $(NAME)
endif

-include $(DEP)

ifeq ($(FANCY_MODE),TRUE)

$(OBJD)/%.o:	$(SRCD)/%.c Makefile
	@if [[ $(CMPT) -ne 0 ]];then printf "$(CURUP)"; else printf "$(CURSV)"; fi
	$(call increment,$(CMPT),CMPT)
	$(eval PRC = $(call purcent,$(CMPT),$(FCNT)))
	@$(call progressbar,$(PRC),BAR)
	@printf $(LINE) $(SUBID) $(TOTAL_SIZE) $(call filename,$(NAME)) \
		$(shell echo $(PRC)) $(CMPT) $(FCNT) "$(BAR)"
	@mkdir -p $(dir $@)
ifndef NO_NOTE
	@$(CC) $(strip $(CFLAGS)) -o $@ -c $<
else #NO_NOTE
	@2>&1 $(CC) $(strip $(CFLAGS)) -o $@ -c $< | sed $(NO_NOTE)
endif #NO_NOTE

clean:
	$(call pinfo,Cleaning $(call filename,$(NAME)))
	@$(RM) $(DEP)
	@$(RM) $(OBJD)

fclean:
	$(call pinfo,Fcleaning $(call filename,$(NAME)))
	@$(RM) $(DEP)
	@$(RM) $(OBJD)
	@$(RM) $(NAME)

else#FANCY_MODE

$(OBJD)/%.o:	$(SRCD)/%.c Makefile
	@$(MKDIR) $(dir $@)
	$(CC) $(strip $(CFLAGS)) -o $@ -c $<

clean:
	$(RM) $(DEP)
	$(RM) $(OBJD)

fclean:
	$(RM) $(DEP)
	$(RM) $(OBJD)
	$(RM) $(NAME)

endif#FANCY_MODE

all:	$(NAME)

re:		fclean all

.PHONY: all clean fclean re
