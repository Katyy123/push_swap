/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:07:33 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 13:05:47 by cfiliber         ###   ########.fr       */
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
		lst = pointer;//alla fine puntano entrambi a NULL, quindi non serve free
	}
}

int	ft_lst_index(t_list *list, int num)//qui scorro pointer list fino a trovare num.
{                              //Forse c'è il rischio di perdermi il puntatore, perché non lo ritorno
	int	i;

	if (!(list))
	{
        ft_putendl("Error8");//togli
		ft_err_exit();
	}
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

int	ft_lst_min(t_list *list)//qui scorro pointer list fino a trovare num.
{                          //Forse c'è il rischio di perdermi il puntatore, perché non lo ritorno
	int	min;            //per free non ci sono problemi perché dopo libero tutto ciò che punta a un elem. della list

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

int	ft_lst_max(t_list *list)//qui scorro pointer list fino a trovare num.
{                          //Forse c'è il rischio di perdermi il puntatore, perché non lo ritorno
	int	max;            //per free non ci sono problemi perché dopo libero tutto ciò che punta a un elem. della list

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