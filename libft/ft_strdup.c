/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:07:36 by nambrako          #+#    #+#             */
/*   Updated: 2025/03/25 15:01:48 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*len_s;
	int		i;

	len_s = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	if (!len_s)
		return (NULL);
	while (s[i])
	{
		len_s[i] = s[i];
		i++;
	}
	len_s[i] = '\0';
	return (len_s);
}
