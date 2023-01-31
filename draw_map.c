/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:52:21 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/17 12:38:07 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_textures(t_game_textures *texture)
{
	texture->floor_tx = mlx_load_png("./textures/floor.png");
	texture->wall_tx = mlx_load_png("./textures/wall.png");
	texture->exit_tx = mlx_load_png("./textures/exit.png");
	texture->icon_tx = mlx_load_png("./textures/icon.png");
	texture->icon2_tx = mlx_load_png("./textures/icon2.png");
	texture->collect_tx = mlx_load_png("./textures/collect.png");
}

void	ft_get_img(t_game_textures *texture, t_game_img *img, mlx_t *mlx)
{
	img->floor_img = mlx_texture_to_image(mlx, texture->floor_tx);
	img->wall_img = mlx_texture_to_image(mlx, texture->wall_tx);
	img->exit_img = mlx_texture_to_image(mlx, texture->exit_tx);
	img->icon_img = mlx_texture_to_image(mlx, texture->icon_tx);
	img->icon2_img = mlx_texture_to_image(mlx, texture->icon2_tx);
	img->collect_img = mlx_texture_to_image(mlx, texture->collect_tx);
	mlx_delete_texture(texture->floor_tx);
	mlx_delete_texture(texture->wall_tx);
	mlx_delete_texture(texture->exit_tx);
	mlx_delete_texture(texture->icon_tx);
	mlx_delete_texture(texture->icon2_tx);
	mlx_delete_texture(texture->collect_tx);
}

void	ft_put_images(t_game_data *game, t_game_img *img, int i, int j)
{
	mlx_image_to_window(game->mlx, img->floor_img, j * 64, i * 64);
	if (game->map[i][j] == WALL)
		mlx_image_to_window(game->mlx, img->wall_img, j * 64, i * 64);
	if (game->map[i][j] == INIT)
	{
		mlx_image_to_window(game->mlx, img->icon_img, j * 64, i * 64);
		mlx_image_to_window(game->mlx, img->icon2_img, j * 64, i * 64);
		img->icon_img->instances[0].enabled = false;
	}
	if (game->map[i][j] == EXIT)
		mlx_image_to_window(game->mlx, img->exit_img, j * 64, i * 64);
	if (game->map[i][j] == COLLECT)
		mlx_image_to_window(game->mlx,
			img->collect_img, j * 64, i * 64);
}

void	ft_put_tiles(t_game_data *game, t_game_img *img)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			ft_put_images(game, img, i, j);
			j++;
		}
		i++;
	}
}

void	ft_draw_map(t_game_data *game, t_game_textures *textures)
{
	ft_get_textures(textures);
	ft_get_img(textures, &(*game).img, game->mlx);
	ft_put_tiles(game, &(*game).img);
}
