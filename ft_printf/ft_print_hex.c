/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 05:14:23 by aerenler          #+#    #+#             */
/*   Updated: 2025/01/28 15:45:36 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*is_uppercase(int uppercase)
{
	if (uppercase == 1)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

void	ft_print_hex(unsigned long long n, int uppercase, int *count)
{
	char	*base;
	char	buffer[16];
	int		i;

	i = 15;
	base = is_uppercase(uppercase);
	while (i >= 0)
	{
		buffer[i] = base[n % 16];
		n /= 16;
		i--;
	}
	i++;
	while (i < 16 && buffer[i] == '0')
		i++;
	if (i == 16)
		ft_print_decimal(0, count);
	while (i < 16)
	{
		write(1, &buffer[i], 1);
		(*count)++;
		i++;
	}
}
