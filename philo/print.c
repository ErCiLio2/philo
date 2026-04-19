/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:21:16 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/19 17:09:15 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	print_state(t_philo *philo, char *str)
{
	int	stop;

	pthread_mutex_lock(&philo->table->meal_lock);
	stop = philo->table->stop;
	pthread_mutex_unlock(&philo->table->meal_lock);
	if (!stop)
	{
		pthread_mutex_lock(&philo->table->write);
		printf("%ld %d %s\n", timestamp(philo->table), philo->id, str);
		pthread_mutex_unlock(&philo->table->write);
	}
}
