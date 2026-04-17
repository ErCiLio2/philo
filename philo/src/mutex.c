/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:59:34 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 12:50:59 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/** Inicialização dos Mutexes de Controle */
int	mutex_init(t_context *data)
{
	int	i;

	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->meal_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->stop_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->start_lock, NULL) != 0)
		return (1);
	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
	}
	return (0);
}

int	check_simulation_stop(t_context *data)
{
	int	stop;

	pthread_mutex_lock(&data->stop_lock);
	stop = data->simulation_stop;
	pthread_mutex_unlock(&data->stop_lock);
	return (stop);
}
