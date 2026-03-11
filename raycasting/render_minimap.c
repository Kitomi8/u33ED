/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:41:27 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/11 17:14:37 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



static void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || y < 0 || x >= 1024 || y >= 768)
        return;
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

static void draw_square(t_data *data, int x, int y, int size, int color)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            my_mlx_pixel_put(&data->screen, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

void render_minimap(t_data *data)
{
    int x;
    int y;

    y = 0;
    while(data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '1')
            {
                draw_square(data, x * SIZE, y * SIZE, SIZE, 0x000000);
            }
            else if (data->map[y][x] == '0')
            {
                draw_square(data, x * SIZE, y * SIZE, SIZE, 0x555555);
            }
            x++;
        }
        y++;
        int player_px = (int)(data->posX * SIZE);
        int player_py = (int)(data->posY * SIZE);
        draw_square(data, player_px - 2, player_py - 2, 5, 0xFF0000);
    }
}