/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:46:06 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/11/08 11:32:45 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	return (i);
}

int	ft_issign(const char *str, int i)
{
	int	sign;

	sign = 1;
	if (str[i] == '-')
		return (-sign);
	else
		return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nbr;

	nbr = 0;
	if (!nptr)
		return (1);
	i = ft_isspace(nptr);
	sign = ft_issign(nptr, i);
	if (sign < 0 || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return (nbr * sign);
}
