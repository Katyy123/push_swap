/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:12:30 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/02 18:59:20 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_list(t_list **lst_a, t_list **lst_b, int *arr)//** perché gli devo passare il puntatore, che va modificato
{
	t_list	*new;
	int		i;

	i = 0;
	while (arr[i])
	{	
		new = ft_lstnew(arr[i]);
		if (new == 0)
		{
			free(arr);
			ft_free_exit(*lst_a, *lst_b);
		}
		ft_lstadd_back(lst_a, new);
		i++;
	}
	return (0);
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
