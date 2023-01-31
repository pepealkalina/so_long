/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:31:57 by preina-g          #+#    #+#             */
/*   Updated: 2022/09/30 14:05:37 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*nstr;
	unsigned int	i;
	unsigned int	a;
	unsigned int	b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (a + b + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	while (a--)
	{
		nstr[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		nstr[a++] = s2[i++];
	nstr[a] = '\0';
	return (nstr);
}
