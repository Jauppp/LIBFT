/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:35:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/11/16 15:25:28 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_callocword(char const *s, int c, int next_word)
{
	int		len;
	int		temp_j;
	char	*word;

	temp_j = next_word;
	len = 0;
	while (s[next_word] && s[next_word] != c)
	{
		next_word++;
		len++;
	}
	word = ft_calloc(len + 1, sizeof (char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + temp_j, len + 1);
	return (word);
}

int	ft_countwords(const char *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
		i++;
	}
	if (s[i - 1] == c)
		count--;
	return (count + 1);
}

void	*freeall(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb_words;
	int		next_word;
	char	**arr;

	if (!s || s[0] == 0)
		return (ft_calloc(1, sizeof (char *)));
	nb_words = ft_countwords(s, c);
	arr = ft_calloc(nb_words + 1, sizeof (char *));
	if (!arr)
		return (arr);
	arr[nb_words] = NULL;
	next_word = 0;
	i = 0;
	while (i < nb_words)
	{
		while (s[next_word] && s[next_word] == c)
			next_word++;
		arr[i] = ft_callocword(s, c, next_word);
		if (!arr[i])
			return (freeall(arr));
		next_word += ft_strlen(arr[i]);
		i++;
	}
	return (arr);
}
