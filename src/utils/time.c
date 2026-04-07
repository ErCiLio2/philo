/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:57:13 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/07 23:44:55 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000LL));
}

void	ft_usleep(long long time_in_ms)
{
	long long	start_time;

	start_time = get_time();
	// Enquanto a diferença entre o tempo atual e o inicial for menor que o desejado
	while ((get_time() - start_time) < time_in_ms)
	{
		// Dormimos um intervalo minúsculo (500 microsegundos) 
		// para não sobrecarregar a CPU com o loop while
		usleep(500);
	}
}