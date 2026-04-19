/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:06:50 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/19 17:09:29 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	parse(int ac, char **av, t_table *t)
{
	int		i;

	i = -1;
	while (++i < ac - 1)
	{
		if (!is_num(av[i]))
			return (0);
	}
	t->n_philo = ft_atoi(av[0]);
	if (t->n_philo == 0)
		return (0);
	t->t_die = ft_atoi(av[1]);
	t->t_eat = ft_atoi(av[2]);
	t->t_sleep = ft_atoi(av[3]);
	if (ac == 6)
		t->must_eat = ft_atoi(av[4]);
	else
		t->must_eat = -1;
	return (1);
}
