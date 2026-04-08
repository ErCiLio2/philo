/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:03:08 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 03:04:43 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void	set_simulation_stop(t_context *data)
{
	pthread_mutex_lock(&data->stop_lock);
	data->simulation_stop = 1;
	pthread_mutex_unlock(&data->stop_lock);
}

void	*monitor_routine(void *arg)
{
	t_context	*data;
	int			i;
	int			n_eat;
	int			philos_full;

	data = (t_context *)arg;
	n_eat = data->number_of_times_each_philosopher_must_eat;
	while (1)
	{
		philos_full = 0;
		i = -1;
		while (++i < data->number_of_philosophers)
		{
			pthread_mutex_lock(&data->meal_lock);
			if (n_eat != -1 && data->philos[i].meals_eaten >= n_eat)
				philos_full++;
			pthread_mutex_unlock(&data->meal_lock);
		}
		if ((n_eat != -1) && (philos_full == data->number_of_philosophers))
			return (set_simulation_stop(data), NULL);
		usleep(1000);
	}
	return (NULL);
}
