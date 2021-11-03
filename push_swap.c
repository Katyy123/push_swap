/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:12:30 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 17:02:14 by cfiliber         ###   ########.fr       */
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
			ft_putendl("Error15");//togli
			ft_free_err_exit(*lst_a, *lst_b);
		}
		ft_lstadd_back(lst_a, new);
		i++;
	}
}

int main(int argc, char **argv)
{
	//int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
  
	if (argc == 1)//se non ci sono args
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_pre_check(argc, argv);
	//arr = ft_pre_check(argc, argv);
	//int i = 0;//togli
	//printf("array in main:\n");//togli
	//while (arr[i])//togli
	//{
		//printf("%d\n", arr[i]);
		//i++;
	//}
	
	//ft_create_list(&stack_a, &stack_b, arr);
	//free(arr);
	size = ft_lstsize(stack_a);
	if (size >= 2 && size <= 5)
		ft_sort_small_stack(&stack_a, &stack_b);
	else if (size > 5)
		ft_sort_big_stack(&stack_a, &stack_b);
	t_list *temp;//togli
	temp = stack_a;//togli
	printf("Stack finale:\n");//togli
	while (temp)//togli
	{
		printf("%d\n", temp->content);
		temp = temp->next;
	}
	if (!(ft_lst_is_sorted(stack_a)) || stack_b != 0)
	{
		ft_putendl("Error11");//togli
		ft_error();
	}
	ft_free_lst(stack_a);
	ft_free_lst(stack_b);
	//printf("check");
	return(0);
}
