/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:14:42 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/13 20:03:43 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

char	**add_line_to_map(char **map, char *line, int *height)
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
	new_map[i] = ft_strdup(line);
	new_map[i + 1] = NULL;
	free(map);
	(*height)++;
	return (new_map);
}

void	load_map(t_data *data, int fd)
{
	char	*line;

	data->map = NULL;
	data->map_height = 0;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
			data->map = add_line_to_map(data->map, line, &data->map_height);
		free(line);
		line = get_next_line(fd);
	}
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (ft_strchr("NSEW", data->map[i][j]))
			{
				data->posX = j + 0.5;
				data->posY = i + 0.5;

				if (data->map[i][j] == 'N')
				{
					data->dirX = 0;
					data->dirY = -1;
				}
				else if (data->map[i][j] == 'S')
				{
					data->dirX = 0;
					data->dirY = 1;
				}
				else if (data->map[i][j] == 'E')
				{
					data->dirX = 1;
					data->dirY = 0;
				}
				else if (data->map[i][j] == 'W')
				{
					data->dirX = -1;
					data->dirY = 0;
				}
				data->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}


void	load_textures(t_data *data)
{
	char *paths[4] = {
		data->no_texture,
		data->so_texture,
		data->we_texture,
		data->ea_texture
	};

	int i = 0;

	while (i < 4)
	{
		data->wall_imgs[i].img = mlx_xpm_file_to_image(
			data->mlx_ptr,
			paths[i],
			&data->wall_imgs[i].width,
			&data->wall_imgs[i].height);

		if (!data->wall_imgs[i].img)
		{
			printf("Error\nTexture load failed: %s\n", paths[i]);
			exit(1);
		}

		data->wall_imgs[i].addr = mlx_get_data_addr(
			data->wall_imgs[i].img,
			&data->wall_imgs[i].bits_per_pixel,
			&data->wall_imgs[i].line_length,
			&data->wall_imgs[i].endian);

		i++;
	}
}

void	init_game_data(t_data *data, char *map_file)
{
	int	fd;

	data->planeX = 0.77;
	data->planeY = 0;
	data->floor_color = 0x222222;
	data->ceiling_color = 0x444444;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open map\n");
		exit(1);
	}

	load_map(data, fd);
	close(fd);

	find_player(data);

	load_textures(data);
}
