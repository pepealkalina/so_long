/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:48:58 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/06 11:59:20 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_numlen(int i)
{
	int	j;

	j = 0;
	if (i == -2147483648)
		return (11);
	if (i == 0)
		return (1);
	else if (i < 0)
	{
		j++;
		i = i * -1;
	}
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

static char	*ft_writenum(int n, int i, char *numstr, int len)
{
	if (n == -2147483648)
	{
		numstr[len - 1] = '8';
		n = -214748364;
		i = 10;
	}
	if (n < 0)
	{
		numstr[0] = '-';
		n = -n;
	}
	while (i > 0)
	{
		numstr[i - 1] = (n % 10) + '0';
		n = n / 10;
		if (n == 0)
		{
			numstr[len] = '\0';
			return (numstr);
		}
		i--;
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*numstr;
	int		i;
	int		len;

	len = ft_numlen(n);
	numstr = (char *)malloc(sizeof(char) * ft_numlen(n) + 1);
	if (!numstr)
		return (0);
	i = ft_numlen(n);
	return (ft_writenum(n, i, numstr, len));
}
