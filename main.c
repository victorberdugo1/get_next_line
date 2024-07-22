/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:28:01 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/22 12:44:29 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char **argv) {
    int fd;
    char *line;

    if (argc == 1)
    	fd = 0; 
	else
    {
        fd = open(argv[1], O_RDONLY);
        if (fd < 0)
            return 1;
    }
    line = get_next_line(fd);
	printf("%s", line);
    free(line);
    close(fd);
    return 0;
}
