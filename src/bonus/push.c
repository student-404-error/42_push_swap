/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:01:30 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/21 21:17:54 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push(t_list **to_lst, t_list **fr_lst)
{
	t_list	*node;

	if (*fr_lst == NULL)
		return ;
	node = *fr_lst;
	*fr_lst = (*fr_lst)->next;
	if (*fr_lst)
		(*fr_lst)->prev = NULL;
	node->next = NULL;
	ft_lstadd_front(to_lst, node);
}
