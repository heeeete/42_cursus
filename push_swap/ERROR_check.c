/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERROR_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:47:35 by huipark           #+#    #+#             */
/*   Updated: 2022/11/03 20:52:40 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ERROR_check(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	while (argc-- > 1)
	{
		str = ft_split(argv[argc], ' ');
		while (str[i])
		{
			j = 0;
			while (str[i][j])
			{
				if (str[i][0] == '-' && j == 0)
					j++;
				if (str[i][j] < '0' || str[i][j] > '9')
					return (1);
				j++;
			}
			if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
				return (1);
			i++;
		}
	}
	return (0);
}

int	ERROR_check2(int argc, char *argv[])
{
	int	i;
	int	j;
	char	***str;

	i = 0;
	while ()
	if (argc == 1)
		return (1);
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