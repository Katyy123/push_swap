/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:12:30 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/31 17:35:17 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_is_sorted_(t_list *lst)
{
	while (lst && lst->next != 0)
	{
		if ((int)(lst->next->content) < (int)(lst->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
  
	if (argc == 1)//se non ci sono args
		return (-1);
	arr = ft_pre_check(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_create_list(&stack_a, &stack_b, arr);
	free(arr);
	size = ft_lstsize(stack_a);
	if (size >= 2 && size <= 5)
		ft_sort_small_stack(&stack_a, &stack_b);
	else if (size > 5)
		ft_sort_big_stack(&stack_a, &stack_b);
	if (!(ft_lst_is_sorted(stack_a)) || stack_b != 0)
		ft_error();
	ft_free_lst(stack_a);
	ft_free_lst(stack_b);
	//printf("check");
	return(0);
}
