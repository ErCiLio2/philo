/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:26:01 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/19 17:00:56 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id % 2 == 0)
		ft_usleep(p->table->t_eat, p->table);
	while (!simulation_finished(p->table))
	{
		take_eat(p);
		take_sleep(p);
		take_think(p);
	}
	return (NULL);
}

