/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:00:40 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/28 11:33:48 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# elif BUFFER_SIZE >= 10000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif

char			*get_next_line(int fd);
unsigned long	ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long size);

#endif
