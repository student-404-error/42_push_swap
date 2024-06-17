/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:59:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/05 15:44:41 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	move_swap(t_list **lst, t_stack **stk)
{
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = (*lst)->next;
	tmp->prev = NULL;
	(*lst)->next = tmp->next;
	if (tmp->next)
        tmp->next->prev = *lst;
	tmp->next = *lst;
	(*lst)->prev = tmp;
	*lst = tmp;
	(*stk)->top = *lst;
    if ((*stk)->bottom == (*lst)->next)
		(*stk)->bottom = (*lst)->next;
}
/*
void	move_ss(t_list *a_stack, t_list *b_stack)
{
	move_swap(&a_stack);
	move_swap(&b_stack);
}
*/
