/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:27:23 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/18 20:11:45 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long	timestamp(t_table *table)
{
	return (get_time() - table->start_time);
}

void	ft_usleep(long time, t_table *table)
{
	long	start;

	start = get_time();
	// Enquanto o tempo não passar E a simulação não parar
	while ((get_time() - start) < time)
	{
		// Se alguém morreu, para de dormir imediatamente
		pthread_mutex_lock(&table->meal_lock);
		if (table->stop)
		{
			pthread_mutex_unlock(&table->meal_lock);
			break ;
		}
		pthread_mutex_unlock(&table->meal_lock);
		
		// Dorme um pouquinho (500 microsegundos) para soltar a CPU
		usleep(500); 
	}
}
