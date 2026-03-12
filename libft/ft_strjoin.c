/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:53:18 by nambrako          #+#    #+#             */
/*   Updated: 2025/03/19 09:13:26 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*str;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	str = (char *)malloc((len_s1 + len_s2) + 1);
	len_s1 = 0;
	if (!str)
		return (NULL);
	while (s1[len_s1] != '\0')
	{
		str[len_s1] = s1[len_s1];
		len_s1++;
	}
	len_s2 = 0;
	while (s2[len_s2] != '\0')
	{
		str[len_s1 + len_s2] = s2[len_s2];
		len_s2++;
	}
	str[len_s1 + len_s2] = '\0';
	return (str);
}
