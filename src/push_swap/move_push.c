/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:01:30 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/16 19:36:01 by seong-ki         ###   ########.fr       */
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
	comp = origin->content * flag;
	while (origin)
	{
		if (comp < origin->content * flag)
			comp = origin->content * flag;
		origin = origin->next;
	}
	return (comp * flag);	comp = origin->content;
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
	if (node->content == (*fr)->min)
		(*fr)->min = update_stack(*fr_lst, -1);
	if (node->content == (*fr)->max)
		(*fr)->max = update_stack(*fr_lst, 1);
	if ((*to)->min > node->content)
		(*to)->min = node->content;
	if ((*to)->max < node->content)
		(*to)->max = node->content;
	(*fr)->top = *fr_lst;
	(*to)->top = *to_lst;
	(*to)->bottom = ft_lstlast(*to_lst);
}
