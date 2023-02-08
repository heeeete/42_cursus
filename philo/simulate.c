/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:15:29 by huipark           #+#    #+#             */
/*   Updated: 2023/02/08 23:01:37 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	philo_pthread_create(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->n_philo)
	{
		philo[i].start_time = get_ms_time();
		philo[i].last_meal_time = philo[i].start_time;
		if (pthread_create(&philo[i].pth, NULL, routine, &philo[i]))
		{
			//오류 났을때
		}
		i++;
	}
	return (0);
}

int	simulate(t_philo *philo)
{
	time_t	start_time;

	start_time = get_ms_time();
	philo_pthread_create(philo);

	return (0);
}
