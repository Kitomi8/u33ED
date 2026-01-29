/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:06 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/01/29 15:02:30 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    rotate_player(t_ray *ray, double angle)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = ray->dirX;
    ray->dirX = ray->dirX * cos(angle) - ray->dirY * sin(angle);
    ray->dirY = old_dir_x * sin(angle) + ray->dirY * cos(angle);
    old_plane_x = ray->planeX;
    ray->planeX = ray->planeX * cos(angle) - ray->planeY * sin(angle);
    ray->planeY = old_plane_x * sin(angle) + ray->planeY * cos(angle);
}