/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:16:14 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 03:00:10 by eteixeir         ###   ########.fr       */
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
	data->number_of_philosophers = ft_atoi(av[0]);
	data->time_to_die = ft_atoi(av[1]);
	data->time_to_eat = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	if (ac == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[4]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	if ((data->number_of_philosophers < 1)
		|| (ac == 6 && data->number_of_times_each_philosopher_must_eat <= 0))
		return (clear_data(data), NULL);
	return (data);
}

t_context	*set_initial_data(int ac, char **av)
{
	t_context	*data;
	int			philos;

	data = parse(ac, av);
	if (!data)
		return (NULL);
	philos = data->number_of_philosophers;
	data->forks = malloc(sizeof(pthread_mutex_t) * philos);
	data->philos = malloc(sizeof(t_philo) * philos);
	if (!data->forks || !data->philos)
		return (clear_data(data), NULL);
	mutex_init(data);
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
	data->start_time = get_time();
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL,
				&philo_routine, &data->philos[i]) != 0)
			return (clear_data(data), 1);
	}
	monitor_routine(data);
	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_join(data->philos[i].thread, NULL);
	return (clear_data(data), 0);
}
