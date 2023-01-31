/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:49:47 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/17 12:45:36 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_rectangle(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (FALSE);
		else
			i++;
	}
	return (i);
}

int	ft_check_wall(char **map)
{
	size_t	i;
	int		j;
	int		height;

	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (i < ft_strlen(map[0]))
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (FALSE);
		else
			i++;
	}
	j = 1;
	while (j < (height - 1))
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[0]) - 1] != '1')
			return (FALSE);
		else
			j++;
	}
	return (TRUE);
}

int	ft_is_tile(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!((map[i][j] == WALL || map[i][j] == VOID)
				|| (map[i][j] == EXIT || map[i][j] == INIT)
				|| (map[i][j] == COLLECT)))
				return (FALSE);
			else
				j++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_have_exit(t_game_data *game)
{
	int	i;
	int	j;

	game->collect = 0;
	game->exit = 0;
	game->init = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == EXIT)
				game->exit++;
			else if (game->map[i][j] == INIT)
				game->init++;
			else if (game->map[i][j] == COLLECT)
				game->collect++;
			j++;
		}
		i++;
	}
	if (game->collect < 1 || game->exit != 1 || game->init != 1)
		return (FALSE);
	return (TRUE);
}
