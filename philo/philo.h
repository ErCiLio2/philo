/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:40:57 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/19 17:00:29 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	int				id;
	int				meals;
	long				last_meal;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_table	*table;
}	t_philo;

typedef struct s_table
{
	int				stop;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	long			start_time;
	pthread_mutex_t lock;
	pthread_mutex_t	start;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_table;
int		is_num(char *s);
int		ft_atoi(char *s);
int		parse(int ac, char **av, t_table *t);
int		init_table(t_table *table, int ac, char **av);
long	get_time(void);
long	timestamp(t_table *table);
void	ft_usleep(long time, t_table *table);
void	cleanup(t_table *t);
void	take_eat(t_philo *philo);
void	take_sleep(t_philo *philo);
void	take_think(t_philo *philo);
void	print_state(t_philo *philo, char *msg);
void	*routine(void *arg);
void	monitor(t_table *table);
void	init_simalation(t_table *t);
int		simulation_finished(t_table *table);
#endif