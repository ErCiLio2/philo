/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:40:57 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/18 16:23:53 by eteixeir         ###   ########.fr       */
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
	int				last_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*rigt;
	t_table	*table;
}	t_philo;

typedef struct s_table
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
	pthread_mutex_t lock;
	pthread_mutex_t	start;
	pthread_mutex_t	write;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}	t_table;
int		is_num(char *s);
int		ft_atoi(char *s);
int		parse(int ac, char **av, t_table *t);
void	cleanup(t_table *t);
t_table	*init_data(int ac, char **av);
#endif