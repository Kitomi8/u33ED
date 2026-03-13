/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:50:42 by nambrako          #+#    #+#             */
/*   Updated: 2026/03/13 20:08:57 by nambrako         ###   ########.fr       */
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

	/* MAP */
	char	**map;
	int		map_width;
	int		map_height;

	/* PLAYER */
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

	/* TEXTURES PATH (from .cub) */
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;

	/* IMAGES */
	t_img	screen;
	t_img	wall_imgs[4]; // 0:Nord, 1:Sud, 2:Est, 3:Ouest

	/* COLORS */
	int		floor_color;
	int		ceiling_color;

}	t_data;

#endif
