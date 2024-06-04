/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 22:34:09 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/04 22:37:03 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	move_rotate(t_list **stack)
{
	// head to bottom
}

void	move_rr(t_list **a, t_list **b)
{
	move_rotate(a);
	move_rotate(b);
}

void	move_reverse_rotate(t_list **stack)
{
	// bottom to head
}

void	move_rrr(t_list **a, t_list **b)
{
	move_reverse_rotate(a);
	move_reverse_rotate(b);
}
