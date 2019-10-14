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

NULL			:=	/dev/null

override SECONDARY		:=	tr		\
							sed		\
							awk		\
							cut		\
							sort	\
							echo	\
							printf	\
							ranlib	\
							$(SHELL)

override WHICH			:=	$(shell which which >$(NULL) 2>&1 || echo 'X')

override DEPENDANCIES	:=	$(firstword $(RM))	\
							$(firstword $(CP))	\
							$(firstword $(LN))	\
							$(firstword $(CC))	\
							$(firstword $(AR))	\
							$(firstword $(MKDIR))

ifneq ($(WHICH),X)

override MISSING_SECONDARY	:=	$(strip \
	$(foreach dep,\
		$(SECONDARY),\
		$(shell which $(dep) >$(NULL) 2>&1 || echo '$(dep)')\
	)\
)

override MISSING	:=	$(strip \
	$(foreach dep,\
		$(DEPENDANCIES),\
		$(shell which $(dep) >$(NULL) 2>&1 || echo '$(dep)')\
	)\
)

override CAN_RUN	:=	$(if $(MISSING),FALSE,TRUE)

ifneq ($(FANCY_MODE),FALSE)
override FANCY_MODE	:=	$(if $(MISSING_SECONDARY),FALSE,TRUE)
endif
endif

override CAN_RUN ?= TRUE
override FANCY_MODE ?= FALSE
