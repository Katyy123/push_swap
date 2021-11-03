/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:07:51 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 15:18:36 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_replace_nums_in_lst(t_list *lst_a, int *sorted_arr)//rimetto in lst i numeri iniziali
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst_a);
	while (i < size)
	{
		lst_a->content = sorted_arr[lst_a->content];
		lst_a = lst_a->next;
		i++;
	}
}

int	ft_sort(t_list **lst_a, t_list **lst_b, int index)
{
	int	size;

	size = ft_lstsize(*lst_a);
	printf("size lista in ft_sort: %d\n", size);//togli
	while (size > 0)
	{
		if ((((*lst_a)->content >> index) & 1) == 0)//per essere 0, l'ultima cifra deve essere essere 0
		{
			if (ft_execute_push(lst_a, lst_b, "pb") == 0)
				return (0);
		}
		else
			ft_execute(lst_a, lst_b, "ra");
		size--;
	}
	while (*lst_b)
	{
		if (ft_execute_push(lst_a, lst_b, "pa") == 0)
			return (0);
	}
	return (1);
}

void	ft_sort_big_stack(t_list **lst_a, t_list **lst_b)
{
	int	*sorted_arr;
	int	len;
	int	i;

	sorted_arr = ft_create_sorted_arr(*lst_a, *lst_b);//creo un array con i numeri di lst ordinati
	ft_put_index_in_lst(*lst_a, sorted_arr);
	len = ft_binary_maxnum_len(*lst_a);
	i = 0;
	while (i < len)
	{
		if (ft_sort(lst_a, lst_b, i) == 0)
		{
			free(sorted_arr);
			ft_putendl("Error16");//togli
			ft_free_err_exit(*lst_a, *lst_b);
		}
		i++;
	}
	ft_replace_nums_in_lst(*lst_a, sorted_arr);
	free(sorted_arr);
}