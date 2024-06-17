/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:28:43 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/17 21:08:42 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"
/*
void	check_min_cost(t_list *lst, int range)
{
	int	cnt;

	cnt = 0;
	while (lst->content >= range)
	{
		cnt++;
		lst = lst->next;
	}
}*/

void	push_b(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
	int	cnt;
	int	size;
	int	i;

	cnt = 3;
	size = ft_lstsize(*a);
	i = size / 3;
	while (cnt)
	{
		while ((*a_stk)->min <= i)
		{
			if ((*a)->idx <= i && (*a)->lis != -1)
				move_push(b, a, b_stk, a_stk);
			else
				move_rotate(a, a_stk);
		}
		i += size / 3 + 1;
		cnt--;
	}
}

void	passing_to_b(t_list *a, t_list *b)
{
	t_stack	*a_stk;
	t_stack	*b_stk;

	a_stk = ft_new_stack(a);
	b_stk = ft_new_stack(b);
	status_list_and_stack(a, a_stk, "a");
	status_list_and_stack(b, b_stk, "b");
	push_b(&a, &b, &a_stk, &b_stk);
	status_list_and_stack(a, a_stk, "a");
	status_list_and_stack(b, b_stk, "b");
}
