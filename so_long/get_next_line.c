/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerenler <aerenler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:17:31 by aerenler          #+#    #+#             */
/*   Updated: 2025/04/07 18:17:31 by aerenler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*parse(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	str = malloc(ft_strlen(buffer) - i + 1);
	if (!str)
	{
		free (buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free (buffer);
	return (str);
}

static char	*new_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*next_line(char	*buffer, int fd)
{
	char	*line;
	char	*temp;
	ssize_t	r;

	line = ft_calloc(1, BUFFER_SIZE + 1);
	r = 1;
	while (!ft_strchr(line, '\n') && r > 0)
	{
		r = read(fd, line, BUFFER_SIZE);
		if (r == -1 || (r == 0 && (!buffer || *buffer == '\0')))
		{
			free (line);
			free (buffer);
			return (NULL);
		}
		line[r] = '\0';
		temp = ft_strjoin(buffer, line);
		free (buffer);
		buffer = temp;
	}
	free (line);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = next_line(buffer, fd);
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	line = new_line(buffer);
	buffer = parse(buffer);
	return (line);
}
