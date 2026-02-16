/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:20:18 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/16 18:03:50 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static double	get_delta_dist(double ray_dir)
{
	if (ray_dir == 0)
		return (1e30);
	return (ft_abs(1 / ray_dir));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W || y < 0 || y >= H)
		return ;
	dst = data->screen.addr + (y * data->screen.line_length + x * (data->screen.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//rendu sol sy plafond sy mur ty
void	draw_ver_line(t_data *data, int x, int start, int end, int color)
{
	int	y;

	y = 0;
	// 1. Plafond
	while (y < start)
	{
		my_mlx_pixel_put(data, x, y, data->ceiling_color);
		y++;
	}
	// 2. Mur
	while (y <= end)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
	// 3. Sol
	while (y < H)
	{
		my_mlx_pixel_put(data, x, y, data->floor_color);
		y++;
	}
}

int	render_frame(t_data *data)
{
	int		x;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;

	x = 0;
	while (x < W)
	{
		// 2. Initialisation Rayon
		cameraX = 2 * x / (double)W - 1;
		rayDirX = data->dirX + data->planeX * cameraX;
		rayDirY = data->dirY + data->planeY * cameraX;	
		mapX = (int)data->posX;
		mapY = (int)data->posY;
		deltaDistX = get_delta_dist(rayDirX);
		deltaDistY = get_delta_dist(rayDirY);
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
		}
		// 4. DDA (Raycasting loop)
		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->map[mapX][mapY] > '0')
				hit = 1;
		}

		// 5. Calcul distance et hauteur mur
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		lineHeight = (int)(H / perpWallDist);

		drawStart = -lineHeight / 2 + H / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + H / 2;
		if (drawEnd >= H)
			drawEnd = H - 1;

		// rouge = Nord/Sud, Vert = Est/Ouest
		if (side == 0)
			color = 0xFF0000;
		else
			color = 0x00FF00;
		if (side == 1)
			color = color / 2;
		draw_ver_line(data, x, drawStart, drawEnd, color);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->screen.img, 0, 0);
	return (0);
}