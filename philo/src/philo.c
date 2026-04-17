/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 06:46:08 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 02:13:40 by eteixeir         ###   ########.fr       */
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

int	get_simulation_status(t_context *data)
{
	int	status;

	pthread_mutex_lock(&data->stop_lock);
	status = data->simulation_stop;
	pthread_mutex_unlock(&data->stop_lock);
	return (status);
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->write_lock);
	if (get_simulation_status(philo->data) && ft_strcmp(msg, "died") != 0)
	{
		pthread_mutex_unlock(&philo->data->write_lock);
		return ;
	}
	printf("%lld %d %s\n",
		get_time() - philo->data->start_time,
		philo->id,
		msg);
	pthread_mutex_unlock(&philo->data->write_lock);
}
int philo_eat(t_philo *philo)
{
    pthread_mutex_t *first;
    pthread_mutex_t *second;
    int left = philo->id - 1;
    int right = philo->id % philo->data->number_of_philosophers;

    if (philo->data->number_of_philosophers == 1)
    {
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork");
        ft_usleep(philo->data->time_to_die);
        pthread_mutex_unlock(philo->left_fork);
        return (1);
    }

    if (left < right)
    {
        first = &philo->data->forks[left];
        second = &philo->data->forks[right];
    }
    else
    {
        first = &philo->data->forks[right];
        second = &philo->data->forks[left];
    }

    pthread_mutex_lock(first);
    print_status(philo, "has taken a fork");

    pthread_mutex_lock(second);
    print_status(philo, "has taken a fork");

    if (get_simulation_status(philo->data))
    {
        pthread_mutex_unlock(second);
        pthread_mutex_unlock(first);
        return (1);
    }

    print_status(philo, "is eating");

    pthread_mutex_lock(&philo->data->meal_lock);
    philo->last_meal_time = get_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->data->meal_lock);

    ft_usleep(philo->data->time_to_eat);

    pthread_mutex_unlock(second);
    pthread_mutex_unlock(first);

    return (0);
}


void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        usleep(500);

    while (!get_simulation_status(philo->data))
    {
        if (philo_eat(philo))
            break;

        print_status(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep);

        print_status(philo, "is thinking");
    }
    return (NULL);
}

