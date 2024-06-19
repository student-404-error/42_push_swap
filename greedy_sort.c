/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:46:23 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/19 14:58:19 by seong-ki         ###   ########.fr       */
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
			move_reverse_rotate(a, a_stk, "rra");
	}
	else
	{
		while ((*a_stk)->top->content != (*a_stk)->min)
			move_rotate(a, a_stk, "ra");
	}
}

void	set_between_min_max(t_list **a, t_stack **a_stk, t_list *b)
{
	t_list	*ptr;
	t_list	*last;
	int		cnt;
	
	while (b)
	{
		cnt = 0;
		ptr = *a;
		last = ft_lstlast(*a);
		while (ptr->content < b->idx || last->content > b->idx)
		{
			cnt++;
			last = ptr;
			ptr = ptr->next;

		}
		if (cnt > (ft_lstsize(*a) / 2))
			b->move[0] = cnt - ft_lstsize(*a);
		else
			b->move[0] = cnt;
	}
	/*
	if (cnt > (ft_lstsize(*a) / 2))
	{
		while (cnt < (ft_lstsize(*a)))
		{
			move_reverse_rotate(a, a_stk, "rra");
			cnt++;
		}
	}
	else
	{
		while (cnt)
		{
			move_rotate(a, a_stk, "ra");
			cnt--;
		}
	}*/
}

void	sort(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
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
