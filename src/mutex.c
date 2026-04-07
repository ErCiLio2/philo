/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:59:34 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 00:07:45 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int check_simulation_stop(t_context *data)
{
    int stop;

    pthread_mutex_lock(&data->stop_lock);
    stop = data->simulation_stop;
    pthread_mutex_unlock(&data->stop_lock);
    return (stop);
}