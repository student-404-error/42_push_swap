/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:01:37 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/22 19:52:55 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "push_swap_bonus.h"

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit();
}
void	checker(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(1);
	if (line == "sa\n" || line == "sb\n" || line == "ss\n")
		movement_swap(a);
	else if (line == "ra\n" || line == "rb\n", || line == "rr\n")
		movement_rotate(b);
	else if (line == "rra\n" || line == "rrb\n" || line == "rrr\n")
		movement_reverse_rotate(a, b);
	else if (line == "pa\n" || line == "pb\n")
		movement_push(a, b);
	else
		ft_error("Error");
}
