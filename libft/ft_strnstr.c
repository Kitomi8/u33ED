/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:59:20 by nambrako          #+#    #+#             */
/*   Updated: 2025/03/18 10:03:07 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_s;

	len_s = ft_strlen(str);
	i = 0;
	if (!*needle)
		return ((char *)str);
	while (str[i] != '\0' && i < len && i < len_s)
	{
		j = 0;
		while (needle[j] && str[i + j] == needle[j] && i + j < len)
		{
			j++;
		}
		if (!needle[j])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

