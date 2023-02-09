/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:06:47 by huipark           #+#    #+#             */
/*   Updated: 2023/02/09 18:27:42 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define CONTEXT_SWITCHING	1000
# define SUCCESS	0
# define FAILURE	1

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

enum	e_error_code
{
	ARG_ERROR = 1,
	ARG_NOT_NUMBER,
	MALLOC_ERROR,
	MUTEX_ERROR,
	RUNTIME_ERROR,
};

enum	e_philo_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

typedef struct s_end_state
{
	char			is_end;
	pthread_mutex_t	is_end_mutex;
}	t_end_state;

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
	t_info			*info;				//공유자원
	t_end_state		*end_state;			//공유자원
	int				id;
	int				n_eat;
	time_t			start_time;
	time_t			last_meal_time;
	pthread_t		pth;
	pthread_mutex_t	fork;				//공유자원
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}				t_philo;

// init.c
int	init(char *argv[], t_info *info, t_philo **philo, t_end_state *end_state);
int		philo_mutex_init(t_philo *philo);

// init_utils.c
int		arguments_check(char *argv[]);

// util.c
int		print_err(int error_code);
int		ft_atoi(const char *str);
int		print_state(t_philo *philo, int state);
time_t	get_ms_time(void);
time_t	get_time_passed_by(time_t start_time);

// simulate.c
int	simulate(t_philo *philo);

// routine.c
void	*routine(void *arg);
int		solo_routine(void);

// rountine_utils.c
void	put_fork(t_philo *philo);
void	take_fork(t_philo *philo);
void	philo_action_time(time_t time_to_wait);

#endif
