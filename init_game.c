/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:14:42 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/13 18:34:44 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

    i = 0;
	while (s[i])
        i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
        return (NULL);
	i = 0;
	while (s[i])
    {
        dest[i] = s[i];
        i++;
    }
	dest[i] = '\0';
	return (dest);
}

void	init_game_data(t_data *data)
{
    // 1. Direction : vers le NORD (Y negatif)
    data->dirX = 0;
    data->dirY = 1;
    data->planeX = 0.66;
    data->planeY = 0;
    data->posX = 5.5;
    data->posY = 5.5;
    data->floor_color = 0x222222;   // Gris foncé
    data->ceiling_color = 0x444444; // Gris clair


data->map = malloc(sizeof(char *) * 11);
data->map[0]  = ft_strdup("111111111111111111111");
data->map[1]  = ft_strdup("1P0000000100010000001");
data->map[2]  = ft_strdup("101000000100010000001");
data->map[3]  = ft_strdup("100000100100000010001");
data->map[4]  = ft_strdup("100000010111111111111");
data->map[5]  = ft_strdup("100000010111101110111");
data->map[6]  = ft_strdup("100010010111111111111");
data->map[7]  = ft_strdup("100010000111111111111");
data->map[8]  = ft_strdup("100010010000000000001");
data->map[9]  = ft_strdup("111111111111111111111");
data->map[10] = NULL;
}