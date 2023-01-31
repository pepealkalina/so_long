/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:00:34 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/07 19:37:36 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_words_count(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (s[i] == '\0')
		return (0);
	if (s[i] != c)
	{
		i++;
		words++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			words++;
		}
		i++;
	}
	return (words);
}

static size_t	ft_wordlen(const char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

static char	**ft_free(const char **str, size_t i)
{
	while (i < 0)
	{
		i--;
		free((void *)str[i]);
	}
	free (str);
	return (NULL);
}

static char	**ft_make_split(char **str, const char *s, char c, size_t l)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		str[j] = (char *)malloc(sizeof(char) * (ft_wordlen(s, c, i) + 1));
		while (!str[j])
			return (ft_free((const char **)str, j));
		while (s[i] && s[i] != c)
			str[j][k++] = s[i++];
		str[j][k] = '\0';
		j++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**separated_str;

	if (!s)
		return (NULL);
	words = ft_words_count(s, c);
	separated_str = (char **)malloc(sizeof(char *) * (words + 1));
	if (!separated_str)
	{
		free(separated_str);
		return (NULL);
	}
	return (ft_make_split(separated_str, s, c, words));
}
