/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:10 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/06 09:22:44 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>     
# include <stdlib.h>   
# include <stdio.h>    
# include <unistd.h>   
# include <fcntl.h>    
# include "mlx.h"

# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_ESC 65307
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

//     STRUCTURES

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
    char    **map;           // Tableau 2D pour la carte
    // Position et Direction
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    // Couleurs (Format RGB)
    int     floor_color;
    int     ceiling_color;
    // Textures
    t_img   tex_no;
    t_img   tex_so;
    t_img   tex_we;
    t_img   tex_ea;
}   t_data;


#endif