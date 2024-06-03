/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:19:11 by seong-ki          #+#    #+#             */
/*   Updated: 2024/05/21 19:29:27 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_ptr;

	if (!*lst || !*del)
		return ;
	lst_ptr = *lst;
	while (*lst)
	{
		(*del)(lst_ptr->content);
		*lst = lst_ptr->next;
		free(lst_ptr);
		lst_ptr = *lst;
	}
}
