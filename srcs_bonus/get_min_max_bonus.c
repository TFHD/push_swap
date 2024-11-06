/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:00:39 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 18:00:53 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	get_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->content[i];
	while (i < stack->size)
	{
		if (stack->content[i] < min)
			min = stack->content[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->content[i];
	while (i < stack->size)
	{
		if (stack->content[i] > max)
			max = stack->content[i];
		i++;
	}
	return (max);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->content[i - 1] > stack->content[i])
			return (0);
		i++;
	}
	return (1);
}
