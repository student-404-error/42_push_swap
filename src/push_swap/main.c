/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:32 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/04 20:34:35 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

int	main(int ac, char **av)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
	t_list	*node;

	if (ac < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	int	i = 1;
	while (i < ac - 2)
	{
		if (ft_atoi(av[i]) == 0)
		{	// 0을 입력받은 경우를 따로 처리 해줘야함.
			ft_printf("Error 2\n");
			return (1);
		}
		node = ft_lstnew(av[i]);
		ft_lstadd_back(&a, node);
		i++;
	}
	while (i < ac)
	{
		if (ft_atoi(av[i]) == 0)
		{
			ft_printf("Error 3\n");
			return (1);
		}
		node = ft_lstnew(av[i]);
		ft_lstadd_back(&b, node);
		i++;
	}
//	ft_printf("%s %s %s\n", (char *)a->content, (char *)a->next->content, (char *) a->next->next->content);
//	ft_printf("%s %s %s\n", av[1], av[2], av[3]);
	push_swap(&a, &b);
	node = a;
	while (node)
	{
		node->content = NULL;
		node = node->next;
	}
	while (a)
	{
		node = a;
		a = a->next;
		free(node);
	}
	ft_printf("%p\n", b);
	while (b)
	{
		node = b;
		b = b->next;
		free(node);
	}
	return (0);
}
