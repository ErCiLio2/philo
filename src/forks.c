/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:06:26 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 02:26:05 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/** Atribuição dos garfos (Lógica do Círculo)*/
void	init_philos_and_forks(t_context *data)
{
	int	i;
	int	n_philos;

	n_philos = data->number_of_philosophers;
	i = -1;
	while (++i < n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % n_philos];
	}
}
