/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:28:43 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/18 15:48:23 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	push_b(t_list **a, t_list **b, t_stack **a_stk, t_stack **b_stk)
{
	int	cnt;
	int	size;
	int	range;
	int	max_rotate;
//	int	lis;

	cnt = 3;
	size = ft_lstsize(*a);
//	lis = find_lis(*a, size);
//	if (lis == size)
//		return ;
	range = size / cnt;
	while (cnt)
	{
		max_rotate = 0;
		while (ft_lstsize(*b) < size /*- lis*/)
		{
			if ((*a)->idx <= range/* && (*a)->lis != -1*/)
			{
				move_push(b, a, b_stk, a_stk);
				ft_printf("pb\n");
			}
			else
			{
				move_rotate(a, a_stk);
				ft_printf("ra\n");
			}
			if (size == max_rotate || (*a_stk)->min > range)
				break ;
			max_rotate++;
		}
		range += size / 3 + 1;
		cnt--;
	}
}

void	passing_to_b(t_list *a, t_list *b)
{
	t_stack	*a_stk;
	t_stack	*b_stk;

	a_stk = ft_new_stack(a);
	b_stk = ft_new_stack(b);
	push_b(&a, &b, &a_stk, &b_stk);
}
