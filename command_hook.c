/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:20:51 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/12 18:12:00 by rtoky-fa         ###   ########.fr       */
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
    if (keycode == K_RIGHT)
        rotate_player(data, -ROT_SPEED);
    if (keycode == K_LEFT)
        rotate_player(data, ROT_SPEED);
    return (0);
}