/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:14:00 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/11 19:57:26 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

typedef struct s_list
{
	int content;
	int lis;
	int idx;
	int move;
	struct s_list *prev;
	struct s_list *next;
} t_list;

int binary_search(int *arr, int value, int left, int right)
{
	int mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (value <= arr[mid])
			right = mid;
		else
			left = mid + 1;
	}
	return right;
}

void update_result_and_lis(int *result, t_list *a_list, int *length)
{
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
		int idx = binary_search(result, a_list->content, 0, *length);
		result[idx] = a_list->content;
		a_list->lis = idx + 1;
	}
}

int *initialize_result(int size, t_list *a_list, int *length)
{
	int *result = malloc(sizeof(int) * size);
	if (!result)
		return NULL; // 메모리 할당 실패 시 NULL 반환 또는 적절한 오류 처리 필요

	result[0] = a_list->content;
	a_list->lis = 1;
	*length = 1;
	a_list = a_list->next;

	return result;
}

int find_lis(t_list *a_list, int size)
{
	int length;
	int *result = initialize_result(size, a_list, &length);

	if (!result)
		return 0; // 메모리 할당 실패 시 0 반환 또는 적절한 오류 처리 필요

	while (a_list)
	{
		update_result_and_lis(result, a_list, &length);
		a_list = a_list->next;
	}
	free(result);
	return length;
}
