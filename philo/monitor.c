/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:52:57 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/19 17:11:12 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	simulation_finished(t_table *table)
{
	int	res;

	pthread_mutex_lock(&table->meal_lock);
	res = table->stop;
	pthread_mutex_unlock(&table->meal_lock);
	return (res);
}

static int	check_death(t_table *table)
{
	int		i;
	long	time_since_meal;

	i = -1;
	while (++i < table->n_philo)
	{
		pthread_mutex_lock(&table->meal_lock);
		time_since_meal = get_time() - table->philos[i].last_meal;
		if (time_since_meal > table->t_die && !table->stop)
		{
			table->stop = 1;
			pthread_mutex_unlock(&table->meal_lock);
			printf("%ld %d %s\n",
				timestamp(table), table->philos[i].id, "died");
			return (1);
		}
		pthread_mutex_unlock(&table->meal_lock);
	}
	return (0);
}

static int	check_meals(t_table *table)
{
	int	i;
	int	finished_eating;

	if (table->must_eat == -1)
		return (0);
	i = -1;
	finished_eating = 0;
	pthread_mutex_lock(&table->meal_lock);
	while (++i < table->n_philo)
	{
		if (table->philos[i].meals >= table->must_eat)
			finished_eating++;
	}
	if (finished_eating == table->n_philo)
	{
		table->stop = 1;
		pthread_mutex_unlock(&table->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->meal_lock);
	return (0);
}

void	monitor(t_table *table)
{
	while (1)
	{
		if (check_death(table) || check_meals(table))
			break ;
		usleep(1000);
	}
}
