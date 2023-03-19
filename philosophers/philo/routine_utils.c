/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:59:30 by huipark           #+#    #+#             */
/*   Updated: 2023/03/17 02:39:44 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->ml_fork);
	*philo->l_fork = 1;
	print_state(philo, FORK);
	pthread_mutex_lock(philo->mr_fork);
	*philo->r_fork = 1;
	print_state(philo, FORK);
}

void	put_fork(t_philo *philo)
{
	*philo->l_fork = 0;
	*philo->r_fork = 0;
	pthread_mutex_unlock(philo->ml_fork);
	pthread_mutex_unlock(philo->mr_fork);
}

void	philo_action_time(time_t time_to_wait)
{
	time_t	start_time;

	start_time = get_ms_time();
	usleep(time_to_wait * 1000 * 0.8);
	while (get_time_passed_by(start_time) < time_to_wait)
		;
}
