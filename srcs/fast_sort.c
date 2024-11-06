/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:12:43 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/28 16:44:51 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fast_sort(t_stack *stack)
{
	int	max;

	if (is_sorted(stack))
		return ;
	max = get_max(stack);
	if (stack->content[0] == max)
		do_rotate(stack);
	else if (stack->content[1] == max)
		do_rrotate(stack);
	if (stack->content[0] > stack->content[1])
		do_swap(stack);
}
