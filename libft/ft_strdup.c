/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:35:15 by aerenler          #+#    #+#             */
/*   Updated: 2024/10/20 15:21:26 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	len = 0;
	while (src[i] != '\0')
	{
		i++;
		len++;
	}
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
