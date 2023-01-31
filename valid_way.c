/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:19:57 by preina-g          #+#    #+#             */
/*   Updated: 2023/01/26 14:42:06 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(t_game_data *game, int x, int y)
{
	if (!(x < 1 || y < 1 || x >= game->width || y > game->heigth
			|| game->dup_map[y][x] == WALL || game->dup_map[y][x] == 'B'))
	{
		game->dup_map[y][x] = 'B';
		ft_flood_fill(game, x, y + 1);
		ft_flood_fill(game, x + 1, y);
		ft_flood_fill(game, x, y - 1);
		ft_flood_fill(game, x - 1, y);
	}
}

int	*ft_start(char **map)
{
	int	x;
	int	y;
	int	*pos;

	pos = (int *)malloc(sizeof(int) * 2);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == INIT)
			{
				pos[0] = x;
				pos[1] = y;
			}
			x++;
		}
		y++;
	}
	return (pos);
}	

int	ft_check_path(t_game_data *game)
{
	int	i;
	int	j;

	game->collect = 0;
	game->exit = 0;
	game->init = 0;
	i = 0;
	while (game->dup_map[i])
	{
		j = 0;
		while (game->dup_map[i][j])
		{
			if (game->dup_map[i][j] == EXIT)
				game->exit++;
			else if (game->dup_map[i][j] == INIT)
				game->init++;
			else if (game->dup_map[i][j] == COLLECT)
				game->collect++;
			j++;
		}
		i++;
	}
	if (game->collect != 0 || game->exit != 0 || game->init != 0)
		return (FALSE);
	return (TRUE);
}

int	ft_path(t_game_data *game, char *file)
{
	int	*pos;

	game->dup_map = ft_read_map(file);
	pos = ft_start(game->dup_map);
	ft_flood_fill(game, pos[0], pos[1]);
	if (ft_check_path(game) == FALSE)
	{
		ft_printf("Error! There is not a valid path\n");
		ft_free(game->dup_map);
		return (FALSE);
	}
	ft_free(game->dup_map);
	free(pos);
	return (TRUE);
}
