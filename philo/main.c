/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:05:40 by huipark           #+#    #+#             */
/*   Updated: 2023/02/08 18:32:22 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int main(int argc, char *argv[])
{
	t_info		info;
	t_end_state	end_state;
	t_philo		*philo;
	int			error_code;

	if (argc != 5 && argc != 6)
		return (ARG_ERROR);
	error_code = init(argv, &info, &philo, &end_state);
	if (error_code != 0)
		return (print_err(error_code));
	if (philo_mutex_init(philo))
		return (print_err(MUTEX_ERROR));
	simulate(philo);
}
