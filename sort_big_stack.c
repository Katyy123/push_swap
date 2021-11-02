/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:07:51 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/31 17:35:21 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



/*static int	ft_sort(t_list **lst_a, t_list **lst_b, int index)
{
	int	size;

	size = ft_lstsize(*lst_a);
	while (size > 0)
	{
		if ((((*lst_a)->content >> index) & 1) == 0)
		{
			if (ft_change_push(lst_a, lst_b, "pb") == -1)
				return (-1);
		}
		else
			ft_change_list(lst_a, lst_b, "ra");
		size--;
	}
	while (*lst_b)
	{
		if (ft_change_push(lst_a, lst_b, "pa") == -1)
			return (-1);
	}
	return (1);
}

static int	ft_len_i(t_list *lst_a)
{
	int	size;
	int	ret;

	ret = 0;
	size = ft_lstsize(lst_a);
	while (size > 0)
	{
		size /= 2;
		ret++;
	}
	return (ret);
}

static int	ft_sort_500(t_list **lst_a, t_list **lst_b)
{
	int	n_i;
	int	i;

	n_i = ft_len_i(*lst_a);
	i = 0;
	while (i < n_i)
	{
		if (ft_sort(lst_a, lst_b, i) == -1)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_sort_big_stack(t_list **lst_a, t_list **lst_b)
{
	int	*trasl;

	trasl = ft_transform(*lst_a);
	if (ft_sort_500(lst_a, lst_b) == -1)
	{
		free(trasl);
		ft_free_exit(*lst_a, *lst_b);
	}
	ft_traslate(*lst_a, trasl);
	free(trasl);
}
*/