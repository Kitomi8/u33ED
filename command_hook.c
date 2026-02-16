/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:20:51 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/16 18:02:46 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	try_move(t_data *data, double moveX, double moveY)
{
    int currentPosY_map;
    int currentPosX_map;
	int nextPosX_map;
    int nextPosY_map;
    double old_x;
	double old_y;
    
    old_x = data->posX;
    old_y = data->posY;
    nextPosX_map = (int)(data->posX + moveX);
    currentPosY_map = (int)(data->posY);
	if (data->map[currentPosY_map][nextPosX_map] != '1')
	{
		data->posX += moveX;
	}
    currentPosX_map = (int)(data->posX);
    nextPosY_map = (int)(data->posY + moveY);

	if (data->map[nextPosY_map][currentPosX_map] != '1')
	{
		data->posY += moveY;
	}
    if (data->posX != old_x || data->posY != old_y)
	{
		printf("[mouvement : Pos( X:%.2f , Y:%.2f ) - Case[%d][%d]\n", 
		data->posX, data->posY, (int)data->posX, (int)data->posY);
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == K_ESC)
		close_game(data);
	if (keycode == K_W)
		try_move(data, data->dirX * MOVE_SPEED, data->dirY * MOVE_SPEED);
	if (keycode == K_S)
		try_move(data, -data->dirX * MOVE_SPEED, -data->dirY * MOVE_SPEED);
	if (keycode == K_D)
		try_move(data, data->planeX * MOVE_SPEED, data->planeY * MOVE_SPEED);
	if (keycode == K_A)
		try_move(data, -data->planeX * MOVE_SPEED, -data->planeY * MOVE_SPEED);
	if (keycode == K_RIGHT)
    {
		rotate_player(data, -ROT_SPEED);
        printf("Rotation Droite : Dir( X:%.2f , Y:%.2f )\n", data->dirX, data->dirY);
    }
	if (keycode == K_LEFT)
    {
		rotate_player(data, ROT_SPEED);
        printf("Rotation Gauche : Dir( X:%.2f , Y:%.2f )\n", data->dirX, data->dirY);
    }
	return (0);
}
