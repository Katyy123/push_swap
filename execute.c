/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:46:11 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/31 17:10:24 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_execute(t_list **lst_a, t_list **lst_b, char *str)
{
	ft_putendl(str);//stampa la mossa
	if (!ft_strncmp(str, "sa", 3) || !ft_strncmp(str, "ss", 3))
		ft_swap(*lst_a);
	if (!ft_strncmp(str, "sb", 3) || !ft_strncmp(str, "ss", 3))
		ft_swap(*lst_b);
	if (!ft_strncmp(str, "ra", 3) || !ft_strncmp(str, "rr", 3))	
		ft_rotate(*lst_a);
	if (!ft_strncmp(str, "rb", 3) || !ft_strncmp(str, "rr", 3))
		ft_rotate(*lst_b);
	if (!ft_strncmp(str, "rra", 4) || !ft_strncmp(str, "rrr", 4))
		ft_rrotate(*lst_a);
	if (!ft_strncmp(str, "rrb", 4) || !ft_strncmp(str, "rrr", 4))
		ft_rrotate(*lst_b);
	if (!ft_strncmp(str, "pa", 3) && ft_lstsize(*lst_b) > 0)
		ft_push(**lst_a);
	if (!ft_strncmp(str, "pb", 3) && ft_lstsize(*lst_a) > 0)
		ft_push(**lst_b);
}

