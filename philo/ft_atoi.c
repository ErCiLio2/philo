/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteixeir <eteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:33:04 by eteixeir          #+#    #+#             */
/*   Updated: 2026/04/18 16:03:02 by eteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_num(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (!is_digit(*s++))
			return (0);
	}
	return (1);
}

int	ft_atoi(char *s)
{
	long	nbr;

	if (!s)
		return (0);
	nbr = 0;
	while (is_digit(*s))
		nbr = nbr * 10 + (*s++ - '0');
	return ((long)nbr);
}
