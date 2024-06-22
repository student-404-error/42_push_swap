/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:34:09 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/22 19:14:50 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate(t_list **lst)
{
	t_list	*first;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	*lst = first->next;
	first->prev = NULL;
	first->next = NULL;
	ft_lstadd_back(lst, first);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = *lst;
	while (last->next->next)
		last = last->next;
	last->prev = NULL;
	ft_lstadd_front(lst, last->next);
	last->next = NULL;
}

void	move_rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
