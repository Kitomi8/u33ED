/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:33:52 by nambrako          #+#    #+#             */
/*   Updated: 2026/03/06 16:35:33 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	**add_map_line(char **map, char *line, int *height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (*height + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < *height)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = strdup(line);
	new_map[i + 1] = NULL;
	free(map);
	(*height)++;
	return (new_map);
}

void	parse_map(int fd, t_map *map)
{
	char	*line;

	map->grid = NULL;
	map->height = 0;
	map->width = 0;

	while ((line = get_next_line(fd)))
	{
		if (is_map_line(line))
		{
			map->grid = add_map_line(map->grid, line, &map->height);
			if ((int)strlen(line) > map->width)
				map->width = strlen(line);
		}
		free(line);
	}
}
