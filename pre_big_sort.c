/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:13:22 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/02 18:59:19 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_create_sorted_arr(t_list *list)//creo un array con i numeri di lst ordinati
{
	t_list	*copy;
	int		*sorted_arr;
	int		size;
	int		i;
	int		min;

	copy = ft_copy_list(list);
	if (copy == NULL)
		ft_error(0);//check
	size = ft_lstsize(list);
	sorted_arr = (int *)malloc(sizeof(int) * size);//creo un array di int
	if (sorted_arr == NULL)
	{
		free(copy);
		ft_error(0);//check
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

static void	ft_put_index_in_lst(t_list *list, int *sorted_arr)//al posto di ogni int di list, metto l'indice di quell'int che ha nell'arr
{
	int	size;
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


static int	ft_binary_maxnum_len(t_list *lst_a)//trova il numero di cifre in codice binario del num max
{
	int	size;
	int	len;

	len = 0;
	size = ft_lstsize(lst_a);//size = numero max + 1
	while ((size - 1) > 0)
	{
		size /= 2;
		len++;
	}
	return (len);
}