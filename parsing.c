/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:05:49 by rtoky-fa          #+#    #+#             */
/*   Updated: 2026/02/23 19:25:45 by rtoky-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

int check_arg(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if (strcmp(&str[i], ".cub") == 0)
            return (1);
        i++;
    }
    return (0);
}

// int parse_file(t_data data, )
