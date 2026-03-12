/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 06:48:18 by nambrako          #+#    #+#             */
/*   Updated: 2026/03/11 16:07:22 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_line(char *line_to_extract)
{
	int		i;
	char	*line;

	if (!line_to_extract || !line_to_extract[0])
		return (NULL);
	i = 0;
	while (line_to_extract[i] && line_to_extract[i] != '\n')
		i++;
	if (line_to_extract[i] == '\n')
		line = ft_calloc(i + 2, 1);
	else
		line = ft_calloc(i + 1, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (line_to_extract[i] && line_to_extract[i] != '\n')
	{
		line[i] = line_to_extract[i];
		i++;
	}
	if (line_to_extract[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*update_line(char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	new_line = ft_calloc(ft_strlen(line) - i, 1);
	if (!new_line)
		return (NULL);
	i++;
	while (line[i])
		new_line[j++] = line[i++];
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line_and_store(fd, line);
	if (!line)
		return (NULL);
	to_return = check_line(line);
	line = update_line(line);
	return (to_return);
}
