/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:15:04 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/30 12:54:38 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	int				content;
	struct s_list  *next;
}				t_list;

typedef struct s_vec2
{
	int	begin;
	int	end;
	int	size;
}				t_vec2;

//push_swap.c
int             main(int argc, char **argv);

//checks.c
int *ft_pre_check(int argc, char **argv);
int	*ft_check(int argc, char **argv);
int	ft_check_doubles(int argc, int *arr);

//split.c
char			**ft_split(char const *s, char c);

//atoi.c
int	ft_atoi(const char *str);
int ft_pre_atoi(const char *str);
int ft_check_toolong_int(char c, int num, int sign);

//utils.c
void	ft_free_mtx(char **mtx);
int ft_mtx_size(char **mtx);
int	ft_arr_size(int *arr);
int	ft_isdigit(char *str);
size_t	ft_strlen(const char *s);

//output.c
void	ft_putendl(char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);

//error.c
void ft_err_exit(void);

#endif
