/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:50:32 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/25 14:00:17 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "ft_printf.h"
#include "libft.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_duplication_check(long num, char **av, int i)
{
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

int	check_argument(int i, char **args)
{
	long	n;

	while (args[i])
	{
		if (!ft_isnumber(args[i]))
			return (0);
		n = ft_atoi(args[i]);
		if (!ft_duplication_check(n, args, i + 1))
			return (0);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

void	free_str(char **strs, int ac)
{
	int	i;

	if (ac != 2)
		return ;
	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;
	char	**args;

	a = NULL;
	b = NULL;
	i = 0;
	if (ac < 2)
		return (-1);
	else if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = ++av;
	if (!check_argument(i, args))
	{
		ft_printf("Error\n");
		return (free_str(args, ac), 1);
	}
	while (args[i])
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(args[i++])));
	find_index(a);
	checker(&a, &b);
	return (free_str(args, ac), 0);
}
