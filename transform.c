/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:13:22 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/31 17:35:22 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_change_number(t_list *list, int *trasl)
{
	int	i;

	i = 0;
	while (trasl[i] != list->content)
		i++;
	list->content = i;
}

static void	ft_trasl_list(t_list *list, int *trasl)
{
	int	size;
	int	i;

	size = ft_lstsize(list);
	i = 0;
	while (list)
	{
		ft_change_number(list, trasl);
		list = list->next;
	}
}

static int	*ft_create_trasl(t_list *list)
{
	t_list	*cpy;
	int		*trasl;
	int		size;
	int		i;
	int		min;

	cpy = ft_copy_list2(list);
	if (cpy == NULL)
		ft_error(0);
	size = ft_lstsize(list);
	trasl = (int *)malloc(sizeof(int) * size);
	if (trasl == NULL)
	{
		ft_free_lst(cpy);
		ft_error(0);
	}
	i = 0;
	while (i < size)
	{
		min = ft_lst_min(cpy);
		trasl[i] = min;
		ft_numlist_remove_if(&cpy, min);
		i++;
	}
	return (trasl);
}

int	*ft_transform(t_list *list)
{
	int	*trasl;

	trasl = ft_create_trasl(list);
	ft_trasl_list(list, trasl);
	return (trasl);
}

void	ft_traslate(t_list *lst_a, int *trasl)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst_a);
	while (i < size)
	{
		lst_a->content = trasl[lst_a->content];
		lst_a = lst_a->next;
		i++;
	}
}
