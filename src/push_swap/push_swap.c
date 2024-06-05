/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:56 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/05 15:38:46 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

void	pr_lst(t_list *lst)
{
	t_list	*pr;

	pr = lst;
	while (pr)
	{
		ft_printf("%p\n", pr->content);
		pr = pr->next;
	}
}
void	push_swap(t_list **a, t_list **b)
{
	move_swap(a);
	move_swap(b);
	move_push(a, b);
	move_push(a, b);
	move_push(b, a);
	move_push(b, a);
	move_rotate(a);
}
