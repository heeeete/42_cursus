/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:05:40 by huipark           #+#    #+#             */
/*   Updated: 2023/02/04 17:52:49 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;
	int		error_code;

	error_code = init(argc, argv, &info, &philo);
	if (error_code != 0)
		return (print_err(error_code));
}
