/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:50:51 by huipark           #+#    #+#             */
/*   Updated: 2023/02/08 22:55:46 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	print_state(t_philo *philo, int state)
{
	int	curr_time;

	curr_time = get_time_passed_by(philo->start_time);
	static const char	*msg[] =
	{
		"has taken fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died"
	};
	printf("%ld    %d    %s\n", curr_time, philo->id, state);
}

int	print_err(int error_code)
{
	static const char	*msg[] =
	{
		NULL,
		"Error: Arguments has 5 or 6",
		"Error: Arguments can only be number",
		"Error: malloc fail",
		"Error: mutex fail",
		"Error: run time fail",
	};
	printf("%s\n", msg[error_code]);
	return (FAILURE);
}

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

time_t	get_ms_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}

time_t	get_time_passed_by(time_t start_time)
{
	return (get_ms_time() - start_time);
}
