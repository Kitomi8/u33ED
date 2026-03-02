/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:48:20 by nambrako          #+#    #+#             */
/*   Updated: 2026/03/02 06:39:16 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <fcntl.h>

static int  has_cub_extension(char *filename)
{
    int len;

    len = ft_strlen(filename);
    if (len < 4)
        return (0);
    if (ft_strcmp(filename + len - 4, ".cub") != 0)
        return (0);
    return (1);
}

void    parse_args(int argc, char **argv)
{
    int fd;

    if (argc != 2)
    {
        write(2, "Error\nUsage: ./cub3D map.cub\n", 30);
        exit(EXIT_FAILURE);
    }
    if (!has_cub_extension(argv[1]))
    {
        write(2, "Error\nFile must have .cub extension\n", 37);
        exit(EXIT_FAILURE);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\nCannot open file\n", 23);
        exit(EXIT_FAILURE);
    }
    close(fd);
}

char    *read_file(char *filename)
{
    int     fd;
    int     size;
    char    *buffer;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    buffer = malloc(size + 1);
    if (!buffer)
        return (NULL);
    read(fd, buffer, size);
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}