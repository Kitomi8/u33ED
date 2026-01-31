/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:25:07 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/01/31 12:09:42 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int close_game(t_data *data)
{
    // mlx_destroy_image(data->mlx, data->tex_north.img);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    free_map(data->map);
    exit(0);
}