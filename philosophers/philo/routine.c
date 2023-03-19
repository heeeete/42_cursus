/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:39 by huipark           #+#    #+#             */
/*   Updated: 2023/03/17 01:53:03 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static void	eating(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&philo->event->event);
	philo->last_meal_time = get_ms_time();
	philo->n_eat++;
	if (philo->n_eat == philo->info->option)
	{
		philo->info->is_full++;
	}
	pthread_mutex_unlock(&philo->event->event);
	print_state(philo, EAT);
	philo_action_time(philo->info->time_to_eat);
	put_fork(philo);
}

static void	sleeping(t_philo *philo)
{
	print_state(philo, SLEEP);
	philo_action_time(philo->info->time_to_sleep);
}

static void	thinking(t_philo *philo)
{
	print_state(philo, THINK);
}

static void	*solo_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->mr_fork);
	*philo->r_fork = 1;
	print_state(philo, FORK);
	pthread_mutex_unlock(philo->mr_fork);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->n_philo == 1)
		return (solo_routine(philo));
	if (philo->id % 2 == 0)
		philo_action_time(philo->info->time_to_eat);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
