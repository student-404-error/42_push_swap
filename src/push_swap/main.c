/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:32 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:16 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_free(t_list *stack)
{
	t_list	*node;

	node = stack;
	while (stack)
	{
		node = stack;
		stack = stack->next;
		free(node);
	}
}

int	main(int ac, char **av)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
	t_list	*node;
	int	i;

	if (ac < 2)
	{
		// prompt back
		ft_printf("Error\n");
		return (1);
	}
	i = 1;
	while (i < ac)
	{

		if (ft_atoi(av[i]) == 0)
		{	// 0을 입력받은 경우를 따로 처리 해줘야함.
			ft_printf("Error 2\n");
			return (1);
		}
		node = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(&a, node);
		i++;
	}
	push_swap(&a, &b);
	ft_free(a);
	ft_free(b);
	return (0);
}
