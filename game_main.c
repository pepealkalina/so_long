/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:29:00 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/26 17:31:27 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_data(t_game_data *game, char **map)
{
	int	i;

	game->width = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
		;
	game->heigth = i;
}

int	ft_count_collectables(t_game_data *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == COLLECT)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_set_floor_z(t_game_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			mlx_set_instance_depth(&(*game).img.floor_img->instances[k], 0);
			k++;
			j++;
		}
		i++;
	}
}

void	ft_set_exit_z(t_game_data *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] == EXIT)
		{
			mlx_set_instance_depth(&(*game).img.exit_img->instances[k], 0);
			k++;
			j++;
		}
		i++;
	}
}

int	ft_game_main(t_game_data *game)
{
	t_game_textures	textures;

	game->collect_count = 0;
	game->move_count = 0;
	game->seta_count = 0;
	ft_map_data(game, game->map);
	game->mlx = mlx_init(game->width * 64, game->heigth * 64,
			"preina-g's so_long", false);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->items = ft_count_collectables(game);
	ft_draw_map(game, &textures);
	ft_set_exit_z(game);
	ft_set_floor_z(game);
	mlx_loop_hook(game->mlx, &ft_gameplay, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
