/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:16:14 by eteixeir          #+#    #+#             */
/*   Updated: 2026/03/31 09:57:56 by eteixeir         ###   ########.fr       */
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
	context->tmie_to_sleep = 0;
	context->number_of_times_each_philosopher_must_eat = 0;
	return (NULL);
}

int main (int ac, char **av)
{
	t_context *context;
	
	if (ac == 5 || ac == 6)
	{
		context = new_context();
		while (*av && ac--)
		{
			if (is_valid_arg(*av))
				printf("=> %s\n", *av);
			else
				printf("Is Not a Valid arg\n");
			av++;
		}
	}
	return (0);
}