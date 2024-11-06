/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:11:31 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/29 14:15:21 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_tab_cpy(t_stack_copy *cpy, t_stack *stack)
{
	int	i;

	cpy->size = stack->size;
	i = 0;
	while (i < stack->size)
	{
		cpy->content[i] = stack->content[i];
		i++;
	}
	quick_sort(cpy->content, 0, stack->size - 1);
	cpy->mediane = cpy->content[stack->size / 2];
	cpy->min = cpy->content[0];
}

void	back_sort(t_stack *stack_a, t_stack *stack_b, t_stack_copy *cp)
{
	int				i;

	do_bm_calculs(stack_a, stack_b, cp);
	i = 0;
	while (stack_a->content[i] != cp->min)
		i++;
	if (i <= stack_a->size / 2)
	{
		while (i--)
			do_rotate(stack_a);
	}
	else
	{
		i = stack_a->size - i;
		while (i--)
			do_rrotate(stack_a);
	}
}

void	push_mediane(t_stack *a, t_stack *b, int mediane)
{
	int	i;

	i = 0;
	while (a->content[i] != mediane)
		i++;
	if (i <= a->size / 2)
	{
		while (i--)
			do_rotate(a);
	}
	else
	{
		i = a->size - i;
		while (i--)
			do_rrotate(a);
	}
	do_push(a, b);
}

void	pre_sort(t_stack *stack_a, t_stack *stack_b, t_stack_copy *cpy)
{
	while (stack_a->size >= 3)
	{
		if (stack_a->size == 3)
			break ;
		if (!is_max(stack_a->content[0], cpy))
		{
			do_push(stack_a, stack_b);
			if (stack_b->content[0] > cpy->mediane)
				do_rotate(stack_b);
		}
		else
			do_rotate(stack_a);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_copy	*stack_cpy;

	stack_cpy = malloc(sizeof(t_stack_copy));
	if (!stack_cpy)
		error_exit(stack_a, stack_b, stack_cpy, 0);
	stack_cpy->content = malloc((stack_a->size) * sizeof(int));
	if (!(stack_cpy->content))
		error_exit(stack_a, stack_b, stack_cpy, 0);
	init_tab_cpy(stack_cpy, stack_a);
	push_mediane(stack_a, stack_b, stack_cpy->mediane);
	pre_sort(stack_a, stack_b, stack_cpy);
	fast_sort(stack_a);
	back_sort(stack_a, stack_b, stack_cpy);
	free(stack_cpy->content);
	free(stack_cpy);
}
