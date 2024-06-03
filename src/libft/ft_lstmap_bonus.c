/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:08:53 by seong-ki          #+#    #+#             */
/*   Updated: 2024/05/22 19:42:26 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	void	*tmp;
	t_list	*new_node;

	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		tmp = (*f)(lst->content);
		new_node = ft_lstnew(tmp);
		if (!new_node)
		{
			del(tmp);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
