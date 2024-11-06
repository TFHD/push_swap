/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 06:44:25 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/16 06:44:26 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_size(uintptr_t ptr)
{
	int		len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

void	ft_convert_ptr_to_hexa(uintptr_t ptr)
{
	if (ptr > 15)
	{
		ft_convert_ptr_to_hexa(ptr / 16);
		ft_convert_ptr_to_hexa(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar((ptr + '0'));
		else
			ft_putchar((ptr - 10 + 'a'));
	}
}

int	ft_putptr(void *ptr)
{
	int	len_write;

	len_write = 0;
	if (!ptr)
		len_write += ft_putstr(PTRNULL);
	else
	{
		len_write += ft_putstr("0x");
		ft_convert_ptr_to_hexa((uintptr_t)ptr);
		len_write += ft_ptr_size((uintptr_t)ptr);
	}
	return (len_write);
}
