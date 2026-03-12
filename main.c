/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:12:30 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/12 14:09:27 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));

	/* 1. Parser les arguments et charger la map */
	parse_args(ac, av);

	/* 2. Initialiser MLX */
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);

	/* 3. Créer la fenêtre */
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1024, 768, "Cub3D");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);

	/* 4. Créer l'image écran */
	data.screen.img = mlx_new_image(data.mlx_ptr, 1024, 768);
	if (!data.screen.img)
		return (close_game(&data), 1);

	data.screen.addr = mlx_get_data_addr(
		data.screen.img,
		&data.screen.bits_per_pixel,
		&data.screen.line_length,
		&data.screen.endian);

	/* 5. Initialiser les données du jeu */
	init_game_data(&data);

	/* 6. Hooks */
	mlx_hook(data.win_ptr, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, close_game, &data);

	/* 7. Boucle principale */
	mlx_loop_hook(data.mlx_ptr, render_frame, &data);
	mlx_loop(data.mlx_ptr);

	return (0);
}