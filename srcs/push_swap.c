/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:41:02 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/24 15:09:18 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
}

t_stack	*init_stack(char name, int size, char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	if (name == 'a')
		stack->content = parsing(size, av);
	else
		stack->content = ft_calloc(size, sizeof(int));
	if (!stack->content)
	{
		free(stack);
		return (0);
	}
	if (name == 'a')
		stack->size = size;
	else
		stack->size = 0;
	stack->name = name;
	return (stack);
}

static void	free_stack(t_stack *stack)
{
	free(stack->content);
	free(stack);
}

void	print_stacks(t_stack *stack_a , t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->size || i < stack_b->size)
	{
		printf("|%d|    |%d|\n", stack_a->content[i], stack_b->content[i]);
		i++;
	}
	printf(" _      _ \n");
	printf("|a|    |b| \n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	//int	i;

	if (ac - 1 <= 0)
		exit(EXIT_FAILURE);
	stack_a = init_stack('a', ac - 1, av + 1);
	if (stack_a)
		stack_b = init_stack('b', ac - 1, av + 1);
	if (!stack_a || !stack_b)
	{
		print_error();
		return (0);
	}
	ft_turk_alorithm(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
