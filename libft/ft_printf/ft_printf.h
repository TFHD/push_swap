/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabartho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 06:47:07 by sabartho          #+#    #+#             */
/*   Updated: 2024/10/16 06:47:09 by sabartho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define PTRNULL "(nil)"
# define STRNULL "(null)"

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_ptr_size(uintptr_t ptr);
void	ft_convert_ptr_to_hexa(uintptr_t ptr);
int		ft_putptr(void *ptr);
int		ft_int_size(int nbr);
void	ft_int_to_char(int nb);
int		ft_putint(int nbr);
int		ft_ui_size(unsigned int nbr);
void	ft_ui_to_char(unsigned int nb);
int		ft_putundec(unsigned int nbr);
int		ft_hexa_size(unsigned int nbr);
void	ft_convert_int_to_hex(unsigned int nb, const char c);
int		ft_puthexa(unsigned int nbr, char c);
int		ft_search_format(const char c, va_list params);
int		ft_printf(const char *str, ...);

#endif
