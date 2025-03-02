/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 05:14:06 by aerenler          #+#    #+#             */
/*   Updated: 2025/01/19 05:26:30 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int n, int *count)
{
	if (n >= 10)
		ft_print_unsigned(n / 10, count);
	ft_print_char((n % 10) + '0', count);
}
