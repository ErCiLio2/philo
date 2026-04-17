/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 06:46:47 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 00:49:08 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;
typedef struct t_context
{
	long long		start_time;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				simulation_stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	stop_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_context;
typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_context		*data;
}					t_philo;
int			ft_atoi(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			is_valid_arg(char *arg);
void		clear_data(t_context *data);
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);
void		ft_usleep(long long time_in_ms);
void		print_error_invalid_arg(void);
void		init_philos_and_forks(t_context *data);
void		mutex_init(t_context *data);
long long	get_time(void);
int			get_simulation_status(t_context *data);
void		print_status(t_philo *philo, char *msg);
void		set_simulation_stop(t_context *data);
#endif