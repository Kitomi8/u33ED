/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:12:30 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/13 20:04:25 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int main(int ac, char **av)
{
    t_data data;

    if (ac != 2)
        return (printf("Usage: ./cub3D map.cub\n"), 1);

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1024, 768, "Cub3D");

    data.screen.img = mlx_new_image(data.mlx_ptr, 1024, 768);
    data.screen.addr = mlx_get_data_addr(
        data.screen.img,
        &data.screen.bits_per_pixel,
        &data.screen.line_length,
        &data.screen.endian);

    init_game_data(&data, av[1]);

    mlx_loop_hook(data.mlx_ptr, render_frame, &data);
    mlx_loop(data.mlx_ptr);
}
