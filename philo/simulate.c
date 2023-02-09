/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:15:29 by huipark           #+#    #+#             */
/*   Updated: 2023/02/09 18:33:57 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	monitoring(t_philo *philo)
{
	int	i;
	int	n_eat_flag;

	while (1)
	{
		i = 0;
		n_eat_flag = 0;
		while (i < philo->info->n_philo)
		{
			if (philo[i].info->time_to_die <= get_time_passed_by(philo[i].last_meal_time))
			{
				print_state(&philo[i], DIE);
				return (DIE);
			}
			i++;
		}
		i--;
		if (philo->info->exit_option != -1)
			while (i >= 0)
			{
				if (philo[i--].n_eat >= philo->info->exit_option)
					n_eat_flag++;
			}
		if (n_eat_flag == philo->info->n_philo)
			return (DIE);
		usleep(CONTEXT_SWITCHING);
	}
	return (0);
}

int	philo_pthread_create(t_philo *philo)
{
	int		i;

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
	if (monitoring(philo))
		return (1);
	return (0);
}

int	simulate(t_philo *philo)
{
	// time_t	start_time;

	// start_time = get_ms_time();
	philo_pthread_create(philo);

	return (0);
}
