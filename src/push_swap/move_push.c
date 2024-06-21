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
#include "push_swap.h"
#include "ft_printf.h"

int	update_stack(t_list *origin, int flag)
{
	int	comp;

	if (origin == NULL && flag == -1)
		return (INT_MAX);
	if (origin == NULL && flag == 1)
		return (INT_MIN);
	comp = origin->idx * flag;
	while (origin)
	{
		if (comp < origin->idx * flag)
			comp = origin->idx * flag;
		origin = origin->next;
	}
	return (comp * flag);
}

void	move_push(t_list **to_lst, t_list **fr_lst, t_stack **to, t_stack **fr)
{
	t_list	*node;

	if (*fr_lst == NULL)
		return ;
	node = *fr_lst;
	*fr_lst = (*fr_lst)->next;
	if (*fr_lst)
		(*fr_lst)->prev = NULL;
	else
		(*fr)->bottom = NULL;
	node->next = NULL;
	ft_lstadd_front(to_lst, node);
	if (node->idx == (*fr)->min)
		(*fr)->min = update_stack(*fr_lst, -1);
	if (node->idx == (*fr)->max)
		(*fr)->max = update_stack(*fr_lst, 1);
	if ((*to)->min > node->idx)
		(*to)->min = node->idx;
	if ((*to)->max < node->idx)
		(*to)->max = node->idx;
	(*fr)->top = *fr_lst;
	(*to)->top = *to_lst;
	(*to)->bottom = ft_lstlast(*to_lst);
}
