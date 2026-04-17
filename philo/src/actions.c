/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:10:02 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 13:05:47 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	just_one_filo(t_philo *philo)
{
	if (philo->data->num_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		ft_usleep(philo->data->time_to_die, philo->data);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

int	take_forks_and_check(t_philo *philo,
	pthread_mutex_t	*first, pthread_mutex_t *second)
{
	if (get_simulation_status(philo->data))
		return (1);
	if (first == second)
		return (1);
	pthread_mutex_lock(first);
	print_status(philo, "has taken a fork");
	if (get_simulation_status(philo->data))
	{
		pthread_mutex_unlock(first);
		return (1);
	}
	pthread_mutex_lock(second);
	print_status(philo, "has taken a fork");
	if (get_simulation_status(philo->data))
	{
		pthread_mutex_unlock(second);
		pthread_mutex_unlock(first);
		return (1);
	}
	return (0);
}

int	philo_eat(t_philo *philo)
{
	pthread_mutex_t	*f;
	pthread_mutex_t	*s;

	if (just_one_filo(philo))
		return (1);
	if (philo->left_fork < philo->right_fork) {
		f = philo->left_fork;
		s = philo->right_fork;
	} else {
		f = philo->right_fork;
		s = philo->left_fork;
	}
	if (take_forks_and_check(philo, f, s))
		return (1);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(s);
	pthread_mutex_unlock(f);
	return (0);
}
