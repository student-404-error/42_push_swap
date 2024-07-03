/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:23:50 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/03 17:59:45 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	rrr_and_remain(t_lists ab, t_stacks abs, int min_move[3])
{
	while (min_move[0] != 0 && min_move[1] != 0)
	{
		move_rrr(ab.a, ab.b, abs.a_stk, abs.b_stk);
		min_move[0]++;
		min_move[1]++;
	}
	while (min_move[MIN_FLAG(min_move[1], min_move[0])] != 0)
	{
		if (MIN_FLAG(min_move[1], min_move[0]))
			move_reverse_rotate(ab.b, abs.b_stk, "rrb");
		else
			move_reverse_rotate(ab.a, abs.a_stk, "rra");
		min_move[MIN_FLAG(min_move[1], min_move[0])]++;
	}
}

void	rr_and_remain(t_lists ab, t_stacks abs, int min_move[3])
{
	while (min_move[0] != 0 && min_move[1] != 0)
	{
		move_rr(ab.a, ab.b, abs.a_stk, abs.b_stk);
		min_move[0]--;
		min_move[1]--;
	}
	while (min_move[MAX_FLAG(min_move[1], min_move[0])] != 0)
	{
		if (MAX_FLAG(min_move[1], min_move[0]))
			move_rotate(ab.b, abs.b_stk, "rb");
		else
			move_rotate(ab.a, abs.a_stk, "ra");
		min_move[MAX_FLAG(min_move[1], min_move[0])]--;
	}
}

void	ra_rra_rb_rrb(t_lists ab, t_stacks abs, int min_move[3])
{
	if (min_move[0] < 0)
	{
		while (min_move[0]++)
			move_reverse_rotate(ab.a, abs.a_stk, "rra");
		while (min_move[1]--)
			move_rotate(ab.b, abs.b_stk, "rb");
	}
	else
	{
		while (min_move[0]--)
			move_rotate(ab.a, abs.a_stk, "ra");
		while (min_move[1]++)
			move_reverse_rotate(ab.b, abs.b_stk, "rrb");
	}
}

void	sort(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
	int			min_move[3];
	t_lists		ab;
	t_stacks	abs;

	ab.a = a;
	ab.b = b;
	abs.a_stk = a_stk;
	abs.b_stk = b_stk;
	while (ft_lstsize(*b) > 0)
	{
		find_min_move(a, b, a_stk, min_move);
		if (min_move[0] * min_move[1] < 0)
			ra_rra_rb_rrb(ab, abs, min_move);
		else
		{
			if (min_move[0] + min_move[1] < 0)
				rrr_and_remain(ab, abs, min_move);
			else
				rr_and_remain(ab, abs, min_move);
		}
		move_push(a, b, a_stk, b_stk);
		ft_printf("pa\n");
	}
}
