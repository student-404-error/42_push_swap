/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:30:58 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/03 17:22:21 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	check_sort(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	last_sort(t_list **a, t_stack **a_stk)
{
	int		cnt;
	int		size;
	t_list	*ptr;

	size = ft_lstsize(*a);
	cnt = 0;
	ptr = *a;
	while (ptr->idx > (*a_stk)->min)
	{
		ptr = ptr->next;
		cnt++;
	}
	if (cnt > (size / 2))
	{
		while (cnt < size)
		{
			move_reverse_rotate(a, a_stk, "rra");
			cnt++;
		}
	}
	else
	{
		while (cnt--)
			move_rotate(a, a_stk, "ra");
	}
}
