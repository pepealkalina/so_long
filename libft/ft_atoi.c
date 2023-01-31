/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:47:33 by preina-g          #+#    #+#             */
/*   Updated: 2022/09/26 16:00:35 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr(const char *str, int i)
{
	int	num;

	num = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	num;

	num = 0;
	nb = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			nb = nb * -1;
			i++;
		}
		else
		i++;
	}
	num = ft_putnbr(str, i);
	return (num * nb);
}
