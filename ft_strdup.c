/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:18:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/11/14 11:24:59 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	arr = malloc((ft_strlen(s) + 1) * sizeof(unsigned char));
	if (!arr)
		return (arr);
	while (s[i])
	{
		arr[i] = ((char *)s)[i];
		i++;
	}
	arr[i] = '\0';
	return ((char *) arr);
}
