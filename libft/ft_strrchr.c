/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:50:40 by aerenler          #+#    #+#             */
/*   Updated: 2024/10/20 15:37:57 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			last_occurrence = str;
		}
		str++;
	}
	if ((char)c == '\0')
	{
		return ((char *)str);
	}
	return ((char *)last_occurrence);
}
