/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_invalid_arg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 02:57:42 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/08 03:16:00 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_error_invalid_arg(void)
{
	printf("Erro:");
	printf(" Use ./philo [n_philos] [die] [eat] [sleep] [optional: n_eat]\n");
}
