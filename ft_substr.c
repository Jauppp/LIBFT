/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:30:23 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/11/16 18:12:06 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*substr;

	if (!s || !len)
		return (ft_calloc(1, sizeof (char)));
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, sizeof (char)));
	i = start;
	while (s[i] && i < len)
		i++;
	//printf("i = %lu\n", i);
	substr = ft_calloc(i + 1, sizeof (char));
	//printf("substr len %lu\n", ft_strlen(substr) + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	return (substr);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("hola", 2, 1));
// }
