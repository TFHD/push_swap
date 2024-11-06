/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 06:43:20 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/19 17:06:53 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_format(const char c, va_list params)
{
	int	len_write;

	len_write = 0;
	if (c == 'c')
		len_write += ft_putchar(va_arg(params, int));
	else if (c == 's')
		len_write += ft_putstr(va_arg(params, char *));
	else if (c == 'p')
		len_write += ft_putptr(va_arg(params, void *));
	else if (c == 'i' || c == 'd')
		len_write += ft_putint(va_arg(params, int));
	else if (c == 'u')
		len_write += ft_putundec(va_arg(params, unsigned long int));
	else if (c == 'x' || c == 'X')
		len_write += ft_puthexa(va_arg(params, unsigned int), c);
	else if (c == '%')
		len_write += ft_putchar('%');
	return (len_write);
}

int	ft_printf(const char *str, ...)
{
	int		len_write;
	int		i;
	va_list	params;

	if (!str)
		return (-1);
	va_start(params, str);
	len_write = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_write += ft_search_format(str[i + 1], params);
			i++;
		}
		else
			len_write += ft_putchar(str[i]);
		i++;
	}
	va_end(params);
	return (len_write);
}
