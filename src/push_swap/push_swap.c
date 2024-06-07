/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:56 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/07 20:19:00 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	pr_lst(t_list *lst)
{
	t_list	*pr;

	pr = lst;
	ft_printf("================\n");
	while (pr)
	{
		ft_printf("%d\n", pr->content);
		pr = pr->next;
	}
	ft_printf("================\n");
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
	t_stack	*a_stack;
	//t_stack	*b_stack = NULL;

	a_stack = ft_new_stack(*a);
	ft_printf("%d\n", a_stack->min);
	ft_printf("%d\n", a_stack->max);
	ft_printf("%d\n", a_stack->top->content);
	ft_printf("%d\n", a_stack->bottom->content);
	pr_lst(*a);
	int	min_node;
	int	cnt = 0;
	t_list	*ptr;
	ptr = *a;
	min_node = a_stack->min;
	while (ptr->content > min_node)
	{
		ptr = ptr->next;
		cnt++;
	}
	if (cnt > (ft_lstsize(*a) / 2))
	{
		while (a_stack->top->content != a_stack->min)
		{
			move_reverse_rotate(a, &a_stack);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (a_stack->top->content != a_stack->min)
		{
			move_rotate(a, &a_stack);
			ft_printf("ra\n");
		}
	}
	pr_lst(*a);
	(void) b;
	free(a_stack);
	a_stack = NULL;

//	if (a_stack->top->content >
//	while (a_stack->top->content 
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
	// if a_top <= b_min
	// 	b_bottom = b_min
	// 	pb
	// 	<OR>
	// 	b_top = b_min
	// 	pb
	// if a_top >= b_max
	// 	b_bottom = b_max
	// 	pb
	// 	<OR>
	// 	b_top=  b_max
	// 	pb
	// if b_min <= a_top <= b_max
	// 	SET b_top < a_top <AND> b_bottom >= a_top
	// 	pb
	// rb, rrb Choose Guide when a_node is btw b_min and b_max
	// counting numbers bigger than a_top in b_stack.
	// if count_node < a_top
	// 	break;
	// if count > b_stack_size / 2
	// 	rrb
	// else
	// 	rb
}
