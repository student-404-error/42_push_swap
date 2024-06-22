/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:59:46 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/22 19:16:38 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = (*lst)->next;
	tmp->prev = NULL;
	(*lst)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *lst;
	tmp->next = *lst;
	(*lst)->prev = tmp;
	*lst = tmp;
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
