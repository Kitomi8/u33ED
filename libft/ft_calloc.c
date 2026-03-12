/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:31:57 by nambrako          #+#    #+#             */
/*   Updated: 2025/03/18 12:36:32 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*total_size;

	if (n != 0 && size > (size_t)-1 / n)
		return (0);
	total_size = malloc(n * size);
	if (total_size == 0)
		return (0);
	ft_bzero(total_size, n * size);
	return (total_size);
}
