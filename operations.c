/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:12:02 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/04 17:31:17 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *lst)
{
	int	tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
}

void	ft_rotate(t_list *lst)
{
	int	tmp;

	tmp = lst->content;
	while (lst->next)
	{
		lst->content = lst->next->content;
		lst = lst->next;
	}
	lst->content = tmp;
}

void	ft_rrotate(t_list *lst)
{
	t_list		*temp;
	int			data;
	int			data2;

	temp = lst;
	data2 = lst->content;
	while (lst->next)
	{
		data = lst->next->content;
		lst->next->content = data2;
		data2 = data;
		lst = lst->next;
	}
	temp->content = data2;
}
