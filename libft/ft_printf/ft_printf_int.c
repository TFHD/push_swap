/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 06:44:16 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/16 06:44:18 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_size(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void	ft_int_to_char(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_int_to_char(-nb);
	}
	else
	{
		if (nb >= 10)
		{
			ft_int_to_char(nb / 10);
			ft_putchar(nb % 10 + 48);
		}
		else
			ft_putchar(nb % 10 + 48);
	}
}

int	ft_putint(int nbr)
{
	int	len_write;

	len_write = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	else
	{
		ft_int_to_char(nbr);
		len_write += ft_int_size(nbr);
	}
	return (len_write);
}
