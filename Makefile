# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 17:04:24 by cfiliber          #+#    #+#              #
#    Updated: 2021/11/03 15:41:46 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = \
		push_swap.c\
		checks.c\
		split.c\
		atoi.c\
		sort_small_stack.c\
		sort_big_stack.c\
		pre_big_sort.c\
		execute.c\
		operations.c\
		utils.c\
		utils_2.c\
		stack_utils.c\
		stack_utils_2.c\
		stack_utils_3.c\
		output.c\
		error_exit.c\

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