/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:14:42 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/03/12 13:55:34 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

static char	*ft_strdup(const char *s)
{
    int		i;
	char	*dest;
    
    i = 0;
	while (s[i])
    i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
    return (NULL);
	i = 0;
	while (s[i])
    {
        dest[i] = s[i];
        i++;
    }
	dest[i] = '\0';
	return (dest);
}

void	init_game_data(t_data *data)
{
    data->dirX = 0;
    data->dirY = 1;
    data->planeX = 0.77;
    data->planeY = 0;
    data->posX = 1.1;
    data->posY = 5.5;
    data->floor_color = 0x222222;   // Gris foncé
    data->ceiling_color = 0x444444; // Gris clair
    // Correction des chemins (texture sans 's' et vrais noms de fichiers)
// Remettez bien "texture" au singulier pour correspondre à votre vrai dossier :
    char *paths[4] = {
        "./texture/Texturelabs_Brick_159S.xpm", 
        "./texture/Texturelabs_Brick_159S (another copy).xpm", 
        "./texture/Texturelabs_Brick_159S (copy).xpm", 
        "./texture/Texturelabs_Brick_159S (3rd copy).xpm"
    };
    
    
    // data->map = malloc(sizeof(char *) * 11);
    // data->map[0]  = ft_strdup("111111111111");
    // data->map[1]  = ft_strdup("100000000001");
    // data->map[2]  = ft_strdup("100010000001");
    // data->map[3]  = ft_strdup("100000010001");
    // data->map[4]  = ft_strdup("100000010111");
    // data->map[5]  = ft_strdup("100000010111");
    // data->map[6]  = ft_strdup("100010010111");
    // data->map[7]  = ft_strdup("100011111111");
    // data->map[8]  = ft_strdup("100000000001");
    // data->map[9]  = ft_strdup("111111111111");
    // data->map[10] = NULL;
    int i = 0;
    while (i < 4)
    {
	    data->wall_imgs[i].img = mlx_xpm_file_to_image(data->mlx_ptr, paths[i], &data->wall_imgs[i].width, &data->wall_imgs[i].height);
    	if (!data->wall_imgs[i].img)
	    {
	    	printf("Error\n: %s\n", paths[i]);
		    exit(1);
	    }
        data->wall_imgs[i].addr = mlx_get_data_addr(data->wall_imgs[i].img, &data->wall_imgs[i].bits_per_pixel, &data->wall_imgs[i].line_length, &data->wall_imgs[i].endian);
	    i++;
    }
}
