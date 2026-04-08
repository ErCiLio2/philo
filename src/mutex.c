/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:59:34 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 02:27:32 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/** Inicialização dos Mutexes de Controle */
void	mutex_init(t_context *data)
{
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	pthread_mutex_init(&data->stop_lock, NULL);
}

int	check_simulation_stop(t_context *data)
{
	int	stop;

	pthread_mutex_lock(&data->stop_lock);
	stop = data->simulation_stop;
	pthread_mutex_unlock(&data->stop_lock);
	return (stop);
}
