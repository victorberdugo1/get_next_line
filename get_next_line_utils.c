/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:00:21 by vberdugo          #+#    #+#             */
/*   Updated: 2024/07/22 17:06:55 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned long	ft_strlen(const char *s)
{
	unsigned long	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;

	if (s1 == (void *)0 || s2 == (void *)0)
		return ((void *)0);
	i = 0;
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join == (void *)0)
		return ((void *)0);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[i - ft_strlen(s1)])
	{
		join[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	join[i] = 0;
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
