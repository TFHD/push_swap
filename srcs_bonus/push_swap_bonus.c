/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:01:23 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 18:01:25 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack *stack)
{
	free(stack->content);
	free(stack);
}

void	error_exit(t_stack *a, t_stack *b, t_stack_copy *cp, t_best_moves *bm)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (cp)
	{
		free(cp->content);
		free(cp);
	}
	if (bm)
		free(bm);
	print_error();
}

t_stack	*init_stack(char name, int size, char **av)
{
	t_stack	*stack;
	int		numbers;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	if (name == 'a')
		numbers = parsing(av, &stack->content);
	else
		stack->content = ft_calloc(size, sizeof(int));
	if (!stack->content)
	{
		free(stack);
		print_error();
		return (0);
	}
	if (name == 'a')
		stack->size = numbers;
	else
		stack->size = 0;
	stack->name = name;
	return (stack);
}
