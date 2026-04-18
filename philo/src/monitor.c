/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:52:57 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/18 20:11:45 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int simulation_finished(t_table *table)
{
    int res;

    pthread_mutex_lock(&table->meal_lock); // Use o seu lock de controle
    res = table->stop;
    pthread_mutex_unlock(&table->meal_lock);
    return (res);
}
int	check_death(t_table *table)
{
	int		i;
	long	now;
	
	i = -1;
	while (++i < table->n_philo)
	{
		pthread_mutex_lock(&table->meal_lock);
		now = get_time() - table->philos[i].last_meal;
		pthread_mutex_unlock(&table->meal_lock);
		if (now > table->t_die)
		{
			print_state(&table->philos[i], "died");
			pthread_mutex_lock(&table->meal_lock); // Proteja a escrita!
			table->stop = 1;
			pthread_mutex_unlock(&table->meal_lock);
			return (1);
		}
	}
	return (0);
	
}

int check_meals(t_table *table)
{
	int i;
	int finished_eating;

	if (table->must_eat == -1)
		return (0);
	i = -1;
	finished_eating = 0;
	while (++i < table->n_philo)
	{
		pthread_mutex_lock(&table->meal_lock);
		if (table->philos[i].meals >= table->must_eat)
			finished_eating++;
		pthread_mutex_unlock(&table->meal_lock);
	}
	if (finished_eating == table->n_philo)
	{
		pthread_mutex_lock(&table->meal_lock);
		table->stop = 1;
		pthread_mutex_unlock(&table->meal_lock);
		return (1);
	}
	return (0);
}

void    monitor(t_table *table)
{
    while (!simulation_finished(table))
    {
        if (check_death(table))
            break;
        if (check_meals(table))
            break;
        ft_usleep(1000, table);
    }
}
