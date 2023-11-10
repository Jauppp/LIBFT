/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:29:56 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/11/10 16:29:55 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	// if (nmemb * size > MAX_INT)
	// 	return (0);
	arr = malloc((size) * (nmemb));
	if (!arr)
		return (arr);
	ft_bzero(arr, nmemb);
	return (arr);
}
