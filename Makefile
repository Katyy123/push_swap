# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 17:04:24 by cfiliber          #+#    #+#              #
#    Updated: 2021/10/30 12:55:43 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
		push_swap.c\
		utils.c\
		atoi.c\
		checks.c\
		output.c\
		split.c\
		error.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -g $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
						rm -f $(OBJS)

fclean: clean
						rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re