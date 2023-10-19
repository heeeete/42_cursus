/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:05:40 by huipark           #+#    #+#             */
/*   Updated: 2023/07/28 21:48:59 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static int	detach(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->n_philo)
		pthread_detach(philo[i++].pth);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info		info;
	t_event		*event;
	t_philo		*philo;
	int			error_code;

	if (argc != 5 && argc != 6)
		return (print_err(ARG_ERROR));
	error_code = init(argv, &info, &philo, &event);
	if (error_code != 0)
		return (print_err(error_code));
	if (philo_mutex_init(philo))
		return (print_err(MUTEX_ERROR));
	simulate(philo);
	detach(philo);
}
