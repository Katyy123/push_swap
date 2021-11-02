/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:12:02 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/31 17:10:20 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list *lst)//non serve dargli **lst
{
	int tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
}

void	ft_rotate(t_list *lst)
{
	int tmp;
	
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
	int			data;//qui salvo il numero che sto per togliere
	int			data2;//questo contiene il numero che devo mettere al posto di quello tolto
	
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

void		ft_push(t_list **lst_a, t_list **lst_b)
{
	t_list	*new;
	
	new = ft_lstnew((*lst_b)->content);//non posso semplicemente spostare l'elem ma devo crearne un altro
	if (new == 0)
		ft_err_free_2(*lst_a, *lst_b);
	new->next = *lst_a;
	*lst_a = new;
	free(*lst_b);
	*lst_b = (*lst_b)->next;
}