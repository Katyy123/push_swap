/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 18:57:46 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/31 17:35:18 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_copy_list(t_list *lst_a, t_list **lst_b)
{
	t_list	*temp;
	int			data;

	while (lst_a->next)
	{
		data = lst_a->content;
		temp = ft_lstnew(data);
		if (temp == 0)
			return (ft_error(0));
		ft_lstadd_back(lst_b, temp);
		lst_a = lst_a->next;
	}
	data = lst_a->content;
	temp = ft_lstnew(data);
	if (temp == 0)
		return (ft_error(0));
	ft_lstadd_back(lst_b, temp);
	return (1);
}



void	ft_create_list(t_list **lst_a, t_list **lst_b, int *arr)//** perché gli devo passare il puntatore, che va modificato
{
	t_list	*new;
	int		i;

	i = 0;
	while (arr[i])
	{	
		new = ft_lstnew(arr[i]);
		if (new == 0)
			ft_err_free_1(arr, lst_a, lst_b);
		ft_lstadd_back(lst_a, new);
		i++;
	}
	return (0);
}