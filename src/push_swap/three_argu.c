/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_argu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:22:53 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/20 18:08:58 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	three_argu(t_list **a_list, t_stack **a_stk)
{
	t_list	*f;
	t_list	*s;
	t_list	*t;

	f = *a_list;
	s = f->next;
	t = s->next;
	if (f->content > s->content && s->content > t->content)
	{
		move_swap(a_list, a_stk, "sa");
		move_reverse_rotate(a_list, a_stk, "rra");
	}
	else if (f->content > s->content && f->content < t->content)
		move_swap(a_list, a_stk, "sa");
	else if (f->content > s->content && f->content > t->content)
		move_rotate(a_list, a_stk, "ra");
	else if (f->content < s->content && t->content < f->content)
		move_reverse_rotate(a_list, a_stk, "rra");
	else if (f->content < t->content && s->content > t->content)
	{
		move_swap(a_list, a_stk, "sa");
		move_rotate(a_list, a_stk, "ra");
	}
}
