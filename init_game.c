/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:14:42 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/12 15:35:22 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"


void	init_game_data(t_data *data)

============initialise toutes les variables du moteur==========

/*prépare tout pour le raycasting
    data->dirX = 0;
    data->dirY = 1;
    data->planeX = 0.77;
    data->planeY = 0;
    data->posX = 1.1;
    data->posY = 5.5;
    data->floor_color = 0x222222;   // Gris foncé
    data->ceiling_color = 0x444444; // Gris clair
*/


============ouvre le fichier .cub============

/*
    
*/

=============lit le fichier avec get_next_line================
/*

*/

==============stocke la map dynamiquement==================
/*

*/

===================charge les textures=====================

/*

*/


==============init_game===========



//     // Correction des chemins (texture sans 's' et vrais noms de fichiers)
// // Remettez bien "texture" au singulier pour correspondre à votre vrai dossier :
//     char *paths[4] = {
//         "./texture/Texturelabs_Brick_159S.xpm", 
//         "./texture/Texturelabs_Brick_159S (another copy).xpm", 
//         "./texture/Texturelabs_Brick_159S (copy).xpm", 
//         "./texture/Texturelabs_Brick_159S (3rd copy).xpm"
//     };
//     int i = 0;
//     while (i < 4)
//     {
// 	    data->wall_imgs[i].img = mlx_xpm_file_to_image(data->mlx_ptr, paths[i], &data->wall_imgs[i].width, &data->wall_imgs[i].height);
//     	if (!data->wall_imgs[i].img)
// 	    {
// 	    	printf("Error\n: %s\n", paths[i]);
// 		    exit(1);
// 	    }
//         data->wall_imgs[i].addr = mlx_get_data_addr(data->wall_imgs[i].img, &data->wall_imgs[i].bits_per_pixel, &data->wall_imgs[i].line_length, &data->wall_imgs[i].endian);
// 	    i++;
//     }
// }


