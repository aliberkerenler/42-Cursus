/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:00:43 by aerenler          #+#    #+#             */
/*   Updated: 2025/01/22 15:15:28 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
void	ft_print_char(char c, int *count);
void	ft_print_string(char *str, int *count);
void	ft_print_pointer(void *ptr, int *count);
void	ft_print_decimal(int n, int *count);
void	ft_print_integer(int n, int *count);
void	ft_print_unsigned(unsigned int n, int *count);
void	ft_print_hex(unsigned long long n, int uppercase, int *count);
void	ft_print_percent(int *count);

#endif