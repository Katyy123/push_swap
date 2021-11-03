/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:13:22 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 15:14:09 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_create_sorted_arr(t_list *lst_a, t_list *lst_b)//creo un array con i numeri di lst ordinati
{
	t_list	*copy;
	int		*sorted_arr;
	int		size;
	int		i;
	int		min;

	copy = ft_copy_list(lst_a);
	if (copy == NULL)
	{
		ft_putendl("Error13");//togli
		ft_free_err_exit(lst_a, lst_b);//check
	}
	size = ft_lstsize(lst_a);
	sorted_arr = (int *)malloc(sizeof(int) * size);//creo un array di int
	if (sorted_arr == NULL)
	{
		free(copy);
		ft_putendl("Error14");//togli
		ft_free_err_exit(lst_a, lst_b);//check
	}
	i = 0;
	while (i < size)//nell'array sorted_arr metto i numeri della lista in ordine
	{
		min = ft_lst_min(copy);
		sorted_arr[i] = min;
		ft_remove_elem_lst(&copy, min);//rimuovo il minimo
		i++;
	}
	return (sorted_arr);//ritorno l'array ordinato
}

void	ft_put_index_in_lst(t_list *list, int *sorted_arr)//al posto di ogni int di list, metto l'indice di quell'int che ha nell'arr
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

int	ft_binary_maxnum_len(t_list *lst_a)//trova il numero di cifre in codice binario del num max
{
	int	size;
	int	len;

	len = 0;
	size = ft_lstsize(lst_a);//size = numero max + 1
	while ((size) > 0)
	{
		size /= 2;
		len++;
	}
	return (len);
}