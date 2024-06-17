/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:34:09 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/16 19:32:46 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move_rotate(t_list **lst, t_stack **stack)
{
	t_list	*first;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	(void) stack;
	*lst = first->next;
	first->prev = NULL;
//	(*stack)->top = *lst;
	first->next = NULL;
//	(*stack)->bottom = first;
	ft_lstadd_back(lst, first);
}
/*
void	move_rr(t_list **a_stack, t_list **b_stack)
{
	move_rotate(a_stack);
	move_rotate(b_stack);
}
*/

void	move_reverse_rotate(t_list **lst, t_stack **stack)
{
	t_list	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = *lst;
	while (last->next->next)
		last = last->next;
	last->prev = NULL;
	ft_lstadd_front(lst, last->next);
	(*stack)->top = last->next;
	last->next = NULL;
	(*stack)->bottom = last;
}
/*
void	move_rrr(t_list **a_stack, t_list **b_stack)
{
	move_reverse_rotate(a_stack);
	move_reverse_rotate(b_stack);
}*/
