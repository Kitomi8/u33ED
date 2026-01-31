/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:10 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/01/29 20:31:16 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>     // Pour cos, sin, abs [cite: 107]
# include <stdlib.h>   // Pour malloc, free, exit [cite: 107]
# include <stdio.h>    // Pour perror [cite: 107]
# include <unistd.h>   // Pour write [cite: 107]
# include <fcntl.h>    // Pour open [cite: 107]
# include "mlx.h"      // Pour toutes les fonctions miniLibX [cite: 107, 109]

# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_ESC 65307

/* --- STRUCTURES --- */

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
    char    **map;           // Tableau 2D pour la carte [cite: 124]
    
    // Position et Direction
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;

    // Couleurs (Format RGB) [cite: 161, 168]
    int     floor_color;
    int     ceiling_color;

    // Textures [cite: 112, 142-157]
    t_img   tex_no;
    t_img   tex_so;
    t_img   tex_we;
    t_img   tex_ea;
}   t_data;

/* --- PROTOTYPES --- */

// Initialisation et Parsing
void    init_game_data(t_data *data, char *map_path);
void    free_map(char **map);

// Moteur de Raycasting
int     render_frame(t_data *data);
void    rotate_player(t_data *data, double angle);

// Événements [cite: 118, 119, 120, 121]
int     handle_keypress(int keycode, t_data *data);
int     close_game(t_data *data);

#endif