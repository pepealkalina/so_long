/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:47:12 by preina-g          #+#    #+#             */
/*   Updated: 2022/09/29 17:37:32 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*array;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s);
	array = (char *)malloc(sizeof(char) * (size + 1));
	if (array == NULL)
		return (NULL);
	while (i < size + 1)
	{
		array[i] = s[i];
		i++;
	}
	return (array);
}
