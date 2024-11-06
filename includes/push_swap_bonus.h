/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:59:04 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 17:59:30 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int			*content;
	char		name;
	int			size;
}				t_stack;

typedef struct s_stack_copy
{
	int			*content;
	int			size;
	int			mediane;
	int			min;
}				t_stack_copy;

typedef struct s_best_moves
{
	int			rrr;
	int			rra;
	int			rrb;
	int			rr;
	int			ra;
	int			rb;
	int			total;
}				t_best_moves;

int		parsing(char **av, int **tab);
void	print_error(void);
int		free_args(char **args);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		*put_in_tab(char **args, int nb_args);
int		ft_char_is_int(char **args);
int		check_double(int *tab, int number, int i);
t_stack	*init_stack(char name, int size, char **av);
void	free_stack(t_stack *stack);

int		swap(t_stack *stack);
int		push(t_stack *stack_src, t_stack *stack_dest);
int		rotate(t_stack *stack);
int		rrotate(t_stack *stack);

void	do_push(t_stack *stack_src, t_stack *stack_dest);
void	do_swap(t_stack *stack);
void	do_rotate(t_stack *stack);
void	do_rrotate(t_stack *stack);
void	do_rr(t_stack *stack_a, t_stack *stack_b);
void	do_rrr(t_stack *stack_a, t_stack *stack_b);
void	do_ss(t_stack *stack, t_stack *stack_b);

int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		is_sorted(t_stack *stack);

void	do_bm_calculs(t_stack *stack_a, t_stack *stack_b, t_stack_copy *cp);
void	apply_best_moves(t_stack *stack_a, t_stack *stack_b, t_best_moves *bm);
void	error_exit(t_stack *a, t_stack *b, t_stack_copy *cp, t_best_moves *bm);
void	init_tab_cpy(t_stack_copy *cpy, t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	swap_elem(int *x, int *y);
void	fast_sort(t_stack *stack);
void	quick_sort(int	*stack_content, int start, int end);
int		partition(int *content, int start, int end);
void	push_mediane(t_stack *a, t_stack *b, int mediane);
int		is_max(int nbr, t_stack_copy *cpy);
void	pre_sort(t_stack *stack_a, t_stack *stack_b, t_stack_copy *cpy);
void	calc_bm(t_stack *a, t_stack *b, t_best_moves *bm, t_stack_copy *cp);
void	copy_moves(t_best_moves *bm_tmp, t_best_moves *bm);
int		calc_total_moves(t_best_moves *best_moves);
void	calc_double_rr(t_best_moves *bm);
void	rotate_or_rrotate_a(t_stack *stack_a, int near_x, t_best_moves *bm);
int		search_near_x(int x, t_stack *stack_a);
void	init_best_moves(t_best_moves *bm);
void	back_sort(t_stack *stack_a, t_stack *stack_b, t_stack_copy *copy);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif
