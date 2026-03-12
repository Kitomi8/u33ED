/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:08:34 by nambrako          #+#    #+#             */
/*   Updated: 2025/03/17 15:29:39 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cast_c;
	char	*cast_s;

	i = 0;
	cast_c = (char)c;
	cast_s = (char *)s;
	while (cast_s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (cast_s[i] != cast_c)
		{
			i--;
		}
		else
		{
			return (&(cast_s[i]));
		}
	}
	return (0);
}
