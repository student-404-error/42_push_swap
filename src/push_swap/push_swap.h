/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:19:25 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/05 15:44:15 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

void	push_swap(t_list **a, t_list **b);
void	move_swap(t_list **stack);
void	move_ss(t_list **a_stack, t_list **b_stack);
void	move_push(t_list **to_stack, t_list **from_stack);
void	move_rotate(t_list **stack);
void	move_rr(t_list **a_stack, t_list **b_stack);
void	move_reverse_rotate(t_list **stack);
void	move_rrr(t_list **a_stack, t_list **b_stack);
#endif
