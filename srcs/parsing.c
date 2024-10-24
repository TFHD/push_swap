/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:28:40 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/23 21:40:05 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long long int	ft_atoll(const char *nptr)
{
	long long int	result;
	int				negate;
	int				i;

	result = 0;
	negate = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negate = -negate;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * negate);
}

static int	ft_char_is_int(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (!args[i][j])
			return (0);
		if (args[i][j] == '-')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	check_double(int *tab, int number, int i)
{
	while (i >= 0)
		if (number == tab[i--])
			return (1);
	return (0);
}

static int	*put_in_tab(char **args, int nb_args)
{
	int				i;
	int				*tab;
	long long int	number;

	i = 0;
	tab = malloc((nb_args) * sizeof(int));
	if (!tab)
		return (0);
	while (args[i])
	{
		number = ft_atoll(args[i]);
		if (number > INT_MAX || number < INT_MIN
			|| check_double(tab, number, i - 1))
		{
			free(tab);
			return (0);
		}
		tab[i] = number;
		i++;
	}
	return (tab);
}

int	*parsing(int ac, char **av)
{
	int	*tab;

	if (!ft_char_is_int(av))
		return (0);
	tab = put_in_tab(av, ac);
	if (!tab)
		return (0);
	return (tab);
}
