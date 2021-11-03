/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:17:51 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 15:41:49 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_toolong_int(char c, int num, int sign)
{	
	if (((2147483647 - (c - 48)) / 10 < num) && (sign == 1))
		return (1);
	if (((2147483648 - (c - 48)) / 10 < num) && (sign == -1))
		return (1);
	return (0);
}

int ft_pre_atoi(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int num;

	sign = 1;
	num = 0;
	i = ft_pre_atoi(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (ft_check_toolong_int (str[i], num, sign))
		{
			ft_putendl("Error1");//togli
			ft_err_exit();
		}
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}