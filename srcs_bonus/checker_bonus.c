/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:00:00 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 18:00:03 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	is_valid_instruct(char *instruct)
{
	int	len;

	len = ft_strlen(instruct);
	if (len == 3)
	{
		if (!(ft_strncmp(instruct, "ra\n", 3))
			|| !(ft_strncmp(instruct, "rb\n", 3))
			|| !(ft_strncmp(instruct, "rr\n", 3))
			|| !(ft_strncmp(instruct, "pa\n", 3))
			|| !(ft_strncmp(instruct, "pb\n", 3))
			|| !(ft_strncmp(instruct, "sa\n", 3))
			|| !(ft_strncmp(instruct, "sb\n", 3)))
			return (0);
	}
	if (len == 4)
	{
		if (!(ft_strncmp(instruct, "rrr\n", 4))
			|| !(ft_strncmp(instruct, "rra\n", 4))
			|| !(ft_strncmp(instruct, "rrb\n", 4)))
			return (0);
	}
	return (1);
}

void	do_instruct(char *instruct, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(instruct, "ra", 2) == 0)
		rotate(stack_a);
	else if (ft_strncmp(instruct, "rb", 2) == 0)
		rotate(stack_b);
	else if (ft_strncmp(instruct, "rra", 3) == 0)
		rrotate(stack_a);
	else if (ft_strncmp(instruct, "rrb", 3) == 0)
		rrotate(stack_b);
	else if (ft_strncmp(instruct, "rr", 2) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(instruct, "rrr", 3) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(instruct, "pa", 2) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(instruct, "pb", 2) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(instruct, "sa", 2) == 0)
		swap(stack_a);
	else if (ft_strncmp(instruct, "sb", 2) == 0)
		swap(stack_b);
}

void	parsing_instruct(t_stack *stack_a, t_stack *stack_b)
{
	char	*instruct;

	instruct = get_next_line(0);
	while (instruct)
	{
		if (is_valid_instruct(instruct))
		{
			free(instruct);
			free(get_next_line(0));
			error_exit(stack_a, stack_b, 0, 0);
		}
		do_instruct(instruct, stack_a, stack_b);
		free(instruct);
		instruct = get_next_line(0);
	}
	if (is_sorted(stack_a) && stack_b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac - 1 == 0)
		exit(EXIT_FAILURE);
	stack_a = init_stack('a', ac, av + 1);
	if (stack_a)
		stack_b = init_stack('b', ac, av + 1);
	if (!stack_a || !stack_b)
	{
		print_error();
		return (0);
	}
	parsing_instruct(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
