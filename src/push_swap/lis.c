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


int	binary_search(int *arr, int value, int left, int right)
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

int	*find_lis(t_list *a_list, int size)
{
	int	*result;
	int	dp[size];
	int	idx;
	int	length;

	dp = malloc(sizeof(int) * size);
	result = malloc(sizeof(int) * size);
	result[0] = a_list->content;
	dp[0] = 1;
	length = 1;
	a_list = a_list->next;
	while (a_list)
	{
		if (a_list->content <= result[0])
		{
			result[0] = a_list->content;
			dp[i] = 1;
		}
		else if (arr[i] > result[length - 1])
		{
			result[length++] = a_list->content;
			dp[i] = length;
		}
		else
		{
			idx = binary_search(result, a_list->content, 0, length);
			result[idx] = a_list->content;
			dp[i] = idx + 1;
		}
		a_list = a_list->next;
	}
	while 
	for (int i = n - 1, len = length; i >= 0; i--)
		if (len == dp[i])
			result[--len] = arr[i];
	return (result);
}
