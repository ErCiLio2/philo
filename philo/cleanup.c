/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:07:50 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/19 17:12:34 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	cleanup(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->meal_lock);
	pthread_mutex_destroy(&table->write);
	pthread_mutex_destroy(&table->lock);
	pthread_mutex_destroy(&table->start);
	i = -1;
	while (++i < table->n_philo)
		pthread_mutex_destroy(&table->forks[i]);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}
