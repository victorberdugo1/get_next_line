/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:08:46 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/22 12:20:01 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h> 

char	*da_line(char *buffrd)
{
	return (buffrd);
}

char	*get_next_line(int fd)
{
	static char	*line;
	ssize_t		bytes_read;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (line == NULL)
    	return NULL;
	bytes_read = read(fd, line,BUFFER_SIZE);
	if (bytes_read < 0)
		free(line);
	da_line(line);
	return (line);
}
