/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:39 by huipark           #+#    #+#             */
/*   Updated: 2023/02/08 23:01:36 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_state(philo, FORK);
	pthread_mutex_lock(philo->r_fork);
	print_state(philo, FORK);

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

	}
	return (0);
}
