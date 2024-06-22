/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <seong-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:48:47 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/22 19:59:23 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	movement_swap(t_list **a, t_list **b, char *option)
{
	if (option == "sa\n")
		swap(a);
	else if (option == "sb\n")
		swap(b);
	else
		ss(a, b);
}

void	movement_rotate(t_list **a, t_list **b, char *option)
{
	if (option == "ra\n")
		rotate(a);
	else if (option == "rb\n")
		rotate(b);
	else
		rr(a, b);
}

void	movement_reverse_rotate(t_list **a, t_list **b, char *option)
{
	if (option == "rra\n")
		reverse_rotate(a);
	else if (option == "rrb\n")
		reverse_rotate(b);
	else
		rrr(a, b);
}
void	movement_push(t_list **a, t_list **b, char *option)
{
	if (option == "pa\n")
		push(a, b);
	else if (option == "pb\n")
		push(b, a);
}
