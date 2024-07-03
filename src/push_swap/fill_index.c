/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:28:14 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/16 18:33:34 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	find_min_value(t_list *a)
{
	int	min;

	min = 2147483647;
	while (a)
	{
		if (a->idx == 0 && a->content < min)
			min = a->content;
		a = a->next;
	}
	return (min);
}

void	fill_list_index(t_list *a, int idx, int min)
{
	while (a)
	{
		if (a->content == min)
		{
			a->idx = idx;
			break ;
		}
		a = a->next;
	}
}

void	find_index(t_list *a)
{
	int		idx;
	int		min;
	int		size;

	size = ft_lstsize(a);
	idx = 1;
	while (idx <= size)
	{
		min = find_min_value(a);
		fill_list_index(a, idx, min);
		idx++;
	}
}
