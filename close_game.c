/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:25:07 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/12 17:57:33 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    // mlx_destroy_display(data->mlx_ptr); 
    free(data->mlx_ptr);
    free_map(data->map);
    exit(0);
}