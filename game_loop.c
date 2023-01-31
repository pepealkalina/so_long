/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:12:09 by preina-g          #+#    #+#             */
/*   Updated: 2023/01/17 12:27:07 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_delete_collect(t_game_data *game)
{
	int	i;

	i = 0;
	while (i < game->items)
	{
		if ((((*game).img.collect_img->instances[i].y
					== (*game).img.icon_img->instances[0].y)
				&& ((*game).img.collect_img->instances[i].x
					== (*game).img.icon_img->instances[0].x))
			&& (*game).img.collect_img->instances[i].enabled == true)
		{
			(*game).img.collect_img->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	ft_is_collect(t_game_data *game)
{
	if (game->map[(*game).img.icon_img->instances[0].y / 64]
		[(*game).img.icon_img->instances[0].x / 64] == COLLECT)
	{
		ft_delete_collect(game);
		game->map[(*game).img.icon_img->instances[0].y / 64]
		[(*game).img.icon_img->instances[0].x / 64] = VOID;
		game->collect_count++;
	}
	if (game->map[(*game).img.icon_img->instances[0].y / 64]
		[(*game).img.icon_img->instances[0].x / 64] == EXIT)
	{
		if (game->collect_count == game->items)
			mlx_close_window(game->mlx);
	}
}

void	ft_gameplay(void *param)
{
	mlx_t		**mlx;
	t_game_data	*game;

	game = &(*param);
	mlx = &(*game).mlx;
	if (mlx_is_key_down(*mlx, MLX_KEY_ESCAPE))
		mlx_close_window(*mlx);
	if (mlx_is_key_down(*mlx, MLX_KEY_W) || mlx_is_key_down(*mlx, MLX_KEY_UP))
		ft_move_up(game);
	if (mlx_is_key_down(*mlx, MLX_KEY_A) || mlx_is_key_down(*mlx, MLX_KEY_LEFT))
		ft_move_left(game);
	if (mlx_is_key_down(*mlx, MLX_KEY_S) || mlx_is_key_down(*mlx, MLX_KEY_DOWN))
		ft_move_down(game);
	if (mlx_is_key_down(*mlx, MLX_KEY_D)
		|| mlx_is_key_down(*mlx, MLX_KEY_RIGHT))
		ft_move_right(game);
	ft_is_collect(game);
}
