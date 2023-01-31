/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:56:54 by preina-g          #+#    #+#             */
/*   Updated: 2022/09/28 18:15:25 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	if (str1 < str2)
		return (ft_memcpy(str1, str2, n));
	if (!n || str1 == str2)
	{
		return (str1);
	}
	s1 = (unsigned char *)str1;
	s2 = (unsigned const char *)str2;
	while (n--)
	{
		s1[n] = s2[n];
	}
	return (str1);
}
