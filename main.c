/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:16:14 by eteixeir          #+#    #+#             */
/*   Updated: 2026/03/31 11:13:42 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_context	*new_context()
{	t_context *context;
	
	context = (t_context *) malloc(sizeof(t_context));
	if(!context)
		return (NULL);
	context->number_of_philosophers = 0;
	context->time_to_die = 0;
	context->time_to_eat = 0;
	context->time_to_sleep = 0;
	context->number_of_times_each_philosopher_must_eat = 0;
	return (context);
}

int main (int ac, char **av)
{
	t_context *context;
	int			i;
	
	if (ac == 6 || ac == 5)
	{
		context = new_context();
		if (!context)
			return (1);
		i = 0;
		while (++i < ac - 1)
		{
			if (!is_valid_arg(av[i]))
				return (1);
		}
		context->number_of_philosophers = ft_atoi(av[1]);
		context->time_to_die = ft_atoi(av[2]);
		context->time_to_eat = ft_atoi(av[3]);
		context->time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			context->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);

		printf("\nPhilosophers => %d \nTime to die => %d \nTime to eat => %d\nTime to sleep => %d \nNumber Of Times Each Philosopher Must Eat => %d\n\n",
		context->number_of_philosophers,
		context->time_to_die,
		context->time_to_eat,
		context->time_to_sleep,
		context->number_of_times_each_philosopher_must_eat);
	}
	else
		return (1);
	return (0);
}