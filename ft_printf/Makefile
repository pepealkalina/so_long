# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 15:48:39 by preina-g          #+#    #+#              #
#    Updated: 2022/10/10 13:13:31 by preina-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs

NAME = libftprintf.a

INCLUDE = ft_printf.h

SRC = ft_printf.c ft_printf_utils.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f *.o

fclean:
	rm -f *.o $(NAME)


re:	fclean all