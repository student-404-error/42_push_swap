/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:34:09 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/05 15:45:27 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	move_rotate(t_list **stack)
{
	t_list	*first;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
}

void	move_rr(t_list **a_stack, t_list **b_stack)
{
	move_rotate(a_stack);
	move_rotate(b_stack);
}

void	move_reverse_rotate(t_list **stack)
{
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	ft_lstadd_front(stack, last->next);
	last->next = NULL;
}

void	move_rrr(t_list **a_stack, t_list **b_stack)
{
	move_reverse_rotate(a_stack);
	move_reverse_rotate(b_stack);
}
