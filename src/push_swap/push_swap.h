/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:19:25 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/04 20:28:22 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

void	push_swap(t_list **a, t_list **b);
void	move_sa(t_list **a);
void	move_sb(t_list **b);
void	move_ss(t_list **a, t_list **b);
void	move_pa(t_list **a, t_list **b);
void	move_pb(t_list **a, t_list **b);
#endif
