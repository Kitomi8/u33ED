/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:06 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/01/31 12:46:03 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    rotate_player(t_data *data, double angle)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = data->dirX;
    data->dirX = data->dirX * cos(angle) - data->dirY * sin(angle);
	data->dirY = old_dir_x * sin(angle) + data->dirY * cos(angle);
	old_plane_x = data->planeX;
	data->planeX = data->planeX * cos(angle) - data->planeY * sin(angle);
	data->planeY = old_plane_x * sin(angle) + data->planeY * cos(angle);
}