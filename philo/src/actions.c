/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:07:48 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/18 20:12:18 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		print_state(philo, "has taken a fork");	
	}
}

void	take_eat(t_philo *philo)
{
	take_forks(philo);
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->t_eat, philo->table);
	philo->meals++;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	take_sleep(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo->table->t_sleep, philo->table);
}

void	take_think(t_philo *philo)
{
	print_state(philo, "is sleeping");	
}
