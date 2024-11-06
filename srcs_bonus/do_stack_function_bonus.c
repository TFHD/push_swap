/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_stack_function_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:00:20 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 18:00:22 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	do_push(t_stack *stack_src, t_stack *stack_dest)
{
	push(stack_src, stack_dest);
	ft_printf("p%c\n", stack_dest->name);
}

void	do_swap(t_stack *stack)
{
	swap(stack);
	ft_printf("s%c\n", stack->name);
}

void	do_rotate(t_stack *stack)
{
	rotate(stack);
	ft_printf("r%c\n", stack->name);
}

void	do_rrotate(t_stack *stack)
{
	rrotate(stack);
	ft_printf("rr%c\n", stack->name);
}
