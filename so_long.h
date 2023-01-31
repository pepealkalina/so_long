/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:46:37 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/25 13:44:09 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"

# define MOVE 64
# define DELAY 500
//typedef
typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}t_bool;

typedef struct s_game_img
{
	mlx_image_t	*enemy_img;
	mlx_image_t	*enemy2_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*collect2_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*exit2_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*icon_img;
	mlx_image_t	*icon2_img;
}t_game_img;

typedef struct s_player
{
	int	x;
	int	y;
}t_player;

typedef enum e_tiles
{
	VOID = '0',
	WALL = '1',
	COLLECT = 'C',
	EXIT = 'E',
	INIT = 'P',
}t_tiles;

typedef struct s_game_data
{
	int					init;
	int					collect;
	int					exit;
	int					floor;
	char				**map;
	int					heigth;
	int					width;
	int					collect_count;
	int					seta_count;
	int					items;
	int					move_count;
	char				**dup_map;
	mlx_t				*mlx;
	struct s_player		player;
	struct s_game_img	img;
}t_game_data;

typedef struct s_game_textures
{
	mlx_texture_t	*enemy_tx;
	mlx_texture_t	*enemy2_tx;
	mlx_texture_t	*collect_tx;
	mlx_texture_t	*collect2_tx;
	mlx_texture_t	*wall_tx;
	mlx_texture_t	*exit_tx;
	mlx_texture_t	*exit2_tx;
	mlx_texture_t	*floor_tx;
	mlx_texture_t	*icon_tx;
	mlx_texture_t	*icon2_tx;
}t_game_textures;

//functions
char	**ft_read_map(char *file);
int		ft_is_rectangle(char **map);
int		ft_check_wall(char **map);
int		ft_is_tile(char **map);
int		ft_have_exit(t_game_data *game);
int		ft_check_map(char **map, t_game_data *game);
int		ft_game_main(t_game_data *game);
void	ft_draw_map(t_game_data *game, t_game_textures *textures);
void	ft_player_move(mlx_t *mlx, t_game_img *img, t_player *p);
void	ft_init_pos(t_game_data *game);
void	ft_move_up(t_game_data *game);
void	ft_move_down(t_game_data *game);
void	ft_move_right(t_game_data *game);
void	ft_move_left(t_game_data *game);
void	ft_gameplay(void *param);
void	ft_is_collect(t_game_data *game);
void	ft_delete_collect(t_game_data *game);
int		ft_count_collectables(t_game_data *game);
void	ft_map_data(t_game_data *game, char **map);
int		ft_path(t_game_data *game, char *file);
void	ft_free(char **map);
#endif
