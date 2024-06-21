/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:28:43 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/21 22:10:45 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	ft_free(t_stack *a_stk, t_stack *b_stk)
{
	t_list	*node;
	t_list	*tmp;

	node = a_stk->top;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(a_stk);
	free(b_stk);
}

void	push_b(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
	int	size;
	int	lis;

	size = ft_lstsize(*a);
	lis = find_lis(*a, size);
	if (lis == size)
		return ;
	while (ft_lstsize(*b) < size - lis)
	{
		if ((*a)->lis == -1)
		{
			move_rotate(a, a_stk, "ra");
			continue ;
		}
		else
		{
			move_push(b, a, b_stk, a_stk);
			ft_printf("pb\n");
			if ((*b)->idx <= size / 2)
				move_rotate(b, b_stk, "rb");
		}
	}
}

void	passing_to_b(t_list **a, t_list **b)
{
	t_stack	*a_stk;
	t_stack	*b_stk;

	a_stk = ft_new_stack(*a);
	b_stk = ft_new_stack(*b);
	if (check_sort(*a))
		return (ft_free(a_stk, b_stk));
	if (ft_lstsize(*a) == 3)
		three_argu(a, &a_stk);
	else if (ft_lstsize(*a) == 5)
	{
		move_push(b, a, &b_stk, &a_stk);
		move_push(b, a, &b_stk, &a_stk);
		ft_printf("pb\npb\n");
		three_argu(a, &a_stk);
	}
	push_b(a, b, &a_stk, &b_stk);
	sort(a, b, &a_stk, &b_stk);
	last_sort(a, &a_stk);
	ft_free(a_stk, b_stk);
}
