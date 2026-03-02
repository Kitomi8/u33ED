/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:50:42 by nambrako          #+#    #+#             */
/*   Updated: 2026/03/02 06:48:54 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "cub3d.h"
# include "frame.h"

typedef struct s_ray
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
	double	wallX;
}	t_ray;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	t_img	screen; 
	t_img	wall_imgs[4]; // 0:Nord, 1:Sud, 2:Est, 3:Ouest
	int		floor_color;
	int		ceiling_color;
}	t_data;

#endif