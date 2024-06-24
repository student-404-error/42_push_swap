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
	exit(1);
}
void	checker(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(1);
	if (ft_strncmp(line, "sa", 2) || ft_strncmp(line, "sb", 2) || ft_strncmp(line, "ss", 2))
		movement_swap(a, b, line);
	else if (ft_strncmp(line, "ra", 2) || ft_strncmp(line, "rb", 2) || ft_strncmp(line, "rr", 2))
		movement_rotate(a, b, line);
	else if (ft_strncmp(line, "rra", 3) || ft_strncmp(line, "rrb", 3) || ft_strncmp(line, "rrr", 3))
		movement_reverse_rotate(a, b, line);
	else if (ft_strncmp(line, "pa", 2) || ft_strncmp(line, "pb", 2))
		movement_push(a, b, line);
	else
		ft_error("Error");
}
