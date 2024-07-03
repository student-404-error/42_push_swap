/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:34:09 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/03 17:13:22 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	move_rotate(t_list **lst, t_stack **stack, char *title)
{
	t_list	*first;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	(void) stack;
	*lst = first->next;
	first->prev = NULL;
	(*stack)->top = *lst;
	first->next = NULL;
	(*stack)->bottom = first;
	ft_lstadd_back(lst, first);
	if (*title != '\0')
		ft_printf("%s\n", title);
}

void	move_rr(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
	move_rotate(a, a_stk, "");
	move_rotate(b, b_stk, "");
	ft_printf("rr\n");
}

void	move_reverse_rotate(t_list **lst, t_stack **stack, char *title)
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
	if (*title != '\0')
		ft_printf("%s\n", title);
}

void	move_rrr(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
	move_reverse_rotate(a, a_stk, "");
	move_reverse_rotate(b, b_stk, "");
	ft_printf("rrr\n");
}
