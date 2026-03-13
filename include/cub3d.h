/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:10 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/13 20:05:35 by nambrako         ###   ########.fr       */
/*                                                                            */
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
# include <fcntl.h>
# include <string.h>

# include "../minilibx-linux/mlx.h"
# include "parsing.h"
# include "data.h"
# include "frame.h"
# include "touch.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

void    rotate_player(t_data *data, double angle);
int     render_frame(t_data *data);
void	init_game_data(t_data *data, char *map_file);
int     close_game(t_data *data);
void    free_map(char **map);
void    run_raycasting_math(t_data *data, t_ray *ray, int x);
void    render_minimap(t_data *data);

#endif
