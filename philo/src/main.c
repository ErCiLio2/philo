/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:16:14 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 13:04:36 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_context	*parse(int ac, char **av)
{
	int				i;
	t_context		*data;

	data = (t_context *) malloc(sizeof(t_context));
	if (!data)
		return (NULL);
	i = -1;
	while (++i < ac - 1)
	{
		if (!is_valid_arg(av[i]))
			return (printf("Erro: Argumentos inválidos"),
				clear_data(data), NULL);
	}
	data->num_philos = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[4]);
	else
		data->must_eat = -1;
	if ((data->num_philos < 1)
		|| (ac == 6 && data->must_eat <= 0))
		return (clear_data(data), NULL);
	return (data);
}

static t_context	*set_initial_data(int ac, char **av)
{
	t_context	*data;

	data = parse(ac, av);
	if (!data)
		return (NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->forks || !data->philos)
		return (clear_data(data), NULL);
	if (mutex_init(data) != 0)
	{
		printf("Erro: Falha ao inicializar mutexes\n");
		return (clear_data(data), NULL);
	}
	data->simulation_stop = 0;
	init_philos_and_forks(data);
	return (data);
}

int	main(int ac, char **av)
{
	t_context	*data;
	int			i;

	if (ac != 5 && ac != 6)
		return (print_error_invalid_arg(), 1);
	data = set_initial_data(ac, av + 1);
	if (!data)
		return (1);
	pthread_mutex_lock(&data->start_lock);
	data->start_time = get_time();
	i = -1;
	while (++i < data->num_philos)
	{
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL,
				&philo_routine, &data->philos[i]) != 0)
			return (clear_data(data), 1);
	}
	pthread_mutex_unlock(&data->start_lock);
	monitor_routine(data);
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i].thread, NULL);
	clear_data(data);
	return (0);
}
