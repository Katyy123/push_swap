/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:46:11 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/02 17:01:19 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_execute_push(t_list **lst_a, t_list **lst_b, char *str)
{
	t_list	*new;
	
	ft_putendl(str);//stampa la mossa
	if (!ft_strncmp(str, "pa", 3) && ft_lstsize(*lst_b) > 0)
	{
		new = ft_lstnew((*lst_b)->content);//non posso semplicemente spostare l'elem ma devo crearne un altro
		if (new == 0)
			return(ft_error());
		new->next = *lst_a;
		*lst_a = new;
		free(*lst_b);
		*lst_b = (*lst_b)->next;
	}
	else if (!ft_strncmp(str, "pb", 3) && ft_lstsize(*lst_a) > 0)
	{
		new = ft_lstnew((*lst_a)->content);
		if (new == 0)
			return (ft_error(0));
		new->next = *lst_b;
		*lst_b = new;
		free(*lst_a);
		*lst_a = (*lst_a)->next;
	}
	return (1);
}

void	ft_execute(t_list **lst_a, t_list **lst_b, char *str)
{
	ft_putendl(str);//stampa la mossa
	if (!ft_strncmp(str, "sa", 3) || !ft_strncmp(str, "ss", 3))
		ft_swap(*lst_a);
	if (!ft_strncmp(str, "sb", 3) || !ft_strncmp(str, "ss", 3))
		ft_swap(*lst_b);
	if (!ft_strncmp(str, "ra", 3) || !ft_strncmp(str, "rr", 3))	
		ft_rotate(*lst_a);
	if (!ft_strncmp(str, "rb", 3) || !ft_strncmp(str, "rr", 3))
		ft_rotate(*lst_b);
	if (!ft_strncmp(str, "rra", 4) || !ft_strncmp(str, "rrr", 4))
		ft_rrotate(*lst_a);
	if (!ft_strncmp(str, "rrb", 4) || !ft_strncmp(str, "rrr", 4))
		ft_rrotate(*lst_b);
}