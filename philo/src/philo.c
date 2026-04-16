/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 06:46:08 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 03:04:31 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_simulation_status(t_context *data)
{
	int	status;

	pthread_mutex_lock(&data->stop_lock);
	status = data->simulation_stop;
	pthread_mutex_unlock(&data->stop_lock);
	return (status);
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (get_simulation_status(philo->data) && ft_strcmp(msg, "died") != 0)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return ;
	}
	printf("%lld %d %s\n",
		get_time() - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->write_lock);
}

int	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	if (philo->data->number_of_philosophers == 1)
	{
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return (-1);
	}
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->data->meal_lock);
	ft_usleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (get_simulation_status(philo->data) == 0)
	{
		if (philo_eat(philo) == -1)
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (NULL);
}
