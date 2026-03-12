/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:48:20 by nambrako          #+#    #+#             */
/*   Updated: 2026/03/12 14:18:54 by nambrako         ###   ########.fr       */
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

void	parse_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);  // pour tester
		free(line);
		line = get_next_line(fd);
	}
}

void	parse_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error_exit("Usage: ./cub3D map.cub");

	if (!has_cub_extension(argv[1]))
		error_exit("File must have .cub extension");

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open file");

	parse_file(fd);
	close(fd);
}