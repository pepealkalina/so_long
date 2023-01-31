/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:01:36 by preina-g          #+#    #+#             */
/*   Updated: 2022/09/22 10:51:12 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argument)
{
	if ((argument >= 'a' && argument <= 'z')
		|| (argument >= 'A' && argument <= 'Z')
		|| (argument >= '0' && argument <= '9'))
		return (1);
	else
		return (0);
}
