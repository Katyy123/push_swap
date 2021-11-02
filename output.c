/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:41:01 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/30 12:55:46 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (s != NULL)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}

void	ft_putendl(char *s)
{
	if (s != NULL)
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}