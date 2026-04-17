/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:47:13 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/16 23:30:47 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	is_digit(unsigned char c)
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

int	ft_atoi(char *str)
{
	long int	nbr;
	int			signal;

	if (!str)
		return (0);
	signal = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			signal = -1;
	}
	nbr = 0;
	while (*str && is_digit(*str))
	{
		nbr = (nbr * 10) + *str - '0';
		str++;
	}
	return ((int)nbr * signal);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (0 - *s2);
	if (!s2)
		return (*s1 - 0);
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
