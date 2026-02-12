/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:12:30 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/12 18:30:57 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_data data;

    (void)ac;
    (void)av; 
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1024, 768, "Cub3D");
    data.screen.img = mlx_new_image(data.mlx_ptr, 1024, 768);
    data.screen.addr = mlx_get_data_addr(data.screen.img, &data.screen.bits_per_pixel, &data.screen.line_length, &data.screen.endian);
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);
    init_game_data(&data);
    mlx_hook(data.win_ptr, 2, 1L << 0, handle_keypress, &data);
    mlx_hook(data.win_ptr, 17, 0, close_game, &data);
    mlx_loop_hook(data.mlx_ptr, render_frame, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}