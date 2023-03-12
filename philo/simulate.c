/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:15:29 by huipark           #+#    #+#             */
/*   Updated: 2023/03/12 21:17:51 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	philo_ttd_check(t_philo *philo)
{
	int	i;
	const char	*red = "\033[0;031m";

	i = 0;
	while (i < philo->info->n_philo)
	{
		if (philo[i].info->time_to_die <= get_time_passed_by(philo[i].last_meal_time))
		{
			philo->info->is_die = 1;
			printf("%s%ld  %d  died\n\033[0m", red, get_time_passed_by(philo[i].start_time), philo[i].id);
			break ;
		}
		i++;
	}
	return (philo->info->is_die);
}

int	philo_n_eat_check(t_philo *philo)
{
	if (philo->info->is_full == philo->info->n_philo)
		return (1);
	return (0);
}

void	*monitoring(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->event->is_die_mutex);
		if (philo_ttd_check(philo))
		{
			pthread_mutex_unlock(&philo->event->is_die_mutex);
			return (NULL);
		}
		if (philo->info->option != -1)
		{
			if (philo_n_eat_check(philo))
			{
				pthread_mutex_unlock(&philo->event->is_die_mutex);
				return (NULL);
			}
		}
		pthread_mutex_unlock(&philo->event->is_die_mutex);
		usleep(100);
	}
	return (NULL);
}

static void	*detach(t_philo *philo, int i)
{
	int	j;

	j = 0;
	while (j < philo->info->n_philo)
		pthread_mutex_destroy(&philo[j++].fork);
	pthread_mutex_destroy(&philo->event->event);
	i--;
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
			;
			// return (detach(philo, i));
		i++;
	}
	return (monitoring(philo));
}
