/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:46:10 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/01/29 11:47:10 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_ray
{
    double posX;      // Position X du joueur
    double posY;      // Position Y du joueur
    double dirX;      // Direction X du joueur
    double dirY;      // Direction Y du joueur
    double planeX;    // Vecteur du plan de caméra (FOV)
    double planeY;    // Vecteur du plan de caméra (FOV)
    double cameraX;   // Coordonnée x dans l'espace de la caméra
    double rayDirX;   // Direction du rayon lancé (X)
    double rayDirY;   // Direction du rayon lancé (Y)
    
    int    mapX;      // Case actuelle de la grille (X)
    int    mapY;      // Case actuelle de la grille (Y)
    double sideDistX; // Distance jusqu'au prochain côté X
    double sideDistY; // Distance jusqu'au prochain côté Y
    double deltaDistX;// Distance entre deux côtés X
    double deltaDistY;// Distance entre deux côtés Y
    double perpWallDist; // Distance projetée du mur
} t_ray;



#endif