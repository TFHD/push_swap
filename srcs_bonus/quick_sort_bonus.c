/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:01:33 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 18:01:35 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap_elem(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

int	partition(int *content, int start, int end)
{
	int	pivot;
	int	start_tab;

	start_tab = start;
	pivot = content[start];
	start++;
	while (start <= end)
	{
		while (start <= end && content[start] < pivot)
			start++;
		while (start <= end && content[end] > pivot)
			end--;
		if (start < end)
			swap_elem(content + start, content + end);
	}
	swap_elem(content + start_tab, content + end);
	return (end);
}

void	quick_sort(int	*stack_content, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = partition(stack_content, start, end);
		quick_sort(stack_content, start, pivot - 1);
		quick_sort(stack_content, pivot + 1, end);
	}
}
