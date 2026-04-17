/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:03:08 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 02:11:36 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	set_simulation_stop(t_context *data)
{
	pthread_mutex_lock(&data->stop_lock);
	data->simulation_stop = 1;
	pthread_mutex_unlock(&data->stop_lock);
}
void *monitor_routine(void *arg)
{
    t_context *data = (t_context *)arg;
    int i;
    int full;

    while (!get_simulation_status(data))
    {
        full = 0;
        i = 0;

        while (i < data->number_of_philosophers)
        {
            pthread_mutex_lock(&data->meal_lock);

            long now = get_time();
            long time_since_meal = now - data->philos[i].last_meal_time;

            if (time_since_meal > data->time_to_die)
            {
                pthread_mutex_unlock(&data->meal_lock);

                pthread_mutex_lock(&data->stop_lock);
                data->simulation_stop = 1;
                pthread_mutex_unlock(&data->stop_lock);

                print_status(&data->philos[i], "died");
                return (NULL);
            }

            if (data->number_of_times_each_philosopher_must_eat != -1 &&
                data->philos[i].meals_eaten >= data->number_of_times_each_philosopher_must_eat)
                full++;

            pthread_mutex_unlock(&data->meal_lock);
            i++;
        }

        if (data->number_of_times_each_philosopher_must_eat != -1 &&
            full == data->number_of_philosophers)
        {
            pthread_mutex_lock(&data->stop_lock);
            data->simulation_stop = 1;
            pthread_mutex_unlock(&data->stop_lock);
            return (NULL);
        }

        usleep(100);
    }
    return (NULL);
}
