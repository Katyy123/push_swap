/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:12:30 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/04 17:47:09 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (argc == 1)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	ft_check_create(argc, argv, &stack_a, &stack_b);
	size = ft_lstsize(stack_a);
	if (size == 2 || size == 3)
		ft_sort_2_3(&stack_a, &stack_b);
	else if (size == 4 || size == 5)
		ft_sort_small_stack(&stack_a, &stack_b);
	else if (size > 5)
		ft_sort_big_stack(&stack_a, &stack_b);
	if (!(ft_lst_is_sorted(stack_a)) || stack_b != 0)
		ft_error();
	ft_free_lst(stack_a);
	ft_free_lst(stack_b);
	return (0);
}
