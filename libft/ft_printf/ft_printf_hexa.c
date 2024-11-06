/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 06:44:10 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/16 06:44:11 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_size(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}

void	ft_convert_int_to_hex(unsigned int nb, const char c)
{
	if (nb > 15)
	{
		ft_convert_int_to_hex(nb / 16, c);
		ft_convert_int_to_hex(nb % 16, c);
	}
	else
	{
		if (nb < 10)
			ft_putchar((nb + '0'));
		else
		{
			if (c == 'x')
				ft_putchar((nb - 10 + 'a'));
			else if (c == 'X')
				ft_putchar((nb - 10 + 'A'));
		}
	}
}

int	ft_puthexa(unsigned int nbr, char c)
{
	int	len_write;

	len_write = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	else
	{
		ft_convert_int_to_hex(nbr, c);
		len_write += ft_hexa_size(nbr);
	}
	return (len_write);
}
