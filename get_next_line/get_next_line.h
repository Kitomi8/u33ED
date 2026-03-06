/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:47:34 by nambrako          #+#    #+#             */
/*   Updated: 2025/04/08 08:41:36 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
void	*ft_calloc(size_t n, size_t size);
char	*concatenate_line(char *s1, char *s2);
char	*read_line_and_store(int fd, char *line);
char	*get_next_line(int fd);

#endif
