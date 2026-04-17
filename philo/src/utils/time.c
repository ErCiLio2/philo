/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 22:57:13 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/17 02:10:59 by eteixeir         ###   ########.fr       */
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

void ft_usleep(long long time_in_ms)
{
    long long start;
    long long remaining;

    start = get_time();
    while (1)
    {
        remaining = time_in_ms - (get_time() - start);
        if (remaining <= 0)
            break;
        if (remaining > 100)
            usleep(100);
        else
            usleep(remaining);
    }
}

