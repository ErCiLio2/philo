/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:16:14 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 00:08:32 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static t_context	*parse(int ac, char **av)
{
	int				i;
	t_context		*data;
	
	data = (t_context *) malloc(sizeof(t_context));
	if(!data)
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
		(data->number_of_times_each_philosopher_must_eat = ft_atoi(av[4]));
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	if ((data->number_of_philosophers < 1 ) ||
		(ac == 6 && data->number_of_times_each_philosopher_must_eat <= 0))
		return (clear_data(data), NULL);
	return (data);
}

t_context	*set_initial_data(int ac, char **av)
{	t_context		*data;
	int				i;
	int				n_philos;
	
	data = parse(ac, av);
	if(!data)
		return (NULL);
	n_philos = data->number_of_philosophers;
	data->forks = malloc(sizeof(pthread_mutex_t) * n_philos);
	i = -1;
	while (++i < n_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		// Dentro do seu loop de inicialização
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
	    data->philos[i].last_meal_time = get_time();
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % n_philos];
	}
	pthread_mutex_init(&data->write_lock, NULL);
	return (data);
}

static void	visualise(t_context *data)
{
	printf("\nPhilosophers => %d \nTime to die => %d \nTime to eat => %d\n",
	data->number_of_philosophers,
	data->time_to_die,
	data->time_to_eat);
	printf("Time to sleep => %d \n",
	data->time_to_sleep);
	printf("Number Of Times Each Philosopher Must Eat => %d\n\n",
	data->number_of_times_each_philosopher_must_eat);
}

int main (int ac, char **av)
{
	t_context	*data;
	long long	current_timestamp;
	int			i;
	// pthread_mutex_t *forks;
	
	if (ac != 5 && ac != 6)
    {
        printf("Erro: Use ./philo [n_philos] [die] [eat] [sleep] [optional: eat_count]\n");
        return (1);
    }
    data = set_initial_data(ac, av+1);
    if (!data)
        return (1);
	while (i < data->number_of_philosophers)
	{
		// pthread_create(id_da_thread, NULL, funcao_da_rotina, ponteiro_do_filosofo);
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine, &data->philos[i]) != 0)
			return (clear_data(data), 1);
		i++;
	}
	data->start_time = get_time();
    visualise(data);
    clear_data(data);
    return (0);
}
