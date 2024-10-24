/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:52:18 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/24 14:02:48 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size >= 2)
	{
		tmp = stack->content[1];
		stack->content[1] = stack->content[0];
		stack->content[0] = tmp;
		printf("s%c\n", stack->name);
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
		stack_src->size -= 1;
		printf("p%c\n", stack_dest->name);
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
		printf("rr%c\n", stack->name);
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
		printf("r%c\n", stack->name);
	}
	return (0);
}
