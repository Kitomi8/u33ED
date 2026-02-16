/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:10 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/16 18:04:04 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* cub3d.h                                                                  */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_ESC 65307
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define W 1024
# define H 768
# define INF 1e30

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_img;

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    char    **map;
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    t_img   screen; 
    int     floor_color;
    int     ceiling_color;

} t_data;

int     handle_keypress(int keycode, t_data *data);
int     render_frame(t_data *data);
int     close_game(t_data *data);
void    rotate_player(t_data *data, double angle);
void    init_game_data(t_data *data);
void    free_map(char **map);

#endif