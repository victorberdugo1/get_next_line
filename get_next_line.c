/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:08:46 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/24 16:02:26 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h> 

int da_line(char **line) {
	char *newline_pos;
	char *remainder;
	newline_pos = ft_strchr(*line, '\n');
	if (newline_pos != NULL) {
		newline_pos++;
		remainder = ft_strdup(newline_pos);
		if (remainder == NULL)
			return -1;
		*(newline_pos - 1) = '\0';
		free(*line);
		*line = remainder;
		return 0;
	}
	return 1;
}

char *get_next_line(int fd) {
	static char *line;
	char *temp;
	ssize_t bytes_read;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return NULL;
	while ((bytes_read = read(fd,line , BUFFER_SIZE)) > 0) {
		//line[bytes_read] = '\0';
		temp = ft_strjoin(line, temp);
		free(line);
		line = temp;
		if (ft_strchr(line, '\n') != NULL)
			break;
	}
	if (bytes_read < 0 || (bytes_read == 0 && line[0] == '\0'))
	{
		free(line);
		line = NULL;
		return NULL;
	}
	line = ft_strdup(temp);
	if (da_line(&line) == -1) {
		free(line);
		return NULL;
	}
	return (line);
}
