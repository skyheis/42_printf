# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:49:20 by ggiannit          #+#    #+#              #
#    Updated: 2022/10/28 20:09:21 by ggiannit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

PRNAME = libft

ARNAME = libftprintf.a 
ARDIR  = ../

NAME = $(addprefix $(ARDIR),$(ARNAME))
INCLUDE = ../include

###### VARIABLE ######

DIRSRCS = src/
DIROBJS = obj/

FLSRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
       ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c \
       ft_atoi.c ft_calloc.c ft_tolower.c ft_toupper.c \
       ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
       ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
       ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstmap.c

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

all: ${NAME}

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

clean:
	@echo "$(WHITE)\"wait.. is $(CYAN)${PRNAME}$(WHITE) all trash? 🧹\" $(DEF_COLOR)"
	@sleep 0.5
	@${RM} ${OBJS} 
	@echo "$(RED)All objects removed with $(WHITE)${RM}$(DEF_COLOR)"
	@echo ""

fclean: clean
	@echo "$(WHITE)\"...it's always as been 🚮\" $(DEF_COLOR)"
	@sleep 0.5
	@echo "$(RED)..and $(CYAN)${ARNAME} $(RED)as been removed$(DEF_COLOR)"
	@echo ""

re: fclean all

starting:
	@echo "$(WHITE)👷🦺\"Let's build somre real $(CYAN)${PRNAME}$(WHITE) sh3t!\"🔨🔧$(DEF_COLOR)"
	@sleep 0.4

.PHONY: all clean fclean re starting .c.o
.SUFFIXES: .c .o 
