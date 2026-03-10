/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoky-fa <rtoky-fa@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 12:47:34 by nambrako          #+#    #+#             */
/*   Updated: 2026/03/10 13:32:57 by rtoky-fa         ###   ########.fr       */
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
int		ft_strlen1(char *s);
void	*ft_calloc(size_t n, size_t size);
char	*concatenate_line(char *s1, char *s2);
char	*read_line_and_store(int fd, char *line);
char	*get_next_line(int fd);

#endif
