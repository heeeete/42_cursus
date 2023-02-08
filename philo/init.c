/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:56:27 by huipark           #+#    #+#             */
/*   Updated: 2023/02/08 23:01:37 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	philo_mutex_init(t_philo *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&philo[i].end_state->is_end_mutex, NULL))
		return (MUTEX_ERROR);
	while (i < philo->info->n_philo)
	{
		if (pthread_mutex_init(&(philo[i].fork), NULL))
		{
			while (i--)
				pthread_mutex_destroy((&philo[i].fork));
			return (MUTEX_ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	philo_malloc(t_philo **philo, int n_philo)
{
	int	i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * n_philo);

	if (*philo == NULL)
		return (MALLOC_ERROR);
	return (SUCCESS);
}

void	philo_init(t_philo *philo, t_info *info, t_end_state *end_state)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		philo[i].info = info;
		philo[i].end_state = end_state;
		philo[i].th_id = i + 1;
		philo[i].n_eat = 0;
		philo[i].r_fork = &(philo[i].fork);
		philo[i].l_fork = &(philo[(i + 1) % info->n_philo].fork);
		i++;
	}
}

int	init(char *argv[], t_info *info, t_philo **philo, t_end_state *end_state)
{
	int	error_code;

	error_code = arguments_check(argv);
	if (error_code != 0)
		return (error_code);
	info->n_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		info->exit_option = ft_atoi(argv[5]);
	else
		info->exit_option = -1;
	error_code = philo_malloc(philo, info->n_philo);
	if (error_code != 0)
		return (error_code);
	philo_init(*philo, info, end_state);
	end_state->is_end = 0;
	return (SUCCESS);
}
