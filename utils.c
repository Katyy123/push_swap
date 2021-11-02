/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:59:08 by cfiliber          #+#    #+#             */
/*   Updated: 2021/10/30 12:55:30 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_isdigit(char *str)
{
	int i;
	
	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}

int	ft_arr_size(int *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int ft_mtx_size(char **mtx)
{
	int i;

	i = 0;
	if (mtx == NULL)
		return (-1);
	while (mtx[i])
		i++;
	return (i);
}

void	ft_free_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx && mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}