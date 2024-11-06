/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:01:51 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 18:01:53 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->content[1];
		stack->content[1] = stack->content[0];
		stack->content[0] = tmp;
	}
	return (0);
}

int	push(t_stack *stack_src, t_stack *stack_dest)
{
	int	i;

	if (stack_src->size >= 1)
	{
		i = stack_dest->size - 1;
		while (i >= 0)
		{
			stack_dest->content[i + 1] = stack_dest->content[i];
			i--;
		}
		stack_dest->content[0] = stack_src->content[0];
		stack_dest->size += 1;
		i = 0;
		while (i < stack_src->size - 1)
		{
			stack_src->content[i] = stack_src->content[i + 1];
			i++;
		}
		stack_src->content[stack_src->size - 1] = 0;
		stack_src->size -= 1;
	}
	return (0);
}

int	rrotate(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->content[stack->size - 1];
		i = stack->size - 2;
		while (i >= 0)
		{
			stack->content[i + 1] = stack->content[i];
			i--;
		}
		stack->content[0] = tmp;
	}
	return (0);
}

int	rotate(t_stack *stack)
{
	int	i;
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->content[0];
		i = 1;
		while (i < stack->size)
		{
			stack->content[i - 1] = stack->content[i];
			i++;
		}
		stack->content[stack->size - 1] = tmp;
	}
	return (0);
}
