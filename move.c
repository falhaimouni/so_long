/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:59:57 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/22 15:17:35 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game, t_elem *textures)
{
	char	tile;
	void	*img;
	int		x;
	int		y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			if (tile == '1')
				img = textures->wall;
			else if (tile == '0')
				img = textures->floor;
			else if (tile == 'E')
				img = textures->exit;
			else if (tile == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				game->map[y][x] = '0';
				img = textures->floor;
			}
			else if (tile == 'C')
				img = textures->collect;
			mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	render_palyer(t_game *game, t_elem *textures)
{
	void	*img;
	
	img = textures->player;
	mlx_put_image_to_window(game->mlx, game->win, img, game->player_x * 32, game->player_y * 32);

}

void	find_player_position(char **map, t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			x = 0;
			if (map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E'
		&& game->collected == game->total_collectibles)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	game->player_x = new_x;
	game->player_y = new_y;
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// int	count_collectibles(char **map)
// {
// 	int	i;
// 	int	j;
// 	int	total;

// 	i = 0;
// 	total = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'C')
// 				total++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (total);
// }
