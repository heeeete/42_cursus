/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:18:07 by huipark           #+#    #+#             */
/*   Updated: 2022/11/06 17:00:33 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long				sign;
	long long			i;

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
	return (i * sign);
}

void	ft_putstr(char *s)
{
	while (*s)
	{
		write (1, s, 1);
		s++;
	}
	write (1, &"\n", 1);
}

void	ft_free(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
		free (dest[i++]);
	free (dest);
}