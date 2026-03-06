/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_uils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:32:19 by nambrako          #+#    #+#             */
/*   Updated: 2025/04/08 07:36:46 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		i++;
	}
	if (s[i] == c)
		return (&(s[i]));
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t	total_size;
	char	*ptr;
	size_t	i;

	total_size = n * size;
	ptr = (char *)malloc(total_size);
	i = 0;
	if (!total_size)
		return (NULL);
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

char	*concatenate_line(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (new_str);
}

char	*read_line_and_store(int fd, char *line)
{
	char	*buf;
	int		nb_read;

	buf = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buf)
		return (NULL);
	nb_read = 1;
	while (nb_read > 0 && !ft_strchr(line, '\n'))
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buf);
			free(line);
			return (NULL);
		}
		buf[nb_read] = '\0';
		line = concatenate_line(line, buf);
	}
	free(buf);
	return (line);
}
