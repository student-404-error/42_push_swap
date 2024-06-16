/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:56 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/08 04:49:15 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	pr_lst(t_list *lst, char *title)
{
	t_list	*pr;
	int	line;

	pr = lst;
	line = ft_printf("=====%s=====\n", title) - 1;
	while (pr)
	{
		ft_printf("%d\n", pr->content);
		pr = pr->next;
	}
	while (line)
	{
		ft_printf("=");
		line--;
	}
	ft_printf("\n");
}


t_stack	*ft_new_stack(t_list *lst)
{
	t_stack	*stk;
	int	min;
	int	max;

	stk = malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	if (lst == NULL)
	{
		stk->min = INT_MAX;
		stk->max = INT_MIN;
		stk->top = NULL;
		stk->bottom = NULL;
		return (stk);
	}
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

void	status_stack(t_stack *stack, char *title)
{
	ft_printf("=====%s=====\n", title);
	ft_printf("min: %d\n", stack->min);
	ft_printf("max: %d\n", stack->max);
	if (stack->top == NULL)
		ft_printf("top: NULL\n");
	else	
		ft_printf("top: %d\n", stack->top->content);
	if (stack->bottom == NULL)
		ft_printf("bot: NULL\n");
	else
		ft_printf("bot: %d\n", stack->bottom->content);
}

void	change_state(t_list **lst, t_stack **stk)
{
	int	min_node;
	int	cnt;
	t_list	*ptr;

	ptr = *lst;
	min_node = (*stk)->min;
	cnt = 0;
	while (ptr->content > min_node)
	{
		ptr = ptr->next;
		cnt++;
	}
	if (cnt > (ft_lstsize(*lst) / 2))
	{
		while ((*stk)->bottom->content != (*stk)->min)
		{
			move_reverse_rotate(lst, stk);
			ft_printf("rrb\n");
		}
	}
	else
	{
		while ((*stk)->bottom->content != (*stk)->min)
		{
			move_rotate(lst, stk);
			ft_printf("rb\n");
		}
	}

}

void	push_swap(t_list **a, t_list **b)
{
	// stack을 선언 후 max min 먼저 설정,
	t_stack	*a_stack;
	t_stack	*b_stack;

	// initialize
	a_stack = ft_new_stack(*a);
	b_stack = ft_new_stack(*b);
//	pr_lst(*a, "a_list");
	// print status
//	status_stack(a_stack, "a_stack");
//	status_stack(b_stack, "b_stack");
	// commands
	move_push(b, a, &b_stack, &a_stack);
	move_push(b, a, &b_stack, &a_stack);
	ft_printf("pb\n");
	ft_printf("pb\n");
	int count = 0;
	t_list	*ptr;
	ptr = *b;
	int	size_a = ft_lstsize(*a);
//	size_a = 5;
	while (size_a)
	{
		count = 0;
//		ft_printf("%d %d %d\n", b_stack->min, a_stack->top->content, b_stack->max);
		if (a_stack->top->content >= b_stack->min && a_stack->top->content <= b_stack->max)
		{
			if (a_stack->top->content > b_stack->bottom->content)
				change_state(b, &b_stack);
			ptr = *b;
			while (a_stack->top->content < ptr->content)
			{
//				ft_printf("comp-->%d < %d\n", a_stack->top->content, ptr->content);
				count++;
				ptr = ptr->next;
			}
//			ft_printf("====count: %d\n", count);
			if (count > (ft_lstsize(*b) / 2))
			{
				while (count < ft_lstsize(*b))
				{
					move_reverse_rotate(b, &b_stack);
					ft_printf("rrb\n");
//					pr_lst(*b, "rrb b_list");
					count++;
				}
			}
			else
			{
				while (count)
				{
					move_rotate(b, &b_stack);
					ft_printf("rb\n");
//					pr_lst(*b, "rb b_list");
					count--;
				}
			}
			move_push(b, a, &b_stack, &a_stack);
			ft_printf("pb\n");
		}
		else
		{
			change_state(b, &b_stack);
			move_push(b, a, &b_stack, &a_stack);
			move_rotate(b, &b_stack);
			ft_printf("pb\nrb\n");
		}
//		status_stack(a_stack, "a_stack");
//		pr_lst(*b, "push b_list");
		size_a--;
	}
//	pr_lst(*b, "b_list");
//	move_rotate(b, &b_stack);
//	move_rotate(b, &b_stack);
//	pr_lst(*a, "a_list");
//	status_stack(a_stack, "a_stack");
//	status_stack(b_stack, "b_stack");
	change_state(b, &b_stack);
	int	last = ft_lstsize(*b);
	while (last)
	{
		move_push(a, b, &a_stack, &b_stack);
		ft_printf("pa\n");
		last--;
	}
//	pr_lst(*a, "a_list");
// free
	free(a_stack);
	free(b_stack);
	a_stack = NULL;
	b_stack = NULL;

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
	// 	b_top = b_max
	// 	pb
	// if b_min <= a_top <= b_max
	// 	SET b_top < a_top <AND> b_bottom >= a_top
	// 	pb
	// counting numbers bigger than a_top in b_stack.
	// if count_node < a_top
	// 	break;
	// if count > b_stack_size / 2
	// 	rrb
	// else
	// 	rb
}
