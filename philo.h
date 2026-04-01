/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 06:46:47 by eteixeir          #+#    #+#             */
/*   Updated: 2026/03/31 11:05:55 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO
#define PHILO
	#include <unistd.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <limits.h>

typedef struct	t_context
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
} t_context;

typedef struct	s_philo
{
	
} t_philo;

int 	ft_atoi(char *str);
int		is_valid_arg(char *arg);
#endif