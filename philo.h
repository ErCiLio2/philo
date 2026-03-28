/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 06:46:47 by eteixeir          #+#    #+#             */
/*   Updated: 2026/03/28 08:23:25 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#ifndef PHILO
#define PHILO

typedef struct	s_global
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int tmie_to_sleep;
} t_global;
typedef struct	s_philo
{
	
} t_philo;
#endif