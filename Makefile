# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggiannit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 17:49:20 by ggiannit          #+#    #+#              #
#    Updated: 2022/10/23 21:41:20 by ggiannit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####### NAME #########

NAME = libftprintf.a
BNUS = bonus

###### VARIABLE ######

SRCS = ft_printf.c ft_struct.c ft_checkstring.c ft_getnewpc.c \
       ft_prepare_cs.c ft_prepare_id.c ft_prepare_p.c ft_prepare_u.c \
       ft_prepare_x.c ft_handle_zeros.c

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
