/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:14:00 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/15 16:15:00 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	binary_search(int *arr, int value, int left, int right)
{
	int	mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (value <= arr[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return (right);
}

static void	update_result_and_lis(int *result, t_list *a_list, int *length)
{
	int	idx;

	if (a_list->content <= result[0])
	{
		result[0] = a_list->content;
		a_list->lis = 1;
	}
	else if (a_list->content > result[*length - 1])
	{
		result[(*length)++] = a_list->content;
		a_list->lis = *length;
	}
	else
	{
		idx = binary_search(result, a_list->content, 0, *length);
		result[idx] = a_list->content;
		a_list->lis = idx + 1;
	}
}

static int	*initialize_result(int size, t_list *a_list, int *length)
{
	int	*result;

	result = malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	result[0] = a_list->content;
	a_list->lis = 1;
	*length = 1;
	a_list = a_list->next;
	return (result);
}

int	find_lis(t_list *a_list, int size)
{
	int	length;
	int	*result;

	result = initialize_result(size, a_list, &length);
	if (!result)
		return (-1);
	while (a_list)
	{
		update_result_and_lis(result, a_list, &length);
		a_list = a_list->next;
	}
	free(result);
	return (length);
}
