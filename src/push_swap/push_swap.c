/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:56 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/05 20:43:41 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

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


t_stack	*ft_new_stack(t_list *lst)
{
	t_stack	*stk;
	int	min;
	int	max;

	stk = malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	min = lst->content;
	max = lst->content;
	stk->top = lst;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		if (lst->content < min)
			min = lst->content;
		if (lst->next == NULL)
			stk->bottom = lst;
		lst = lst->next;
	}
	stk->max = max;
	stk->min = min;
	return (stk);
}

void	push_swap(t_list **a, t_list **b)
{
	// stack을 선언 후 max min 먼저 설정,
	t_stack	*a_stack = NULL;
	//t_stack	*b_stack = NULL;

	a_stack = ft_new_stack(*a);
	ft_printf("%d\n", a_stack->min);
	ft_printf("%d\n", a_stack->max);
	(void) b;
	free(a_stack);
	a_stack = NULL;
	// 경우의 수
	// b가 정렬되어있고,
	// b_max 보다 a의 모든 노드가 크고,
	// a가 내림차순 정렬이 되어있다면,
	// pa만 하면 됨.
	//
	//
	// 전제조건
	// b는 rb, rrb로만 정렬이 가능한 반 정렬 스택이다.
	// b는 오름차순 정렬이 되어있다.
	//
	//
	// a에서 가장 큰 값을 찾는다.
	// a_max가 b의 원소들보다 작다면,	<<<<<
	// 	b_bottom을 b_min으로 설정 후 pb
	// 혹은	b_top을 b_min으로 설정 후 pb
	// a_max가 b의 원소들보다 크다면,	<<<<<
	// 	b_bottom을 b_max로 설정 후 pb
	// 혹은	b_top을 b_max로 설정 후 pb
	// a_max가 b의 원소들 사이에 있다면,	<<<<<
	// 	b_top은 a_node보다 작고, 
	// 	b_bottom은 a_node보다 크게 설정 후 pb
	// rb, rrb Choose Guide when a_node is btw b_min and b_max
	// a_node보다 큰 숫자들을 count함.
	// b_top부터 bottom까지 내려가면서 a_node보다 작은 순간 break ;
	// count가 b의 총 원소 갯수 / 2 보다 크다면 rrb
	// 아니라면 rb
}
