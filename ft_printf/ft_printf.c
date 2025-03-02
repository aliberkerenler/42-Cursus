/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:55:48 by aerenler          #+#    #+#             */
/*   Updated: 2025/01/28 15:31:15 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_format(va_list args, const char *format, int *count)
{
	if (*format == 'c')
		ft_print_char(va_arg(args, int), count);
	else if (*format == 's')
		ft_print_string(va_arg(args, char *), count);
	else if (*format == 'p')
		ft_print_pointer(va_arg(args, void *), count);
	else if (*format == 'd' || *format == 'i')
		ft_print_decimal(va_arg(args, int), count);
	else if (*format == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), count);
	else if (*format == 'x')
		ft_print_hex(va_arg(args, unsigned int), 0, count);
	else if (*format == 'X')
		ft_print_hex(va_arg(args, unsigned int), 1, count);
	else if (*format == '%')
		ft_print_percent(count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) != '\0')
			{
				format++;
				parse_format(args, format, &count);
			}
		}
		else
			ft_print_char(*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
