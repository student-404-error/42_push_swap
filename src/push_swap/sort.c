/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:46:23 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/18 22:01:13 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	change_state(t_list **a, t_stack **a_stk)
{
	t_list	*ptr;
	int		cnt;

	cnt = 0;
	ptr = *a;
	while (ptr->content > (*a_stk)->min)
	{
		ptr = ptr->next;
		cnt++;
	}
	if (cnt > (ft_lstsize(*a) / 2))
	{
		while ((*a_stk)->top->content != (*a_stk)->min)
		{
			move_reverse_rotate(a, a_stk);
			ft_printf("rra\n");
		}
	}
	else
	{
		while ((*a_stk)->top->content != (*a_stk)->min)
		{
			move_rotate(a, a_stk);
			ft_printf("ra\n");
		}
	}
}

void	set_between_min_max(t_list **a, t_stack **a_stk, int b_top)
{
	t_list	*ptr;
	t_list	*last;
	int	cnt;

	cnt = 0;
	ptr = *a;
	last = ft_lstlast(*a);
	while (ptr->content < b_top || last->content > b_top)
	{
		cnt++;
		last = ptr;
		ptr = ptr->next;

	}
	if (cnt > (ft_lstsize(*a) / 2))
	{
		while (cnt < (ft_lstsize(*a)))
		{
			move_reverse_rotate(a, a_stk);
			ft_printf("rra\n");
			cnt++;
		}
	}
	else
	{
		while (cnt)
		{
			move_rotate(a, a_stk);
			ft_printf("ra\n");
			cnt--;
		}
	}
}

void	sort(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
		move_push(a, b, a_stk, b_stk);
		move_push(a, b, a_stk, b_stk);
		ft_printf("pa\n");
		ft_printf("pa\n");
	while (ft_lstsize(*b) > 0)
	{
		// b_list의 꼭대기에 있는거부터 a로 push할 예정임
		// b_Top이 a_max보다 클 때,
		if ((*b)->idx > (*a_stk)->max || (*b)->idx < (*a_stk)->min)
		{
			//ft_printf("out\n");
			change_state(a, a_stk);
		}
		else	// 사이에 있다면
		{
			//ft_printf("between\n");
//			change_state(a, a_stk);
			set_between_min_max(a, a_stk, (*b)->idx);
			// a_top은 b->idx보다 크게
			// a_bottom b->idx 보다 작게
		}
		move_push(a, b, a_stk, b_stk);
		ft_printf("pa\n");
	}
	change_state(a, a_stk);
//	ft_lstsize(*b);
//	int t = (*b_stk)->min;
//	t = 0;
//	change_state(a, a_stk);
}
