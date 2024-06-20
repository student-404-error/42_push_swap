/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:46:23 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/20 17:43:47 by seong-ki         ###   ########.fr       */
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
		pt = pt->next;
		b_cnt++;
	}
}

void	sort(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
	int	min_move[3];

	while (ft_lstsize(*b) > 0)
	{
		find_min_move(a, b, a_stk, min_move);
		if (min_move[0] * min_move[1] < 0)
		{
			if (min_move[0] < 0)
			{
				while (min_move[0] != 0)
				{
					move_reverse_rotate(a, a_stk, "rra");
					min_move[0]++;
				}
				while (min_move[1] != 0)
				{
					move_rotate(b, b_stk, "rb");
					min_move[1]--;
				}
			}
			else
			{
				while (min_move[0] != 0)
				{
					move_rotate(a, a_stk, "ra");
					min_move[0]--;
				}
				while (min_move[1] != 0)
				{
					move_reverse_rotate(b, b_stk, "rrb");
					min_move[1]++;
				}
			}
		}
		else
		{
			if (min_move[0] + min_move[1] < 0)
			{
				while (min_move[0] != 0 && min_move[1] != 0)
				{
					move_rrr(a, b, a_stk, b_stk);
					ft_printf("rrr\n");
					min_move[0]++;
					min_move[1]++;
				}
				while (min_move[MIN_FLAG(min_move[1], min_move[0])] != 0)
				{
					if (MIN_FLAG(min_move[1], min_move[0]))
						move_reverse_rotate(b, b_stk, "rrb");
					else
						move_reverse_rotate(a, a_stk, "rra");
					min_move[MIN_FLAG(min_move[1], min_move[0])]++;
				}
			}
			else
			{
				while (min_move[0] != 0 && min_move[1] != 0)
				{
					move_rr(a, b, a_stk, b_stk);
					ft_printf("rr\n");
					min_move[0]--;
					min_move[1]--;
				}
				while (min_move[MAX_FLAG(min_move[1], min_move[0])] != 0)
				{
					if (MAX_FLAG(min_move[1], min_move[0]))
						move_rotate(b, b_stk, "rb");
					else
						move_rotate(a, a_stk, "ra");
					min_move[MAX_FLAG(min_move[1], min_move[0])]--;
				}
			}
		}
		move_push(a, b, a_stk, b_stk);
		ft_printf("pa\n");
	}
}
