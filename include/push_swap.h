/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:19:25 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/16 16:49:55 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	t_list	*top;
	t_list	*bottom;
	int		max;
	int		min;
}	t_stack;
void	find_index(t_list *a);
int		find_lis(t_list *a_list, int size);
void	push_swap(t_list **a_stack, t_list **b_stack);
void	move_swap(t_list **stack);
void	move_ss(t_list **a_stack, t_list **b_stack);
void	move_push(t_list **to_lst, t_list **fr_lst, t_stack **to, t_stack **fr);
void	move_rotate(t_list **lst, t_stack **stack);
void	move_rr(t_list **a_stack, t_list **b_stack);
void	move_reverse_rotate(t_list **lst, t_stack **stack);
void	move_rrr(t_list **a_stack, t_list **b_stack);
#endif
