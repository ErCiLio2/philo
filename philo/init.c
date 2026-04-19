/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 15:05:00 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/19 16:59:14 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void init_forks(t_table *table)
{
	int	i;

	if (!table)
		return ;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philo);
	if (!table->forks)
		return ;
	i = -1;
	while (++i < table->n_philo)
		pthread_mutex_init(&table->forks[i], NULL);
}

void init_philos(t_table *table)
{
	int	i;

	if (!table)
		return ;
	table->philos = malloc(sizeof(t_philo) * table->n_philo);
	if (!table->philos)
		return ;
	i = -1;
	table->start_time = get_time();
	while (++i < table->n_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals = 0;
		table->philos[i].last_meal = table->start_time;
		table->philos[i].l_fork = &table->forks[i];
		table->philos[i].r_fork = &table->forks[(i + 1) % table->n_philo];
		table->philos[i].table = table;
	}
}

void init_mutex_table(t_table *table)
{
	pthread_mutex_init(&table->write, NULL);
	pthread_mutex_init(&table->lock, NULL);
	pthread_mutex_init(&table->start, NULL);
	pthread_mutex_init(&table->meal_lock, NULL);
}

int	init_table(t_table *table, int ac, char **av)
{
	if (!parse(ac, av, table))
		return (printf("Error: Invalid arguments!"), 0);
	init_forks(table);
	init_philos(table);
	if (!table->forks || !table->philos)
		return (cleanup(table), 0);
	init_mutex_table(table);
	return (1);
}

void	init_simalation(t_table *t)
{
	int	i;
	
	i = -1;
	while (++i < t->n_philo)
		pthread_create(&t->philos[i].thread, NULL, routine, &t->philos[i]);
	usleep(1000);
	monitor(t);
	i = -1;
	while (++i < t->n_philo)
		pthread_join(t->philos[i].thread, NULL);
}
