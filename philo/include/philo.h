/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:06:47 by huipark           #+#    #+#             */
/*   Updated: 2023/03/18 17:56:03 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define CONTEXT_SWITCHING	1000
# define SUCCESS	0
# define FAILURE	1

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

enum	e_error_code
{
	ARG_ERROR = 1,
	ARG_NOT_NUMBER,
	MALLOC_ERROR,
	MUTEX_ERROR,
	RUNTIME_ERROR,
	TO_BIG,
};

enum	e_philo_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

typedef struct s_event
{
	pthread_mutex_t	event;
	pthread_mutex_t	is_die_mutex;
}				t_event;

typedef struct s_argv_info
{
	int	n_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	option;
	int	is_die;
	int	is_full;
}				t_info;

typedef struct s_philo
{
	t_info			*info;
	t_event			*event;
	int				id;
	int				n_eat;
	time_t			start_time;
	time_t			last_meal_time;
	pthread_t		pth;
	pthread_mutex_t	m_fork;
	pthread_mutex_t	*ml_fork;
	pthread_mutex_t	*mr_fork;
	int				fork;
	int				*l_fork;
	int				*r_fork;
}				t_philo;

// init.c
int			init(char *argv[], t_info *info, t_philo **philo, t_event **event);
int			philo_mutex_init(t_philo *philo);

// init_utils.c
int			arguments_check(char *argv[]);

// util.c
int			print_err(int error_code);
long long	ft_atoi(const char *str);
int			print_state(t_philo *philo, int state);
time_t		get_ms_time(void);
time_t		get_time_passed_by(time_t start_time);

// simulate.c
void		*simulate(t_philo *philo);
int			philo_ttd_check(t_philo *philo);

// routine.c
void		*routine(void *arg);

// rountine_utils.c
void		put_fork(t_philo *philo);
void		take_fork(t_philo *philo);
void		philo_action_time(time_t time_to_wait);

#endif
