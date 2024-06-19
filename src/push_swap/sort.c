/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:46:23 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/19 15:52:05 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	change_state(t_list *a, t_stack *a_stk)
{
	int		cnt;

	cnt = 0;
	while (a->content > a_stk->min)
	{
		a = a->next;
		cnt++;
	}
	if (cnt > (ft_lstsize(a) / 2))
		return (cnt - ft_lstsize(a));
	return (cnt);
}

int	set_minimum_move(t_list *a, t_list *b)
{
	t_list	*ptr;
	t_list	*last;
	int		cnt;
	
	cnt = 1;
	ptr = a;
	last = ft_lstlast(a);
	while (ptr->content < b->idx || last->content > b->idx)
	{
		cnt++;
		last = ptr;
		ptr = ptr->next;

	}
	if (cnt > (ft_lstsize(a) / 2))
		return (cnt - ft_lstsize(a));
	return (cnt);
}

void	sort(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
	t_list	*pt;
	int		b_cnt;

	pt = *b;
	b_cnt = 1;
	while (pt)
	{
		if (pt->idx > (*a_stk)->max || pt->idx < (*a_stk)->min)
		{
			pt->move[0] = change_state(*a, *a_stk);
		}
		else	// 사이에 있다면
		{
			pt->move[0] = set_minimum_move(*a, pt);
		}
		if (b_cnt > (ft_lstsize(*b) / 2))
			pt->move[1] = b_cnt - ft_lstsize(*b);
		else
			pt->move[1] = b_cnt;
		ft_printf("%d %d\n", pt->move[0], pt->move[1]);
		pt = pt->next;
		b_cnt++;
	}
	(void) b_stk;
//	change_state(a, a_stk);
}
