/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:02:24 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/18 20:09:42 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	int		i;
	
	if (ac < 5  || ac > 6)
	{
		printf("Erro: use: ./philo n t_die t_eat t_sleep [must_eat]");
		return (1);
	}
	if (!init_table(&table,ac, av+1))
		return (1);
	i = -1;
	table.stop = 0;
	init_simalation(&table);
	cleanup(&table);
	return (0);
}