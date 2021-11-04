/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:08:17 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/04 17:47:14 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_doubles(t_list *stack_a, t_list *stack_b)
{
	t_list	*copy;
	t_list	*start;

	start = stack_a;
	while (stack_a->next != 0)
	{
		copy = stack_a->next;
		while (copy->next != 0)
		{
			if (copy->content == stack_a->content)
				ft_free_err_exit(stack_a, stack_b);
			copy = copy->next;
		}
		if (copy->content == stack_a->content)
			ft_free_err_exit(stack_a, stack_b);
		stack_a = stack_a->next;
	}
	stack_a = start;
}

void	ft_check_1arg(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		num;
	t_list	*new;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!(ft_isdigit(&argv[i][j])))
			ft_err_exit();
		num = ft_atoi(argv[i]);
		new = ft_lstnew(num);
		if (new == 0)
			ft_free_err_exit(*stack_a, *stack_b);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	ft_check_doubles(*stack_a, *stack_b);
	ft_free_mtx(argv);
}

void	ft_check_2args(int argc, char **argv, t_list **lst_a, t_list **lst_b)
{
	int		i;
	int		j;
	int		num;
	t_list	*new;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!(ft_isdigit(&argv[i][j])))
			ft_err_exit();
		num = ft_atoi(argv[i]);
		new = ft_lstnew(num);
		if (new == 0)
			ft_free_err_exit(*lst_a, *lst_b);
		ft_lstadd_back(lst_a, new);
		i++;
	}
	ft_check_doubles(*lst_a, *lst_b);
}

void	ft_check_create(int argc, char **argv, t_list **lst_a, t_list **lst_b)
{
	char	**mtx;
	int		size;

	if (argc == 2)
	{
		mtx = ft_split(argv[1], ' ');
		if (mtx == NULL)
			ft_err_exit();
		ft_check_1arg(ft_mtx_size(mtx), mtx, lst_a, lst_b);
	}
	if (argc > 2)
	{
		ft_check_2args(argc - 1, argv + 1, lst_a, lst_b);
	}
	size = ft_lstsize(*lst_a);
	if (size == 1)
		exit(0);
	if (ft_lst_is_sorted(*lst_a))
		exit(0);
}
