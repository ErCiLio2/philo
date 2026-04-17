/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 03:03:08 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 12:11:24 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// No seu monitor ou onde quer que a simulação pare
void set_simulation_status(t_context *data)
{
    pthread_mutex_lock(&data->stop_lock);
    data->simulation_stop = 1;
    pthread_mutex_unlock(&data->stop_lock);
}

/**
 * Checa se o filosofo esta morto
 */
int	check_death(t_philo *philo)
{
	long long	last_meal;
	int			meals_eaten;
	t_context	*data;

	data = philo->data;
	last_meal = philo->last_meal_time;
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&data->meal_lock);
	if (get_time() - last_meal > data->time_to_die)
	{
		pthread_mutex_lock(&data->stop_lock);
		data->simulation_stop = 1;
		pthread_mutex_unlock(&data->stop_lock);
		pthread_mutex_lock(&data->write_lock);
		printf("%lld %d died\n", get_time() - data->start_time, philo->id);
		pthread_mutex_unlock(&data->write_lock);
		return (1);
	}
	return (0);
}

/**
 * Checa se o filosofo esta Satisfeito
 * Parms:
 * Philo: dados do filosofo
 * Quantidade de filosophos satisefeitos
 */
void	check_satisfied(t_philo *philo, int *full_philos)
{
	t_context	*data;

	data = philo->data;
	pthread_mutex_lock(&data->meal_lock); // Proteja a leitura de meals_eaten
	if (data->must_eat != -1 && philo->meals_eaten >= data->must_eat)
		(*full_philos)++; // Incrementa o VALOR apontado
	pthread_mutex_unlock(&data->meal_lock);
}

int	check(t_context *data)
{
	int	i;
	int	full_philos;

	full_philos = 0;
	i = -1;
	while (++i < data->num_philos)
	{
		// check_death e check_satisfied agora cuidam de seus próprios locks
		if (check_death(&data->philos[i]))
			return (1);
		check_satisfied(&data->philos[i], &full_philos);
	}
	if (data->must_eat != -1 && full_philos == data->num_philos)
	{
		set_simulation_status(data);
		return (1);
	}
	return (0);
}

/**
 * Monitoramento da rotina
 */
void	*monitor_routine(t_context *data)
{
	if (!data)
		return (printf("ERRO: data é NULL\n"), NULL);
	if (!data->philos)
		return (printf("ERRO: data->philos é NULL\n"), NULL);
	while (1)
	{
		if (check(data))
			return (NULL);
		usleep(100);
	}
}
