/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:08:17 by cfiliber          #+#    #+#             */
/*   Updated: 2021/11/03 17:02:16 by cfiliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct s_array {
	size_t	len;
	int		*arr;
} t_array;


#include "push_swap.h"

int	ft_arr_is_sorted(int *arr)
{
	int i;

	i = 1;
	while (arr[i])
	{
		if (arr[i] <= arr[i -1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_doubles(int argc, int *arr)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)//argc è il numero di interi nell'array
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] == arr[i])
			{
				ft_putendl("Error2");//togli
				ft_err_exit();
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_check_1arg(int argc, char **argv)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * (argc + 1));
	if (!arr)
	{
			ft_putendl("Error3");//togli
			ft_err_exit();
	}
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!(ft_isdigit(&argv[i][j])))
		{
			ft_putendl("Error4");//togli
			ft_err_exit();//controlla se devo liberare la memoria di arr
		}
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	arr[i] = '\0';
	ft_check_doubles(argc, arr);
	ft_free_mtx(argv);
	return (arr);
}

int	*ft_check_2args(int argc, char **argv)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	arr = malloc(sizeof(int) * (argc + 1));
	if (!arr)
	{
			ft_putendl("Error5");//togli
			ft_err_exit();
	}
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!(ft_isdigit(&argv[i][j])))
		{
			ft_putendl("Error6");//togli
			ft_err_exit();
		}
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	arr[i] = '\0';
	ft_check_doubles(argc, arr);
	return (arr);
}

int	*ft_pre_check(int argc, char **argv)
{
	char	**mtx;
	//int		*arr;
	int		size;
	t_list *stack_a;

	if (argc == 2)//c'é un solo numero
	{
		mtx = ft_split(argv[1], ' ');
		if (mtx == NULL)//arg è vuoto o allocation failed
		{
			ft_putendl("Error7");//togli
			ft_err_exit();
		}
		stack_a = ft_check_1arg(ft_mtx_size(mtx), mtx);
		//arr = ft_check_1arg(ft_mtx_size(mtx), mtx);
		//printf("arr in pre_check_1arg:\n");
		//int i = 0;//togli
		//while (arr[i])//togli
		//{
			//printf("%d\n", arr[i]);
			//i++;
		//}
	}
	if (argc > 2)
	{
		arr = ft_check_2args(argc - 1, argv + 1);
		//printf("arr in pre_check_2arg:\n");
		//int i = 0;//togli
		//while (arr[i])//togli
		//{
			//printf("%d\n", arr[i]);
			//i++;
		//}
	}
	//if (ft_arr_size(arr) == 1)
		//exit(0);
	size = 0;
	while (arr[size])
		size++;
	if (size == 1)
		exit(0);
	if (ft_arr_is_sorted(arr))
		exit(0);
	return (arr);
}