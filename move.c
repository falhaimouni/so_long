/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:59:57 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/25 10:26:07 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_tile_image(t_game *game, char tile, int x, int y)
{
	void	*img;

	if (tile == '1')
		img = game->textures->wall;
	else if (tile == '0')
		img = game->textures->floor;
	else if (tile == 'E')
		img = game->textures->exit;
	else if (tile == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->map[y][x] = '0';
		img = game->textures->player;
	}
	else if (tile == 'C')
		img = game->textures->collect;
	else
		img = NULL;
	return (img);
}

void	render_map(t_game *game, t_elem *textures)
{
	char	tile;
	void	*img;
	int		x;
	int		y;

	y = 0;
	(void)textures;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			tile = game->map[y][x];
			img = get_tile_image(game, tile, x, y);
			if (img != NULL)
				mlx_put_image_to_window(game->mlx, game->win, img, x
					* 64, y * 64);
			x++;
		}
		y++;
	}
}

void	render_palyer(t_game *game, t_elem *textures)
{
	void	*img;

	img = textures->player;
	mlx_put_image_to_window(game->mlx, game->win, img, game->player_x
		* 64, game->player_y * 64);
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	total = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	game->collected = count_collectibles(game->map);
	if (new_x < 0 || new_x >= game->width || new_y < 0 || new_y >= game->height)
		return ;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E' && game->collected == game->c)
		free_game(game);
	game->count++;
	ft_printf("Number of movment : %d\n", game->count);
	game->player_x = new_x;
	game->player_y = new_y;
}
