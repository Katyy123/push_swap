/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:04:45 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 11:16:37 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_err_exit(void)
{
    ft_putendl("Error");
    exit(-1); 
}

int ft_error(void)
{
    ft_putendl("Error");
    return(0);
}

void    ft_free_err_exit(t_list *lst_a, t_list *lst_b)
{
    ft_putendl("Error");
    ft_free_lst(lst_a);
	ft_free_lst(lst_b);
	exit(-1);
}