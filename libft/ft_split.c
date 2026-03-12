/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nambrako <nambrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 07:41:28 by nambrako          #+#    #+#             */
/*   Updated: 2025/03/19 15:41:12 by nambrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static int	count_letter(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && c != s[i])
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len_word;
	int		len_letter;
	char	**str;

	i = 0;
	len_word = count_word((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (len_word + 1));
	if (!str)
		return (NULL);
	while (i < len_word)
	{
		while (*s == c)
			s++;
		len_letter = count_letter((char *)s, c);
		str[i] = ft_substr(s, 0, len_letter);
		if (!str[i])
			return (NULL);
		s = s + len_letter;
		i++;
	}
	str[i] = NULL;
	return (str);
}
