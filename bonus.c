/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:56:37 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/28 15:23:26 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
    int fds[argc];
    int num_files;
    int i;
    char *line;
    char *filenames[argc]; 
    int line_numbers[argc];

    if (argc == 1)
    {
        fds[0] = 0;
        filenames[0] = "stdin";
        line_numbers[0] = 1;
        num_files = 1;
    }
    else
    {
        num_files = argc - 1;
        for (i = 0; i < num_files; i++)
        {
            fds[i] = open(argv[i + 1], O_RDONLY);
            if (fds[i] < 0)
            {
                while (i-- > 0)
                    close(fds[i]);
                return (1);
            }
            filenames[i] = argv[i + 1];
            line_numbers[i] = 1;
        }
    }
    i = 0;
    while (num_files > 0)
    {
        line = get_next_line(fds[i]);
        if (line == NULL)
        {
            if (fds[i] != 0)
                close(fds[i]);
            printf(".............End of %s.............\n", filenames[i]);
            for (int j = i; j < num_files - 1; j++)
            {
                fds[j] = fds[j + 1];
                filenames[j] = filenames[j + 1];
                line_numbers[j] = line_numbers[j + 1];
            }
            num_files--;
            if (i >= num_files)
                i = 0;
        }
        else
        {
            printf("[%s] Line %d: %s", filenames[i], line_numbers[i], line);
            free(line);
            line_numbers[i]++;
            i = (i + 1) % num_files;
        }
    }
    return (0);
}

