/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:48:22 by huipark           #+#    #+#             */
/*   Updated: 2023/02/16 20:07:24 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	arguments_check2(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > INT_MAX)
			return (BIG);
		i++;
	}
	return (SUCCESS);
}

int	arguments_check(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (ARG_NOT_NUMBER);
			j++;
		}
		i++;
	}
	return (arguments_check2(argv));
}
