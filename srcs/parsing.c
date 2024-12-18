/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:28:40 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/30 11:20:01 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_real_word(char **av, int i, int j, int numbers)
{
	char	**split_args;

	while (av[i])
	{
		j = 0;
		split_args = ft_split(av[i++], ' ');
		if (!split_args[j])
		{
			free(split_args);
			return (0);
		}
		while (split_args[j])
		{
			free(split_args[j++]);
			numbers++;
		}
		free(split_args);
	}
	return (numbers);
}

char	**parsing_split(char **av, int i, int j, int numbers)
{
	char	**split_args;
	char	**all_nums;

	numbers = count_real_word(av, 0, 0, 0);
	if (!numbers)
		return (0);
	all_nums = malloc(sizeof(char *) * (numbers + 1));
	if (!all_nums)
		return (0);
	numbers = 0;
	while (av[i])
	{
		j = 0;
		split_args = ft_split(av[i++], ' ');
		while (split_args && split_args[j])
		{
			all_nums[numbers] = ft_strjoin(split_args[j], "");
			free(split_args[j]);
			j++;
			numbers++;
		}
		free(split_args);
	}
	all_nums[numbers] = 0;
	return (all_nums);
}

int	parsing(char **av, int **tab)
{
	char	**split_args;
	int		i;
	int		words;

	words = 0;
	i = 0;
	*tab = 0;
	while (av[i])
		words += ft_count_words(av[i++], ' ');
	split_args = parsing_split(av, 0, 0, 0);
	if (!words || !split_args || !ft_char_is_int(split_args))
	{
		free_args(split_args);
		return (0);
	}
	*tab = put_in_tab(split_args, words);
	if (!*tab)
	{
		free_args(split_args);
		return (0);
	}
	free_args(split_args);
	return (words);
}
