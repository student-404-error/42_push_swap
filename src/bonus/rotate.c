/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:34:09 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/25 13:51:52 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate(t_list **lst)
{
	t_list	*first;
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	*lst = first->next;
	(*lst)->prev = NULL;
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*second_to_last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = *lst;
	while (last->next->next)
		last = last->next;
	second_to_last = last;
	last = last->next;
	second_to_last->next = NULL;
	last->prev = NULL;
	last->next = *lst;
	(*lst)->prev = last;
	*lst = last;
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
