/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 06:46:08 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 13:08:20 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


void init_philos_and_forks(t_context *data)
{
	int i;

	i = -1;
	while (++i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = get_time();
		
		// Atribuição circular de garfos
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philos];
	}
}

int	get_simulation_status(t_context *data)
{
	int	status;

	pthread_mutex_lock(&data->stop_lock);
	status = data->simulation_stop;
	pthread_mutex_unlock(&data->stop_lock);
	return (status);
}

void print_status(t_philo *philo, char *status)
{
    pthread_mutex_lock(&philo->data->write_lock);
    if (!get_simulation_status(philo->data)) // Checagem dupla dentro do lock
    {
        printf("%lld %d %s\n", get_time() - philo->data->start_time, 
               philo->id, status);
    }
    pthread_mutex_unlock(&philo->data->write_lock);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	
	pthread_mutex_lock(&philo->data->start_lock);
	pthread_mutex_unlock(&philo->data->start_lock);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2, philo->data);
	while (!get_simulation_status(philo->data))
	{
		if (philo_eat(philo))
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		print_status(philo, "is thinking");
	}
	return (NULL);
}
