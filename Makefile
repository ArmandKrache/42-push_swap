# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrache <akrache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 16:06:11 by akrache           #+#    #+#              #
#    Updated: 2019/11/02 20:47:34 by akrache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH = push_swap

CHECK = checker

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS_P = push_swap.c stack.c ope.c parsing.c tools.c small_ps.c algo.c small_ps2.c four.c tools2.c ft_strsplit.c

SRCS_C = checker.c stack.c ope.c parsing_checker.c parsing.c tools.c tools2.c ft_strsplit.c

OBJECT_P = $(SRCS_P:.c=.o)

OBJECT_C = $(SRCS_C:.c=.o)

LIBFT = libft/libft.a

all : $(PUSH) $(CHECK)

$(PUSH) : $(OBJECT_P)
	$(CC) $(FLAGS) -I/usr/local/include $(OBJECT_P) -o $(PUSH)

$(CHECK) : $(OBJECT_C)
	$(CC) $(FLAGS) -I/usr/local/include  $(OBJECT_C) -o $(CHECK)

%.o: %.c push_swap.h
	$(CC) -I/usr/local/include -o $@ -c $< $(FLAGS)

clean:
	/bin/rm -rf $(OBJECT_P) $(OBJECT_C)

fclean: clean
	/bin/rm -rf $(PUSH) $(CHECK)

re: fclean all

.PHONY: clean fclean all re