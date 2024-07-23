/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:08:46 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/23 14:23:55 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h> 

int da_line(char **line)
{
    char *newline_pos;
    char *remainder;

    newline_pos = ft_strchr(*line, '\n');
    if (newline_pos != NULL)
    {
        *newline_pos = '\0';
        remainder = ft_strdup(newline_pos + 1);
        if (remainder == NULL)
            return -1;
        free(*line);
        *line = remainder;
        return 0;
    }
    return 1;
}

char	*get_next_line(int fd)
{
	static char	*line;
	char *buffer;
	char *temp;
	ssize_t		bytes_read;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	while ((bytes_read = read(fd, line, BUFFER_SIZE)) > 0)
	{	
		temp = ft_strjoin(buffer, line);
        free(line);
        line = temp;
        if (da_line(&line) == 0)
            break;
	}
	if (bytes_read < BUFFER_SIZE)
	{
		if (bytes_read < 0)
		{
			free(line);
			return (NULL);
		}

	}
	return (line);
}
