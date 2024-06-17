/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   passing_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:28:43 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/17 17:40:51 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	passing_to_b(t_list *a, t_list *b)
{
	t_stack	*a_stk;
	t_stack	*b_stk;
	int		size;

	a_stk = ft_new_stack(a);
	b_stk = ft_new_stack(b);
	size = ft_lstsize(a);
	int	i = size / 3;
	while (i < size)
	{
		while (a_stk->min <= i)
		{
			status_list_and_stack(a, a_stk, "a");
			if (a->idx <= i)
				move_push(&b, &a, &b_stk, &a_stk);
			else
				move_rotate(&a, &a_stk);
		}
		i += size / 3;
	}
	status_list_and_stack(a, a_stk, "a");
	status_list_and_stack(b, b_stk, "b");
}
