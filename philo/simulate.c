/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:15:29 by huipark           #+#    #+#             */
/*   Updated: 2023/02/11 00:49:54 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	philo_ttd_check(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->n_philo)
	{
		if (philo[i].info->time_to_die <= get_time_passed_by(philo[i].last_meal_time))
		{
			pthread_mutex_lock(&philo->info->is_die_mutex);
			philo->info->die = 1;
			pthread_mutex_unlock(&philo->info->is_die_mutex);
			print_state(&philo[i], DIE);
			return (DIE);
		}
		i++;
	}
	return (0);
}

int	philo_n_eat_check(t_philo *philo)
{
	int	i;
	int	n_count;

	i = 0;
	n_count = 0;
	while (i < philo->info->n_philo)
	{
		if (philo[i++].n_eat >= philo->info->option)
			n_count++;
	}
	if (n_count == philo->info->n_philo)
		return (1);
	else
		return (0);
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
		usleep(CONTEXT_SWITCHING);
	}
	return (NULL);
}

// static void	*destroy_and_detach(t_philo *philo, int i)
// {
// 	int	j;

// 	j = 0;
// 	while (j < philo->info->n_philo)
// 		pthread_mutex_destroy(&philo[j++].fork);
// 	pthread_mutex_destroy(&philo->event->event);
// 	i--;
// 	while (i >= 0)
// 		pthread_detach(philo[i--].pth);
// 	return (NULL);
// }

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
			// return (destroy_and_detach(philo, i));
		i++;
	}
	return (monitoring(philo));
}
