/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:50:42 by nambrako          #+#    #+#             */
/*   Updated: 2026/02/23 21:07:38 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "cub3d.h"
# include "frame.h"

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

#endif