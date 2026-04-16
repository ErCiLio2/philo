/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:57:13 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 02:23:04 by eteixeir         ###   ########.fr       */
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
	while ((get_time() - start_time) < time_in_ms)
		usleep(500);
}
