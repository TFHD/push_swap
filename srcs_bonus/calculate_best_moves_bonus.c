/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_best_moves_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:59:52 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 17:59:54 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	do_bm_calculs(t_stack *stack_a, t_stack *stack_b, t_stack_copy *cp)
{
	t_best_moves	*best_moves;

	best_moves = malloc(sizeof(t_best_moves));
	if (!best_moves)
		error_exit(stack_a, stack_b, cp, 0);
	init_best_moves(best_moves);
	while (stack_b->size)
	{
		calc_bm(stack_a, stack_b, best_moves, cp);
		apply_best_moves(stack_a, stack_b, best_moves);
		best_moves->total = INT_MAX;
	}
	free(best_moves);
}

int	search_near_x(int x, t_stack *stack_a)
{
	int	i;
	int	near_x;

	i = 0;
	near_x = INT_MAX;
	while (i < stack_a->size)
	{
		if (stack_a->content[i] > x && stack_a->content[i] < near_x)
			near_x = stack_a->content[i];
		i++;
	}
	if (near_x == INT_MAX)
	{
		near_x = stack_a->content[0];
		i = 0;
		while (i < stack_a->size)
		{
			if (stack_a->content[i] < near_x)
				near_x = stack_a->content[i];
			i++;
		}
	}
	return (near_x);
}

void	rotate_or_rrotate_a(t_stack *stack_a, int near_x, t_best_moves *bm)
{
	int	i;

	i = 0;
	while (i < stack_a->size && stack_a->content[i] != near_x)
		i++;
	if (i <= stack_a->size / 2)
		bm->ra = i;
	else
		bm->rra = stack_a->size - i;
}

void	calc_double_rr(t_best_moves *bm)
{
	if (bm->ra && bm->rb)
	{
		bm->ra--;
		bm->rb--;
		bm->rr++;
	}
	if (bm->rra && bm->rrb)
	{
		bm->rra--;
		bm->rrb--;
		bm->rrr++;
	}
}

void	calc_bm(t_stack *a, t_stack *b, t_best_moves *bm, t_stack_copy *cp)
{
	t_best_moves	*best_moves_tmp;
	int				i;
	int				near_x;

	best_moves_tmp = malloc(sizeof(t_best_moves));
	if (!best_moves_tmp)
		error_exit(a, b, cp, bm);
	i = 0;
	while (i < b->size)
	{
		init_best_moves(best_moves_tmp);
		if (i <= b->size / 2)
			best_moves_tmp->rb = i;
		else
			best_moves_tmp->rrb = b->size - i;
		near_x = search_near_x(b->content[i], a);
		rotate_or_rrotate_a(a, near_x, best_moves_tmp);
		calc_double_rr(best_moves_tmp);
		if (calc_total_moves(best_moves_tmp) < bm->total)
			copy_moves(best_moves_tmp, bm);
		if (bm->total == 1 || bm->total == 0)
			break ;
		i++;
	}
	free(best_moves_tmp);
}
