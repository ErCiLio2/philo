/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:07:50 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/18 16:24:14 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	cleanup(t_table *t)
{
	int	i;
	
	pthread_mutex_destroy(&t->lock);
	pthread_mutex_destroy(&t->write);
	pthread_mutex_destroy(&t->start);
	i = -1;
	while (++i < t->n_philo)
		pthread_mutex_destroy(&t->forks[i]);
	free(t->forks);
	free(t->philos);
}
