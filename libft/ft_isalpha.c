/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:33:07 by preina-g          #+#    #+#             */
/*   Updated: 2022/09/22 10:51:11 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int	ft_isalpha(int argument)
{
	if ((argument >= 'a' && argument <= 'z')
		|| (argument >= 'A' && argument <= 'Z'))
		return (1);
	else
		return (0);
}
