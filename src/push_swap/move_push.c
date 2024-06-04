/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:01:30 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/04 20:15:19 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	move_pa(t_list **a, t_list **b)
{
	t_list	*node;
	t_list	*tmp;

	if (*b == NULL)
		return ;
	node = ft_lstnew((*b)->content);
	tmp = *b;
	*b = (*b)->next;
	free(tmp);
	ft_lstadd_front(a, node);
}

void	move_pb(t_list **b, t_list **a)
{
	t_list	*node;
	t_list	*tmp;

	if (*a == NULL)
		return ;
	node = ft_lstnew((*a)->content);
	tmp = *a;
	*a = (*a)->next;
	free(tmp);
	ft_lstadd_front(b, node);
}
