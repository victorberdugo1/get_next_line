/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:08:46 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/28 13:48:04 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
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

static char	*remainder(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	new_buffer = (char *)malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (free(buffer), NULL);
	while (buffer[i] != '\0')
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	return (free(buffer), new_buffer);
}

static char	*read_new_line(int fd, char **buffer)
{
	char	temp_buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;

	while (!ft_strchr(*buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			return (*buffer);
		temp_buffer[bytes_read] = '\0';
		tmp = ft_strjoin(*buffer, temp_buffer);
		free(*buffer);
		if (!tmp)
			return (NULL);
		*buffer = tmp;
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (!buffer)
		buffer = ft_strdup("");
	if (!read_new_line(fd, &buffer))
		return (NULL);
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = get_line(buffer);
	if (!line)
		return (NULL);
	buffer = remainder(buffer);
	return (line);
}
