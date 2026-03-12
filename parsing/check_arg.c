/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:48:20 by nambrako          #+#    #+#             */
/*   Updated: 2026/03/12 13:51:44 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	has_cub_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strcmp(filename + len - 4, ".cub") != 0)
		return (0);
	return (1);
}

static void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	parse_file(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		parse_line(line, data);
		free(line);
		line = get_next_line(fd);
	}
}

void	parse_args(int ac, char **av, t_data *data)
{
	int	fd;

	if (ac != 2)
	{
		printf("Error\nUsage: ./cub3D map.cub\n");
		exit(1);
	}
	if (!has_cub_extension(av[1]))
	{
		printf("Error\nMap must have .cub extension\n");
		exit(1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCannot open map file\n");
		exit(1);
	}
	parse_file(fd, data);
	close(fd);
}
