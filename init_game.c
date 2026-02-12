/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:14:42 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/12 18:28:32 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strdup(const char *s)
{
	int		i = 0;
	char	*d;
	while (s[i]) i++;
	d = malloc(i + 1);
	if (!d) return (NULL);
	i = 0;
	while (s[i]) { d[i] = s[i]; i++; }
	d[i] = '\0';
	return (d);
}

void	init_game_data(t_data *data)
{
    // 1. Direction : vers le NORD (Y negatif)
    data->dirX = 0;
    data->dirY = -1;
    data->planeX = 0.66;
    data->planeY = 0;
    data->posX = 5.5;
    data->posY = 5.5;
    data->floor_color = 0x222222;   // Gris foncé
    data->ceiling_color = 0x444444; // Gris clair

    data->map = malloc(sizeof(char *) * 11);
    data->map[0] = ft_strdup("1111111111");
    data->map[1] = ft_strdup("1000000001");
    data->map[2] = ft_strdup("1010000001");
    data->map[3] = ft_strdup("1000000001");
    data->map[4] = ft_strdup("1000000001");
    data->map[5] = ft_strdup("1000000001");
    data->map[6] = ft_strdup("1000000001");
    data->map[7] = ft_strdup("1000000001");
    data->map[8] = ft_strdup("1000000001");
    data->map[9] = ft_strdup("1111111111");
    data->map[10] = NULL;
}