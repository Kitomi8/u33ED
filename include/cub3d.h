/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:10 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/02 06:52:35 by rtoky-fa         ###   ########.fr       */
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
void    run_raycasting_math(t_data *data, t_ray *ray, int x);
int	ft_strlen(const char *s);
int	ft_strcmp(const char *s1, const char *s2);

#endif