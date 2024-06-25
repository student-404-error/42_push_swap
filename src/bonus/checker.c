/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:01:37 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/25 14:02:38 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "push_swap_bonus.h"

int	check_sort(t_list *a)
{
	while (a->next)
	{
		if (a->idx > a->next->idx)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_list_free(t_list *a, t_list *b)
{
	t_list	*node;

	while (a)
	{
		node = a;
		a = a->next;
		free(node);
	}
	while (b)
	{
		node = b;
		b = b->next;
		free(node);
	}
}

void	checker_result(t_list *a, t_list *b)
{
	if (check_sort(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_list_free(a, b);
}

void	checker(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!ft_strncmp(line, "sa", 2) || !ft_strncmp(line, "sb", 2) \
			|| !ft_strncmp(line, "ss", 2))
			movement_swap(a, b, line);
		else if (!ft_strncmp(line, "rra", 3) || !ft_strncmp(line, "rrb", 3) \
			|| !ft_strncmp(line, "rrr", 3))
			movement_reverse_rotate(a, b, line);
		else if (!ft_strncmp(line, "ra", 2) || !ft_strncmp(line, "rb", 2) \
			|| !ft_strncmp(line, "rr", 2))
			movement_rotate(a, b, line);
		else if (!ft_strncmp(line, "pa", 2) || !ft_strncmp(line, "pb", 2))
			movement_push(a, b, line);
		else
		{
			ft_printf("Error\n");
			return (free(line), ft_list_free(*a, *b));
		}
		free(line);
		line = get_next_line(0);
	}
	checker_result(*a, *b);
}
