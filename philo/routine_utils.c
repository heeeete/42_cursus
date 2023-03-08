/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:59:30 by huipark           #+#    #+#             */
/*   Updated: 2023/03/08 15:25:15 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	take_fork(t_philo *philo)
{
		pthread_mutex_lock(philo->l_fork);
		print_state(philo, FORK);
		pthread_mutex_lock(philo->r_fork);
		print_state(philo, FORK);
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_action_time(time_t time_to_wait)
{
	time_t	start_time;

	start_time = get_ms_time();
	while (get_time_passed_by(start_time) < time_to_wait)
		usleep(CONTEXT_SWITCHING);
}
