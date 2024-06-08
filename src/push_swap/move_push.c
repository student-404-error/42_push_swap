/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:01:30 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/08 02:43:08 by seong-ki         ###   ########.fr       */
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
	return (comp * flag);
}

void	move_push(t_list **to_lst, t_list **fr_lst, t_stack **to, t_stack **fr)
{
	t_list	*node;

	if (*fr_lst == NULL)
		return ;
	node = *fr_lst;
	*fr_lst = (*fr_lst)->next;
	(*fr)->top = *fr_lst;
	if (*fr_lst == NULL)
		(*fr)->bottom = *fr_lst;
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
	(*to)->top = *to_lst;
	(*to)->bottom = ft_lstlast(*to_lst);
	/*
	 * 나올 수 있는 경우의 수를 계산 해봅시다.
	 * min이 push됨
	 * 	if node == a_stack->min:
	 * 		min 새로고침 a
	 * max가 push됨
	 * 	if node == a->max:
	 * 그외 아무것도 아닌 것이 push됨
	 *	알빠아님.
	 *
	 *
	 * */
}
