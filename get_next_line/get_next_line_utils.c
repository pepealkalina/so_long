/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:54:13 by preina-g          #+#    #+#             */
/*   Updated: 2022/12/17 17:52:13 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_gnl_strchr(const char *s, int c)
{
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
		{
			return (1);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return (0);
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src, int start)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i + start] = src[i];
		i++;
	}
	dest[i + start] = '\0';
	return (dest);
}
