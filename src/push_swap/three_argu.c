/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_argu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:22:53 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/11 18:58:13 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	three_argu(t_list **a_list)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *a_list;
	second = first->next;
	third = second->next;
	// 1 2 3 > 0
	// 1 3 2 > sa ra
	// 2 1 3 > sa
	// 2 3 1 > rra
	// 3 1 2 > ra
	// 3 2 1 > sa rra
	if (first->content > second->content && second->content > third->content)
	{
	//	move_swap(a_list);
	//	move_reverse_rotate(a_list);
		ft_printf("sa\nrra\n");
	}
	else if (first->content > second->content && second->content < third->content)
	{
	//	move_rotate(a_list);
		ft_printf("ra\n");
	}
	else if (first->content < second->content && third->content < first->content)
	{
	//	move_reverse_rotate(a_list);
		ft_printf("rra\n");
	}
	else if (first->content > second->content && first->content < third->content)
	{
	//	move_swap(a_list);
		ft_printf("sa\n");
	}
	else if (first->content < third->content && second->content > third->content)
	{
	//	move_swap(a_list);
	//	move_rotate(a_list);
		ft_printf("sa\nra\n");
	}
}
