/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.32.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:38:37 by seong-ki          #+#    #+#             */
/*   Updated: 2023/06/22 19:59:23 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

void	movement_swap(t_list **a, t_list **b, char *option)
{
	if (ft_strncmp(option, "sa", 2))
		swap(a);
	else if (ft_strncmp(option, "sb", 2))
		swap(b);
	else
		ss(a, b);
}

void	movement_rotate(t_list **a, t_list **b, char *option)
{
	if (ft_strncmp(option, "ra", 2))
		rotate(a);
	else if (ft_strncmp(option, "rb", 2))
		rotate(b);
	else
		rr(a, b);
}

void	movement_reverse_rotate(t_list **a, t_list **b, char *option)
{
	if (ft_strncmp(option, "rra", 3))
		reverse_rotate(a);
	else if (ft_strncmp(option, "rrb", 3))
		reverse_rotate(b);
	else
		rrr(a, b);
}
void	movement_push(t_list **a, t_list **b, char *option)
{
	if (ft_strncmp(option, "pa", 2))
		push(a, b);
	else if (ft_strncmp(option, "pb", 2))
		push(b, a);
}
