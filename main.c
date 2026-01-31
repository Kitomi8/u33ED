/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:12:30 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/01/29 20:32:27 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    t_data data;

    if (ac != 2)
    {
        write(2, "Error\nUsage: ./cube3D map.cub\n" ,29);
        return (1);
    }
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1024, 768, "cub3D");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);
    init_game_data(&data, av[1]);
    mlx_hook(data.win_ptr, 2, 1L << 0, handle_keypress, &data); // Touches
    mlx_hook(data.win_ptr, 17, 0, close_game, &data);          // Croix rouge
    mlx_loop_hook(data.mlx_ptr, render_frame, &data);
    mlx_loop(data.mlx_ptr);

    return (0);
}