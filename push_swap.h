/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:15:04 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 12:12:27 by cfiliber         ###   ########.fr       */
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

/*push_swap.c*/
int             main(int argc, char **argv);
void	ft_create_list(t_list **lst_a, t_list **lst_b, int *arr);

/*checks.c*/
int	*ft_pre_check(int argc, char **argv);
int	*ft_check_1arg(int argc, char **argv);
int	*ft_check_2args(int argc, char **argv);
int	ft_check_doubles(int argc, int *arr);
int	ft_arr_is_sorted(int *arr);

/*split.c*/
char			**ft_split(char const *s, char c);

/*atoi.c*/
int	ft_atoi(const char *str);
int ft_pre_atoi(const char *str);
int ft_check_toolong_int(char c, int num, int sign);

/*sort_small_stack.c*/
void	ft_sort_small_stack(t_list **lst_a, t_list **lst_b);
void	ft_sort_2_3(t_list **lst_a, t_list **lst_b);
int	ft_sort_4(t_list **lst_a, t_list **lst_b);
int	ft_sort_5(t_list **lst_a, t_list **lst_b);

/*sort_big_stack.c*/
void	ft_sort_big_stack(t_list **lst_a, t_list **lst_b);
int	ft_sort(t_list **lst_a, t_list **lst_b, int index);
void	ft_replace_nums_in_lst(t_list *lst_a, int *sorted_arr);

/*pre_big_sort.c*/
int	*ft_create_sorted_arr(t_list *lst_a, t_list *lst_b);
void	ft_put_index_in_lst(t_list *list, int *sorted_arr);
int	ft_binary_maxnum_len(t_list *lst_a);

/*execute.c*/
void	ft_execute(t_list **lst_a, t_list **lst_b, char *str);
int	ft_execute_push(t_list **lst_a, t_list **lst_b, char *str);

/*operations.c*/
void	ft_swap(t_list *lst);
void	ft_rotate(t_list *lst);
void	ft_rrotate(t_list *lst);

/*utils.c*/
void	ft_free_mtx(char **mtx);
int ft_mtx_size(char **mtx);
int	ft_arr_size(int *arr);
int	ft_isdigit(char *str);
size_t	ft_strlen(const char *s);

/*utils_2.c*/
int	ft_strncmp(const char *s1, const char *s2, int n);

/*stack_utils.c*/
int	ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

/*stack_utils_2.c*/
void	ft_free_lst(t_list *lst);
int	ft_lst_index(t_list *list, int num);
int	ft_lst_min(t_list *list);
int	ft_lst_max(t_list *list);

/*stack_utils_3.c*/
t_list	*ft_copy_list(t_list *list);
void	ft_remove_elem_lst(t_list **begin_list, int num);
int	ft_lst_is_sorted(t_list *lst);

/*output.c*/
void	ft_putendl(char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);

/*error_exit.c*/
void ft_err_exit(void);
int ft_error(void);
void    ft_free_err_exit(t_list *lst_a, t_list *lst_b);

#endif
