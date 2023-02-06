/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:06:47 by huipark           #+#    #+#             */
/*   Updated: 2023/02/06 18:35:34 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

enum	e_error_code
{
	ARG_ERROR = 1,
	ARG_NOT_NUMBER,
	MALLOC_ERROR,
	MUTEX_ERROR,
	RUNTIME_ERROR,
};

enum	e_return_status
{
	SUCCESS,
	FAILURE,
};

typedef struct	s_argv_info
{
	int	n_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	exit_option;
}				t_info;

typedef struct	s_philo
{
	t_info			*info;
	int				th_id;
	pthread_t		pth;
	pthread_mutex_t	fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}				t_philo;

int		ft_atoi(const char *str);
int		print_err(int error_code);
int		init(int argc, char *argv[], t_info *info, t_philo **philo);
int		philo_mutex_init(t_philo *philo);
int		arguments_check(int argc, char *argv[]);

#endif
