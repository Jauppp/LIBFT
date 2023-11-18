/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:34:59 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/11/17 20:34:59 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	nb;

	nb = '0' + n;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1; 
	}
	if (n < 9)
	{
		nb = '0' + n;
		write(fd, &nb, 1);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr_fd(fd, n / 10);
		nb = '0' + n % 10;
		write(fd, &nb, 1); 
	}
	else
	{
		nb = '0' + n;
		write(fd, &nb, 1);
	}
}

int	main(void)
{
	ft_putnbr_fd(15889, 1);
}
