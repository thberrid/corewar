# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/04 00:51:05 by abaurens          #+#    #+#              #
#    Updated: 2019/10/14 17:10:37 by abaurens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include	variables.mk

NAME	:=	libft.a
SONM	:=	libft.so

ifeq ($(FANCY_MODE),TRUE)

override LDFLAGS =	-L. -lft

CC		:=	$(MAKE) --no-print-dir -I$(ROOT) -C
else
CC		:=	$(MAKE) -w -I$(ROOT) -C
endif
LINKER	:=	$(AR)

LIBS	:=	\
			ftio		\
			ftlib		\
			ftmath		\
			ftregex		\
			ftcipher	\
			ftmatrix	\
			ftvectors	\
			ftreadline
LIBS	:=	$(addsuffix $(SUB_EXT),$(LIBS))

ifeq ($(FANCY_MODE),TRUE)
LIBS	:=	$(shell echo $(LIBS)|tr ' ' '\n'|awk '{print length,$$0}'|sort -n|\
			cut -d' ' -f2)
endif
LIBS	:=	$(addprefix $(LIBS_D)/, $(LIBS))
ifeq ($(FANCY_MODE),TRUE)
MAX_LEN	:=	$(shell echo $(basename $(notdir $(lastword $(LIBS))))|\
			awk '{print length}')
endif

VAR_	:=	$(strip $(foreach mk, $(LIBS),\
	$(shell $(CC) $(basename $(mk)) -q || $(RM) $(mk))))

ifeq ($(CAN_RUN),TRUE)
.DEFAULT:	$(NAME)
ifeq ($(FANCY_MODE),TRUE)
$(NAME):	$(LIBS)
	@$(LINKER) $(NAME) $(LIBS)
	@ranlib $(NAME)
	@$(call pinfo,DONE!)
else
$(NAME):	$(LIBS)
	$(LINKER) $(NAME) $(LIBS)
	ranlib $(NAME)
endif

$(SONM):	override CFLAGSTO ?= -fPIC
ifeq ($(FANCY_MODE),TRUE)
$(SONM):	$(LIBS)
	@gcc -shared -o libft.so $(LIBS)
	@$(call pinfo,DONE!)
else
$(SONM):	$(LIBS)
	gcc -shared -o libft.so $(LIBS)
endif

so:	$(SONM)

ifeq ($(FANCY_MODE),TRUE)

CLEAN_DEFINED	:=	TRUE

clean:
	@$(RM) $(OBJD)
	@$(RM) $(LIBS)
	@$(foreach CMD,$(basename $(LIBS)),$(CC) $(CMD) clean;)

fclean:
	@$(RM) $(NAME)
	@$(RM) $(SONM)
	@$(RM) $(LIBS)
	@$(foreach CMD,$(basename $(LIBS)),$(CC) $(CMD) fclean;)
endif
else

.DEFAULT:	$(NAME)
$(NAME):
	@$(error missing dependencie(s): $(foreach dep,$(MISSING),'$(dep)'))
	@which -v $(firstword $(MISSING)) >$(NULL) 2>&1

endif

ifneq ($(CLEAN_DEFINED),TRUE)
clean:
	$(RM) $(OBJD)
	$(RM) $(LIBS)
	@$(foreach CMD,$(basename $(LIBS)),$(CC) $(CMD) clean;)

fclean:
	$(RM) $(NAME)
	$(RM) $(SONM)
	$(RM) $(LIBS)
	@$(foreach CMD,$(basename $(LIBS)),$(CC) $(CMD) fclean;)
endif

ifeq ($(LIB_MODE),$(or $(findstring DYNAMIC,$(LIB_MODE)),$(findstring SHARED,$(LIB_MODE))))
all:	$(SONM)
else
all:	$(NAME)
endif

re:		fclean all

.PHONY:	all clean fclean re so
