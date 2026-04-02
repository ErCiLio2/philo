/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:16:14 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/02 13:34:57 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_context	*set_initial_data()
{	t_context *data;
	
	data = (t_context *) malloc(sizeof(t_context));
	if(!data)
		return (NULL);
	data->number_of_philosophers = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->number_of_times_each_philosopher_must_eat = 0;
	return (data);
}

static int	parse(int ac, char **av, t_context **data)
{
	int	i;

	if (!data || !*data)
			return (-1);
	i = -1;
	while (++i < ac - 1)
	{
		if (!is_valid_arg(av[i]))
			return (-1);
	}
	(*data)->number_of_philosophers = ft_atoi(av[0]);
	(*data)->time_to_die = ft_atoi(av[1]);
	(*data)->time_to_eat = ft_atoi(av[2]);
	(*data)->time_to_sleep = ft_atoi(av[3]);
	if (ac == 6)
		(*data)->number_of_times_each_philosopher_must_eat = ft_atoi(av[4]);
	return (0);
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
	t_context *data;
	
	if (ac == 6 || ac == 5)
	{
		data = set_initial_data();
		if (parse(ac, av+1, &data) == -1)
			return (1);
		visualise(data);
	}
	else
		return (1);
	return (0);
}
