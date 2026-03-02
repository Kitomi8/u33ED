/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:20:18 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/02 07:09:27 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W || y < 0 || y >= H)
		return ;
	dst = data->screen.addr + (y * data->screen.line_length
			+ x * (data->screen.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_frame(t_data *data)
{
	t_ray			ray;
	int				x;
	int				y;
	unsigned int	color;
	char			*dst;

	x = 0;
	while (x < W)
	{
		run_raycasting_math(data, &ray, x);
		if (ray.side == 0)
		{
			ray.texNum = 2; // Est par défaut
			if (ray.rayDirX > 0)
				ray.texNum = 3; // Ouest
			ray.wallX = data->posY + ray.perpWallDist * ray.rayDirY;
		}
		else
		{
			ray.texNum = 0; // Nord par défaut
			if (ray.rayDirY > 0)
				ray.texNum = 1; // Sud
			ray.wallX = data->posX + ray.perpWallDist * ray.rayDirX;
		}
		ray.wallX -= floor(ray.wallX);
		ray.texX = (int)(ray.wallX * (double)data->wall_imgs[ray.texNum].width);
		if ((ray.side == 0 && ray.rayDirX > 0) || (ray.side == 1 && ray.rayDirY < 0))
			ray.texX = data->wall_imgs[ray.texNum].width - ray.texX - 1;
		ray.step = 1.0 * data->wall_imgs[ray.texNum].height / ray.lineHeight;
		ray.texPos = (ray.drawStart - H / 2 + ray.lineHeight / 2) * ray.step;
		y = -1;
		while (++y < ray.drawStart) // Plafond
			my_mlx_pixel_put(data, x, y, data->ceiling_color);
		
		y--;
		while (++y <= ray.drawEnd) // Mur
		{
			ray.texY = (int)ray.texPos & (data->wall_imgs[ray.texNum].height - 1);
			ray.texPos += ray.step;
			dst = data->wall_imgs[ray.texNum].addr + (ray.texY
					* data->wall_imgs[ray.texNum].line_length + ray.texX
					* (data->wall_imgs[ray.texNum].bits_per_pixel / 8));
			color = *(unsigned int *)dst;
			my_mlx_pixel_put(data, x, y, color);
		}
		
		y--;
		while (++y < H) // Sol
			my_mlx_pixel_put(data, x, y, data->floor_color);

		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->screen.img, 0, 0);
	return (0);
}