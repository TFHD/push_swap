/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bm_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:29:43 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/29 20:29:44 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	calc_total_moves(t_best_moves *best_moves)
{
	int	total;

	total = best_moves->ra + best_moves->rb + best_moves->rra + best_moves->rrb
		+ best_moves->rr + best_moves->rrr;
	best_moves->total = total;
	return (total);
}

void	copy_moves(t_best_moves *bm_tmp, t_best_moves *bm)
{
	bm->ra = bm_tmp->ra;
	bm->rb = bm_tmp->rb;
	bm->rra = bm_tmp->rra;
	bm->rrb = bm_tmp->rrb;
	bm->rr = bm_tmp->rr;
	bm->rrr = bm_tmp->rrr;
	bm->total = bm_tmp->total;
}

void	init_best_moves(t_best_moves *bm)
{
	bm->ra = 0;
	bm->rb = 0;
	bm->rra = 0;
	bm->rrb = 0;
	bm->rr = 0;
	bm->rrr = 0;
	bm->total = INT_MAX;
}

void	apply_best_moves(t_stack *stack_a, t_stack *stack_b, t_best_moves *bm)
{
	while (bm->rr--)
		do_rr(stack_a, stack_b);
	while (bm->rrr--)
		do_rrr(stack_a, stack_b);
	while (bm->ra--)
		do_rotate(stack_a);
	while (bm->rb--)
		do_rotate(stack_b);
	while (bm->rrb--)
		do_rrotate(stack_b);
	while (bm->rra--)
		do_rrotate(stack_a);
	do_push(stack_b, stack_a);
}

int	is_max(int nbr, t_stack_copy *cpy)
{
	if (nbr == cpy->content[cpy->size - 1])
		return (1);
	else if (nbr == cpy->content[cpy->size - 2])
		return (1);
	else if (nbr == cpy->content[cpy->size - 3])
		return (1);
	return (0);
}
