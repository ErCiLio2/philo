/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:07:48 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/21 13:08:06 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

static void	take_forks(t_philo *philo)
{
	if (philo->table->n_philo == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a lefhtfork");
		ft_usleep(philo->table->t_die, philo->table);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->r_fork);
		print_state(philo, "has taken a right fork");
		pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a left fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_state(philo, "has taken a left fork");
		pthread_mutex_lock(philo->r_fork);
		print_state(philo, "has taken a right fork");
	}
}

void	take_eat(t_philo *philo)
{
	take_forks(philo);
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->table->meal_lock);
	philo->last_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(&philo->table->meal_lock);
	ft_usleep(philo->table->t_eat, philo->table);
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
	long	think_time;

	print_state(philo, "is thinking");
	if (philo->table->n_philo % 2 == 1 || philo->table->t_sleep == 0)
	{
		think_time = philo->table->t_eat * 2 - philo->table->t_sleep;
		if (think_time < 1)
			think_time = 1;
		if (think_time > philo->table->t_die - philo->table->t_eat)
			think_time = philo->table->t_die - philo->table->t_eat;
		if (think_time < 1)
			think_time = 1;
		ft_usleep(think_time, philo->table);
	}
}
