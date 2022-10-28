# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:49:20 by ggiannit          #+#    #+#              #
#    Updated: 2022/10/27 13:04:07 by ggiannit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = ../libftprintf.a
BNUS = bonus

###### VARIABLE ######

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
       ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c \
       ft_atoi.c ft_calloc.c ft_tolower.c ft_toupper.c \
       ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
       ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
       ft_strmapi.c ft_striteri.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = ${SRCS:.c=.o}

BNSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	 ft_lstsize.c ft_lstlast.c ft_lstiter.c ft_lstmap.c
BNOBJS = ${BNSRCS:.c=.o}

CC = gcc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

####### RULES ########

all: ${NAME}

${NAME}: ${OBJS} ${BNOBJS}
	@echo "===++== CREATE/UPDATE LIBFT ARCHIVE ==++=="
	${AR} -rcs ${NAME} ${OBJS} ${BNOBJS}
	@echo ""

clean:
	@echo "====++=== CLEAN ALL LIBFT OBJECTS ===++==="
	${RM} ${OBJS} ${BNOBJS}
	@echo ""

fclean: clean
	@echo "====++==== DELETE LIBFT ARCHIVE ====++===="
	${RM} ${NAME}
	@echo ""
	@echo "====++==== ==++==++==++== ====++===="

re: fclean all

.PHONY: all clean fclean re .c.o
.SUFFIXES: .c .o 
