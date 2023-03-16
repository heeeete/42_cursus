/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:50:51 by huipark           #+#    #+#             */
/*   Updated: 2023/03/17 02:36:28 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	print_state(t_philo *philo, int state)
{
	time_t		curr_time;
	const char	*cyan = "\033[0;036m";
	const char	*yellow = "\033[0;033m";
	const char	*blue = "\033[0;034m";
	const char	*purple = "\033[0;035m";

	pthread_mutex_lock(&philo->event->is_die_mutex);
	curr_time = get_time_passed_by(philo->start_time);
	if (state == FORK && philo->info->is_die == 0)
		printf("%s%ld %d has taken fork\n\033[0m", cyan, curr_time,
			philo->id);
	else if (state == EAT && philo->info->is_die == 0)
		printf("%s%ld %d is eating\n\033[0m", yellow, curr_time, philo->id);
	else if (state == SLEEP && philo->info->is_die == 0)
		printf("%s%ld %d is sleeping\n\033[0m", blue, curr_time, philo->id);
	else if (state == THINK && philo->info->is_die == 0)
		printf("%s%ld %d is thinking\n\033[0m", purple, curr_time, philo->id);
	pthread_mutex_unlock(&philo->event->is_die_mutex);
	return (0);
}

int	print_err(int error_code)
{
	static const char	*msg[] = \
	{
		NULL,
		"Error: [n_philo] [ttd] [tte] [tts] [option]",
		"Error: Arguments can only be positive number",
		"Error: malloc fail",
		"Error: mutex fail",
		"Error: run time fail",
		"Error: too big number"
	};

	printf("%s\n", msg[error_code]);
	return (FAILURE);
}

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
