/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:47:13 by eteixeir          #+#    #+#             */
/*   Updated: 2026/03/31 09:57:12 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_digit(unsigned char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_valid_arg(char *arg)
{
	if (!arg || !*arg)
		return (0);
	while (*arg)
	{
		if (!is_digit(*arg++))
			return (0);
	}
	return (1);
}