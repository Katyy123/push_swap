/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:05:27 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 13:08:24 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_copy_list(t_list *list)
{
	t_list	*new;
	t_list	*copy;

	copy = NULL;
	while (list != 0)
	{
		new = ft_lstnew(list->content);
		if (new == 0)
		{
			ft_putendl("Error12");//togli
			ft_error();//check
		}
		ft_lstadd_back(&copy, new);
		list = list->next;
	}
	return (copy);
}

void	ft_remove_elem_lst(t_list **begin_list, int num)
{
	t_list	*list;
	t_list	*tmp;

	list = *begin_list;
	while (list && list->next)
	{
		if (list->next->content == num)
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp);
		}
		list = list->next;
	}
	list = *begin_list;
	if (list && list->content == num)
	{
		*begin_list = list->next;
		free(list);
	}
}

int	ft_lst_is_sorted(t_list *lst)
{
	while (lst && lst->next != 0)
	{
		if ((int)(lst->next->content) < (int)(lst->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}