/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:05:00 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/18 16:04:38 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_table	*init_data(int ac, char **av)
{
	t_table	*t;
	
	t = malloc(sizeof(t_table *));
	if (!t)
		return (NULL);
	if (!parse(ac, av, t))
		return (printf("Error: Invalid arguments!"), free(t), NULL);
	printf ("Total: %d Morrer: %d Comer: %d Dormir: %d Refeicoes: %d\n",
		t->n_philo, t->t_die, t->t_eat, t->t_sleep, t->must_eat);
	return (t);
}