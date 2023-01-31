/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:04:36 by preina-g          #+#    #+#             */
/*   Updated: 2022/09/30 17:56:52 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_check_char(set, s1[i]) && s1[i])
		i++;
	while (ft_check_char(set, s1[len - 1]) && (len - 1))
		len--;
	if (len < i)
		len = i;
	newstr = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!newstr)
		return (NULL);
	while (i < len)
		newstr[j++] = s1[i++];
	newstr[j] = '\0';
	return (newstr);
}

/*linea 44: malloc del tamano de la string resultante + 1 parra anadir el \0*/