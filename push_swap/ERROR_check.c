/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERROR_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:47:35 by huipark           #+#    #+#             */
/*   Updated: 2022/10/27 16:55:18 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ERROR_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc == 1)
		return (1);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (1);
		while (argv[i][j])
		{	if (argv[i][0] == '-')
			{
				j++;
				continue;
			}
			else if ((argv[i][j] < '0' || argv[i][j] > '9'))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	ERROR_check2(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i <= (argc - 2))
	{
		j = i + 1;
		while (j <= (argc - 1))
		{
			if (!(ft_strcmp(argv[i], argv[j])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}