/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:48:22 by huipark           #+#    #+#             */
/*   Updated: 2023/02/04 17:57:03 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	ft_atoi(const char *str)
{
	long				sign;
	unsigned long long	i;

	sign = 1;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += (*str - '0');
		str++;
	}
	if (i > 9223372036854775807 && sign == 1)
		return (-1);
	else if (i > 9223372036854775808ULL && sign == -1)
		return (0);
	return ((int)(i * sign));
}

int	arguments_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	if (argc != 5 && argc != 6)
		return (ARG_ERROR);
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
	return (SUCCESS);
}
