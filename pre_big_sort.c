/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:13:22 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/04 17:40:13 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_create_sorted_arr(t_list *lst_a, t_list *lst_b)
{
	t_list	*copy;
	int		*sorted_arr;
	int		size;
	int		i;
	int		min;

	copy = ft_copy_list(lst_a);
	if (copy == NULL)
		ft_free_err_exit(lst_a, lst_b);
	size = ft_lstsize(lst_a);
	sorted_arr = (int *)malloc(sizeof(int) * size);
	if (sorted_arr == NULL)
	{
		free(copy);
		ft_free_err_exit(lst_a, lst_b);
	}
	i = 0;
	while (i < size)
	{
		min = ft_lst_min(copy);
		sorted_arr[i] = min;
		ft_remove_elem_lst(&copy, min);
		i++;
	}
	return (sorted_arr);
}

void	ft_put_index_in_lst(t_list *list, int *sorted_arr)
{
	int	i;

	while (list)
	{
		i = 0;
		while (sorted_arr[i] != list->content)
			i++;
		list->content = i;
		list = list->next;
	}
}

int	ft_binary_maxnum_len(t_list *lst_a)
{
	int	size;
	int	len;

	len = 0;
	size = ft_lstsize(lst_a);
	while ((size) > 0)
	{
		size /= 2;
		len++;
	}
	return (len);
}
