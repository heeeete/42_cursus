/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:15:29 by huipark           #+#    #+#             */
/*   Updated: 2023/03/18 19:53:17 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	philo_ttd_check(t_philo *philo)
{
	int					i;
	int					die;
	const char			*red = "\033[0;031m";

	i = 0;
	die = 0;
	while (i < philo->info->n_philo)
	{
		pthread_mutex_lock(&philo->event->event);
		if (philo[i].info->time_to_die <= \
		get_time_passed_by(philo[i].last_meal_time))
		{
			pthread_mutex_lock(&philo->event->is_die_mutex);
			die = 1;
			printf("%s%ld  %d  died\n\033[0m", \
			red, get_time_passed_by(philo[i].start_time), philo[i].id);
			break ;
		}
		pthread_mutex_unlock(&philo->event->event);
		i++;
	}
	return (die);
}

int	philo_n_eat_check(t_philo *philo)
{
	int	return_value;

	return_value = 0;
	pthread_mutex_lock(&philo->event->event);
	if (philo->info->is_full == philo->info->n_philo)
		return_value = 1;
	pthread_mutex_unlock(&philo->event->event);
	return (return_value);
}

void	*monitoring(t_philo *philo)
{
	while (1)
	{
		if (philo_ttd_check(philo))
			return (NULL);
		if (philo->info->option != -1)
		{
			if (philo_n_eat_check(philo))
				return (NULL);
		}
		usleep(100);
	}
	return (NULL);
}

static void	*detach(t_philo *philo, int i)
{
	while (i >= 0)
		pthread_detach(philo[i--].pth);
	return (NULL);
}

void	*simulate(t_philo *philo)
{
	int		i;
	time_t	start_time;

	i = 0;
	start_time = get_ms_time();
	while (i < philo->info->n_philo)
	{
		philo[i].start_time = start_time;
		philo[i].last_meal_time = start_time;
		if (pthread_create(&philo[i].pth, NULL, routine, &philo[i]))
			return (detach(philo, i));
		i++;
	}
	return (monitoring(philo));
}
