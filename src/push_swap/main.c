/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:32 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/20 19:34:36 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_input()
{
	
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*node;
	int		i;

	a = NULL;
	b = NULL;
	if (ac < 2)
	{
		// prompt back
		ft_printf("Error\n");
		return (1);
	}
	/* 함수 따로 빼서 만들어야할 듯*/
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
	find_index(a);
	passing_to_b(&a, &b);
	return (0);
}
