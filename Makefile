# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:49:20 by ggiannit          #+#    #+#              #
#    Updated: 2022/10/17 17:07:42 by ggiannit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = libftprintf.a
BNUS = bonus

###### VARIABLE ######

SRCS = ft_struct.c 

OBJS = ${SRCS:.c=.o}

#BNSRCS = 
#BNOBJS = ${BNSRCS:.c=.o}

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

all: libft ${NAME}

${NAME}: ${OBJS}
	@echo "==++==++== CREATE/UPDATE ARCHIVE ==++==++="
	${AR} -rcs ${NAME} ${OBJS}
	@echo ""


${BNUS}: all

clean:
	@echo "==++===++=== CLEAN ALL OBJECTS ===++==++=="
	${RM} ${OBJS} 
	@echo ""

fclean: libftfclean clean
	@echo "==++===++==== DELETE ARCHIVE ====++===++=="
	${RM} ${NAME}
	@echo ""
	@echo "==++===++==== ==++==++==++== ====++===++=="

libft:
	cd libft && ${MAKE}

libftclean:
	cd libft && ${MAKE} clean

libftfclean:
	cd libft && ${MAKE} fclean

libftre:
	cd libft && ${MAKE} re

re: fclean libftfclean all

.PHONY: all clean fclean re .c.o libft libftclean libftfclean libftre
.SUFFIXES: .c .o 
