/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:07:33 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/04 17:54:11 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list *lst)
{
	t_list	*pointer;

	while (lst)
	{
		pointer = lst->next;
		free(lst);
		lst = pointer;
	}
}

int	ft_lst_index(t_list *list, int num)
{
	int	i;

	if (!(list))
		ft_err_exit();
	i = 0;
	while (list->next)
	{
		if (list->content == num)
			return (i);
		list = list->next;
		i++;
	}
	return (i);
}

int	ft_lst_min(t_list *list)
{
	int	min;

	min = list->content;
	while (list->next)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	if (list->content < min)
		min = list->content;
	return (min);
}

int	ft_lst_max(t_list *list)
{
	int	max;

	max = list->content;
	while (list->next)
	{
		if (list->content > max)
			max = list->content;
		list = list->next;
	}
	if (list->content > max)
		max = list->content;
	return (max);
}
