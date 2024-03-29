# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:49:20 by ggiannit          #+#    #+#              #
#    Updated: 2022/10/28 20:55:32 by ggiannit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

PRNAME = ft_printf

ARNAME = libftprintf.a 
BNUS = bonus
ARDIR  =

NAME = $(addprefix $(ARDIR),$(ARNAME))
INCLUDE = include

###### VARIABLE ######

DIRSRCS = src/
DIROBJS = obj/

FLSRCS = ft_printf.c ft_struct.c ft_checkstring.c ft_getnewpc.c \
	 ft_prepare_cs.c ft_prepare_id.c ft_prepare_p.c ft_prepare_u.c \
	 ft_prepare_x.c ft_handle_zeros.c ft_put.c ft_lutoa.c	

FLOBJS = ${FLSRCS:.c=.o}

SRCS = $(addprefix $(DIRSRCS),$(FLSRCS))
OBJS = $(addprefix $(DIROBJS),$(FLOBJS))

CC = gcc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

#.c.o:
$(DIROBJS)%.o: $(DIRSRCS)%.c
	@echo "$(YELLOW)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

####### RULES ########

all: libft ${NAME}

${NAME}: starting ${OBJS}
	@echo ""
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}$(DEF_COLOR)"
	@echo "$(YELLOW)- Flags: $(WHITE)${CFLAGS}$(DEF_COLOR)"
	@echo "$(GREEN)*******************************************$(DEF_COLOR)"
	@echo ""
	@${AR} -rcs ${NAME} ${OBJS}
	@echo "$(YELLOW)Archive created with $(WHITE)${AR}$(YELLOW) as $(CYAN)${ARNAME}$(DEF_COLOR)"
	@echo ""

clean: libftclean
	@echo "$(WHITE)\"wait.. is $(CYAN)${PRNAME}$(WHITE) all trash? 🧹\" $(DEF_COLOR)"
	@sleep 0.5
	@${RM} ${OBJS} 
	@echo "$(RED)All objects removed with $(WHITE)${RM}$(DEF_COLOR)"
	@echo ""

fclean: clean
	@echo "$(WHITE)\"...it's always as been 🚮\" $(DEF_COLOR)"
	@sleep 0.5
	@${RM} ${ARNAME} 
	@echo "$(RED)..and $(CYAN)${ARNAME} $(RED)as been removed$(DEF_COLOR)"
	@echo ""

libft:
	cd libft && ${MAKE}

libftclean:
	cd libft && ${MAKE} clean

libftre:
	cd libft && ${MAKE} re

re: fclean all

starting:
	@echo "$(WHITE)👷🦺\"Let's build somre real $(CYAN)${PRNAME}$(WHITE) sh3t!\"🔨🔧$(DEF_COLOR)"
	@sleep 0.4

.PHONY: all clean fclean re starting .c.o libft libftclean libftre
.SUFFIXES: .c .o 
