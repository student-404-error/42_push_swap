/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:56 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/20 17:40:54 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

t_stack	*is_lst_null(t_stack *stk)
{
	stk->min = INT_MAX;
	stk->max = INT_MIN;
	stk->top = NULL;
	stk->bottom = NULL;
	return (stk);
}

t_stack	*ft_new_stack(t_list *lst)
{
	t_stack	*stk;
	int		min;
	int		max;

	stk = malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	if (lst == NULL)
		return (is_lst_null(stk));
	min = lst->idx;
	max = lst->idx;
	stk->top = lst;
	while (lst)
	{
		if (lst->idx > max)
			max = lst->idx;
		if (lst->idx < min)
			min = lst->idx;
		if (lst->next == NULL)
			stk->bottom = lst;
		lst = lst->next;
	}
	stk->max = max;
	stk->min = min;
	return (stk);
}
