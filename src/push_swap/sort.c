/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:46:23 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/03 18:00:08 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	change_state(t_list *a, t_stack *a_stk)
{
	int	cnt;
	int	size;

	size = ft_lstsize(a);
	cnt = 0;
	while (a->idx > a_stk->min)
	{
		a = a->next;
		cnt++;
	}
	if (cnt > (size / 2))
		return (cnt - size);
	return (cnt);
}

int	set_minimum_move(t_list *a, t_list *b)
{
	t_list	*ptr;
	t_list	*last;
	int		cnt;

	cnt = 0;
	ptr = a;
	last = ft_lstlast(a);
	while (ptr->idx < b->idx || last->idx > b->idx)
	{
		cnt++;
		last = ptr;
		ptr = ptr->next;
	}
	if (cnt > (ft_lstsize(a) / 2))
		return (cnt - ft_lstsize(a));
	return (cnt);
}

void	change_min_move(t_list *pt, int min_move[3])
{
	if (pt->move[0] * pt->move[1] < 0)
	{
		if (min_move[2] > ABS(pt->move[0]) + ABS(pt->move[1]))
		{
			min_move[0] = pt->move[0];
			min_move[1] = pt->move[1];
			min_move[2] = ABS(pt->move[0]) + ABS(pt->move[1]);
		}
	}
	else
	{
		if (min_move[2] > MAX(ABS(pt->move[0]), ABS(pt->move[1])))
		{
			min_move[0] = pt->move[0];
			min_move[1] = pt->move[1];
			min_move[2] = MAX(ABS(pt->move[0]), ABS(pt->move[1]));
		}
	}
}

void	find_min_move(t_list **a, t_list **b, t_stack **a_stk, int min_move[3])
{
	t_list	*pt;
	int		b_cnt;

	pt = *b;
	b_cnt = 0;
	min_move[2] = INT_MAX;
	while (pt)
	{
		if (pt->idx > (*a_stk)->max || pt->idx < (*a_stk)->min)
			pt->move[0] = change_state(*a, *a_stk);
		else
			pt->move[0] = set_minimum_move(*a, pt);
		if (b_cnt > (ft_lstsize(*b) / 2))
			pt->move[1] = b_cnt - ft_lstsize(*b);
		else
			pt->move[1] = b_cnt;
		change_min_move(pt, min_move);
		pt = pt->next;
		b_cnt++;
	}
}
