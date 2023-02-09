/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:39 by huipark           #+#    #+#             */
/*   Updated: 2023/02/09 19:16:16 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"


void	eating(t_philo *philo)
{
	take_fork(philo);
	print_state(philo, EAT);
	philo->last_meal_time = get_ms_time();
	philo_action_time(philo->info->time_to_eat);
	put_fork(philo);
	philo->n_eat++;
}

void	sleeping(t_philo *philo)
{
	print_state(philo, SLEEP);
	philo_action_time(philo->info->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_state(philo, THINK);
	// usleep(CONTEXT_SWITCHING);
}

int	solo_routine(void)
{
	//solo philo
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->n_philo == 1)
		solo_routine();
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}
