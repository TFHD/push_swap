/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:21:52 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/24 13:18:52 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct	s_stack
{
	int			*content;
	char		name;
	int			size;
}				t_stack;


int	*parsing(int ac, char **av);
int	swap(t_stack *stack);
int	push(t_stack *stack_src, t_stack *stack_dest);
int	rotate(t_stack *stack);
int	rrotate(t_stack *stack);

#endif
