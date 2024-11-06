/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:00:31 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 18:00:33 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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
