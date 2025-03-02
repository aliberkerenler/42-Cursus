/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 05:13:29 by aerenler          #+#    #+#             */
/*   Updated: 2025/01/22 15:05:20 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(void *ptr, int *count)
{
	unsigned long long	address;

	address = (unsigned long long)ptr;
	if (address == 0)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*count) += 2;
	ft_print_hex(address, 0, count);
}
