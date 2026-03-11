/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:12:30 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/11 16:22:11 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

#include "include/cub3d.h"

int main(int ac, char **av)
{
    t_data data;

    (void)ac;
    (void)av;
    // parse_args(ac, av);

    /* 1. Initialiser d'abord MLX pour obtenir mlx_ptr */
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (1);

    /* 2. Créer la fenêtre */
    data.win_ptr = mlx_new_window(data.mlx_ptr, 1024, 768, "Cub3D");
    if (!data.win_ptr)
        return (free(data.mlx_ptr), 1);

    /* 3. Créer l'image principale (l'écran) */
    data.screen.img = mlx_new_image(data.mlx_ptr, 1024, 768);
    if (!data.screen.img)
        return (close_game(&data), 1); // close_game doit être capable de gérer l'affichage seulement
    data.screen.addr = mlx_get_data_addr(data.screen.img, &data.screen.bits_per_pixel, &data.screen.line_length, &data.screen.endian);

    /* 4. Initialiser les données du jeu ET charger les textures maintenant que mlx_ptr existe */
    init_game_data(&data);

    /* 5. Configurer les hooks et lancer la boucle */
    mlx_hook(data.win_ptr, 2, 1L << 0, handle_keypress, &data);
    mlx_hook(data.win_ptr, 17, 0, close_game, &data);
    mlx_loop_hook(data.mlx_ptr, render_frame, &data);
    mlx_loop(data.mlx_ptr);

    return (0);
}