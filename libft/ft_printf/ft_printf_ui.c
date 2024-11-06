/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 06:44:34 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/16 06:44:35 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ui_size(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

void	ft_ui_to_char(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_ui_to_char(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb % 10 + 48);
}

int	ft_putundec(unsigned int nbr)
{
	int	len_write;

	len_write = 0;
	if (nbr <= 0)
		return (ft_putchar('0'));
	else
	{
		ft_ui_to_char(nbr);
		len_write += ft_ui_size(nbr);
	}
	return (len_write);
}
