/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:10 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/23 21:09:32 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* cub3d.h                                                                  */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define INF 1e30

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "parsing.h"
# include "data.h"
# include "frame.h"
# include "touch.h"

void    rotate_player(t_data *data, double angle);
int     render_frame(t_data *data);
void    init_game_data(t_data *data);
int     close_game(t_data *data);
void    free_map(char **map);

#endif