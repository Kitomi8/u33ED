/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:25:07 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/04 09:59:34 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	free_map(char **map)
{
	int i = 0;
	if (!map) return;
	while (map[i])
		free(map[i++]);
	free(map);
}

int close_game(t_data *data)
{
    if (data->screen.img)
        mlx_destroy_image(data->mlx_ptr, data->screen.img);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    free(data->mlx_ptr);
    free_map(data->map);
    exit(0);
}