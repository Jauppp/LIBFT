/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:07:53 by cdomet-d          #+#    #+#             */
/*   Updated: 2023/11/22 17:16:27 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstcpy;
	t_list	*temp;
	void	*new_content;

	if (!f || !del)
		return (NULL);
	lstcpy = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		temp = ft_lstnew(new_content);
		if (!temp)
		{
			del(new_content);
			ft_lstclear(&lstcpy, del);
			return (NULL);
		}
		ft_lstadd_back(&lstcpy, temp);
		lst = lst->next;
	}
	return (lstcpy);
}
