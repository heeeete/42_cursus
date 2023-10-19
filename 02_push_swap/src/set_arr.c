/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:42:25 by huipark           #+#    #+#             */
/*   Updated: 2022/11/24 19:54:57 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count(char *argv[])
{
	int		cnt;
	int		i;
	int		j;
	char	**str;

	cnt = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		while (str[j])
		{
			cnt++;
			j++;
		}
		ft_free (str);
		i++;
	}
	return (cnt);
}

static void	set_info(t_arr_info **arr_info, int max_index)
{
	(*arr_info)->max = (*arr_info)->arr[0];
	(*arr_info)->min = (*arr_info)->arr[max_index - 1];
	(*arr_info)->one_over_three_pivot = (*arr_info)->arr[max_index / 3];
	(*arr_info)->two_over_three_pivot = (*arr_info)->arr[max_index * 2 / 3];
}

void	set_arr(t_point *a, t_arr_info **arr_info, char *argv[])
{
	int		i;
	int		j;
	int		k;
	int		cnt;
	char	**str;

	i = 1;
	k = 0;
	cnt = count(argv);
	(*arr_info)->arr = wrap_malloc(sizeof(int) * cnt);
	i = 1;
	while (argv[i])
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		while (str[j])
			(*arr_info)->arr[k++] = ft_atoi(str[j++]);
		i++;
		ft_free (str);
	}
	quicksort (&(*arr_info)->arr, 0, cnt - 1);
	set_info(arr_info, cnt);
	a->head->max = (*arr_info)->max;
}

void	init_arr(int *arr)
{
	int	i;

	i = 0;
	while (i <= 10)
	{
		arr[i] = 0;
		i++;
	}
}
