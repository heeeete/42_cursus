/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:39 by huipark           #+#    #+#             */
/*   Updated: 2023/02/11 22:28:33 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	is_end_monitoring(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->event->is_die_mutex);
	status = philo->info->is_die;
	pthread_mutex_unlock(&philo->event->is_die_mutex);
	return (status);
}

static int	eating(t_philo *philo)
{
	take_fork(philo);
	philo->last_meal_time = get_ms_time();
	print_state(philo, EAT);
	philo_action_time(philo->info->time_to_eat);
	put_fork(philo);
	return (is_end_monitoring(philo));
}

static int	sleeping(t_philo *philo)
{
	print_state(philo, SLEEP);
	philo_action_time(philo->info->time_to_sleep);
	return (is_end_monitoring(philo));
}

static int	thinking(t_philo *philo)
{
	print_state(philo, THINK);
	usleep(CONTEXT_SWITCHING);
	return (is_end_monitoring(philo));
}

static void	*solo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_state(philo, FORK);
	pthread_mutex_unlock(&philo->fork);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->n_philo == 1)
		return (solo_routine(philo));
	if (philo->id % 2 == 0)
		usleep(CONTEXT_SWITCHING);
	while (1)
	{
		if ((philo->info->option != -1 &&
			philo->n_eat == philo->info->option))
			continue ;
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
	}
	return (0);
}
