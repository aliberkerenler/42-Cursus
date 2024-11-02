/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:00:54 by aerenler          #+#    #+#             */
/*   Updated: 2024/10/29 15:07:38 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *st, const char *sst, size_t len)
{
	const char	*str;
	const char	*subst;

	if (*sst == '\0')
	{
		return ((char *)st);
	}
	while (*st != '\0' && len > 0)
	{
		str = st;
		subst = sst;
		while (*subst != '\0' && *str == *subst && len > 0)
		{
			str++;
			subst++;
			len--;
		}
		if (*subst == '\0')
		{
			return ((char *)st);
		}
		st++;
		len--;
	}
	return (NULL);
}
