/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:02:24 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/19 17:11:44 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac < 5 || ac > 6)
	{
		printf("Erro: use: ./philo n t_die t_eat t_sleep [must_eat]");
		return (1);
	}
	table.stop = 0;
	if (!init_table(&table, ac, av + 1))
		return (1);
	init_simalation(&table);
	cleanup(&table);
	return (0);
}
