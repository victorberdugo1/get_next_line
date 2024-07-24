/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:08:46 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/24 21:11:04 by victor           ###   ########.fr       */
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
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
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

static char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(ft_strlen(buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

static char	*readln2(int fd, char *temp_buffer, char **buffer)
{
	char	*tmp;
	int		bytes_read;

	while (!ft_strchr(*buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0)
				return (NULL);
			break ;
		}
		temp_buffer[bytes_read] = '\0';
		tmp = ft_strjoin(*buffer, temp_buffer);
		free(*buffer);
		if (!tmp)
			return (NULL);
		*buffer = tmp;
	}
	return (*buffer);
}

char	*readnl(int fd, char **buffer)
{
	char	*temp_buffer;

	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	if (!readln2(fd, temp_buffer, buffer))
	{
		free(temp_buffer);
		return (NULL);
	}
	free(temp_buffer);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (!buffer)
		buffer = ft_strdup("");
	if (readnl(fd, &buffer) == NULL)
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
	buffer = update_buffer(buffer);
	return (line);
}
