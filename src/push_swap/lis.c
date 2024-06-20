/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:28:43 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/20 17:14:14 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

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

void	passing_to_b(t_list *a, t_list *b)
{
	t_stack	*a_stk;
	t_stack	*b_stk;

	a_stk = ft_new_stack(a);
	b_stk = ft_new_stack(b);
	push_b(&a, &b, &a_stk, &b_stk);
	sort(&a, &b, &a_stk, &b_stk);
}
