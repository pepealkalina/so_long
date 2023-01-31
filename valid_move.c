/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:58:51 by preina-g          #+#    #+#             */
/*   Updated: 2023/01/17 12:39:40 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_game_data *game)
{
	if (game->map[(*game).img.icon_img->instances[0].y / 64 - 1]
		[(*game).img.icon_img->instances[0].x / 64] != WALL)
	{
		usleep(150000);
		(*game).img.icon_img->instances[0].y -= MOVE;
		(*game).img.icon2_img->instances[0].y -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_down(t_game_data *game)
{		
	if (game->map[(*game).img.icon_img->instances[0].y / 64 + 1]
		[(*game).img.icon_img->instances[0].x / 64] != WALL)
	{
		usleep(150000);
		(*game).img.icon_img->instances[0].y += MOVE;
		(*game).img.icon2_img->instances[0].y += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_left(t_game_data *game)
{
	if (game->map[(*game).img.icon_img->instances[0].y / 64]
		[(*game).img.icon_img->instances[0].x / 64 - 1] != WALL)
	{
		usleep(150000);
		(*game).img.icon2_img->instances[0].enabled = false;
		(*game).img.icon_img->instances[0].enabled = true;
		(*game).img.icon_img->instances[0].x -= MOVE;
		(*game).img.icon2_img->instances[0].x -= MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}

void	ft_move_right(t_game_data *game)
{
	if (game->map[(*game).img.icon_img->instances[0].y / 64]
		[(*game).img.icon_img->instances[0].x / 64 + 1] != WALL)
	{
		usleep(150000);
		(*game).img.icon_img->instances[0].enabled = false;
		(*game).img.icon2_img->instances[0].enabled = true;
		(*game).img.icon_img->instances[0].x += MOVE;
		(*game).img.icon2_img->instances[0].x += MOVE;
		game->move_count++;
		ft_printf("MOVES: %i\n", game->move_count);
	}
}
