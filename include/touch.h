/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:46:24 by nambrako          #+#    #+#             */
/*   Updated: 2026/02/23 20:11:43 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOUCH_H
# define TOUCH_H
# include "cub3d.h"

# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_ESC 65307

int     handle_keypress(int keycode, t_data *data);
#endif