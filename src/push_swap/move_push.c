/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:01:30 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/05 15:35:39 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	move_push(t_list **to_stack, t_list **from_stack)
{
	t_list	*node;

	if (*from_stack == NULL)
		return ;
	node = *from_stack;
	*from_stack = (*from_stack)->next;
	node->next = NULL;
	ft_lstadd_front(to_stack, node);
}
