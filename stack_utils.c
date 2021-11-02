/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:07:20 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/31 17:10:36 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;//non serve liberare questo puntatore perché prima di return, viene fatto puntare a NULL
	int		n;

	ptr = lst;
	n = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		n++;
	}
	return (n);
}

t_list	*ft_lstnew(int content)
{
	t_list *new;

	new = malloc(sizeof(t_list *));//alloco memoria che poi libero
	if (!(new))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)//il pointer lst rimane puntato al primo elem. 
{
	t_list	*last;

	if (!new)
		return ;//vedere se bisogna mettere exit, invece di return. Controlla se c'è free dopo
	if (!(*lst))
	{
		*lst = new;
		return ;//vedere se bisogna mettere exit, invece di return. Controlla se c'è free dopo
	}
	last = ft_lstlast(*lst);
	last->next = new;
	last = new;//potrebbe creare problemi per free? Forse una volta che libero new, si libera anche last
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;//vedere se bisogna mettere exit, invece di return. Controlla se c'è free dopo
	if (!(*lst))
	{
		*lst = new;
		return ;//vedere se bisogna mettere exit, invece di return. Controlla se c'è free dopo
	}
	new->next = *lst;
	*lst = new;//faccio puntare new al primo elem.
}