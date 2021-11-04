/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:08:22 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/04 15:27:40 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2_3(t_list **lst_a, t_list **lst_b)//quando num = 2 o 3
{
	int	index_min;
	int	index_max;

	index_min = ft_lst_index(*lst_a, ft_lst_min(*lst_a));
	index_max = ft_lst_index(*lst_a, ft_lst_max(*lst_a));
	if (ft_lstsize(*lst_a) == 3 && index_min == 0 && index_max == 1)//1 3 2
	{
		ft_execute(lst_a, lst_b, "sa");
		ft_execute(lst_a, lst_b, "ra");
	}
	else if (index_min == 1 && index_max == 0)//3 1 2  o  2 1
		ft_execute(lst_a, lst_b, "ra");
	else if (index_min == 1 && index_max == 2)//2 1 3
		ft_execute(lst_a, lst_b, "sa");
	else if (index_min == 2 && index_max == 0)//3 2 1
	{
		ft_execute(lst_a, lst_b, "ra");
		ft_execute(lst_a, lst_b, "sa");
	}
	else if (index_min == 2 && index_max == 1)//2 3 1
		ft_execute(lst_a, lst_b, "rra");
}

int	ft_sort_4(t_list **lst_a, t_list **lst_b)//mette il numero più piccolo nella stack b
{
	int	index_min;

	index_min = ft_lst_index(*lst_a, ft_lst_min(*lst_a));
	if (index_min == 1)
		ft_execute(lst_a, lst_b, "sa");
	else if (index_min == 2)
	{
		ft_execute(lst_a, lst_b, "ra");
		ft_execute(lst_a, lst_b, "ra");
	}
	else if (index_min == 3)
		ft_execute(lst_a, lst_b, "rra");
	return (ft_execute_push(lst_a, lst_b, "pb"));
}

int	ft_sort_5(t_list **lst_a, t_list **lst_b)//mette il numero più piccolo nella stack b
{
	int	index_min;

	index_min = ft_lst_index(*lst_a, ft_lst_min(*lst_a));
	if (index_min == 1)
		ft_execute(lst_a, lst_b, "sa");
	else if (index_min == 2)
	{
		ft_execute(lst_a, lst_b, "ra");
		ft_execute(lst_a, lst_b, "ra");
	}
	else if (index_min == 3)
	{
		ft_execute(lst_a, lst_b, "rra");
		ft_execute(lst_a, lst_b, "rra");
	}
	else if (index_min == 4)
		ft_execute(lst_a, lst_b, "rra");
	return (ft_execute_push(lst_a, lst_b, "pb"));
}

void	ft_sort_small_stack(t_list **lst_a, t_list **lst_b)
{
	int	size;

	size = ft_lstsize(*lst_a);
	if (size == 2 || size == 3)
		ft_sort_2_3(lst_a, lst_b);
	if (size == 4)
	{
		if (ft_sort_4(lst_a, lst_b) == 0)
		{
			ft_putendl("Error17");//togli
			ft_free_err_exit(*lst_a, *lst_b);
		}
		ft_sort_2_3(lst_a, lst_b);
		if (ft_execute_push(lst_a, lst_b, "pa") == 0)
		{
			ft_putendl("Error18");//togli
			ft_free_err_exit(*lst_a, *lst_b);
		}
	}
	if (size == 5)
	{
		if (ft_sort_5(lst_a, lst_b) == 0)
		{
			ft_putendl("Error19");//togli
			ft_free_err_exit(*lst_a, *lst_b);
		}
		if (ft_sort_4(lst_a, lst_b) == 0)
		{
			ft_putendl("Error20");//togli
			ft_free_err_exit(*lst_a, *lst_b);
		}
		ft_sort_2_3(lst_a, lst_b);
		if (ft_execute_push(lst_a, lst_b, "pa") == 0)
		{
			ft_putendl("Error21");//togli
			ft_free_err_exit(*lst_a, *lst_b);
		}
		if (ft_execute_push(lst_a, lst_b, "pa") == 0)
		{
			ft_putendl("Error22");//togli
			ft_free_err_exit(*lst_a, *lst_b);
		}
	}
}
