/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:20:51 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/01/31 16:05:36 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == K_ESC)
        close_game(data);
    if (keycode == K_W)
    {
        data->posX += data->dirX * MOVE_SPEED;
        data->posY += data->dirY * MOVE_SPEED;
    }
    if (keycode == K_S)
    {
        data->posX -= data->dirX * MOVE_SPEED;
        data->posY -= data->dirY * MOVE_SPEED;
    }
    if (keycode == K_D)
    {
        data->posX += data->planeX * MOVE_SPEED;
        data->posY += data->planeY * MOVE_SPEED;
    }
    if (keycode == K_A)
    {
        data->posX -= data->planeX * MOVE_SPEED;
        data->posY -= data->planeY * MOVE_SPEED;
    }
    if (keycode == K_RIGHT)
        rotate_player(data, -ROT_SPEED); // Rotation horaire
    if (keycode == K_LEFT)
        rotate_player(data, ROT_SPEED);  // Rotation anti-horaire

    return (0);
}