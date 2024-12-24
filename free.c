/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:08:28 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/24 10:43:43 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_game *game)
{
	if (game->textures->collect)
		mlx_destroy_image(game->mlx, game->textures->collect);
	if (game->textures->player)
		mlx_destroy_image(game->mlx, game->textures->player);
	if (game->textures->wall)
		mlx_destroy_image(game->mlx, game->textures->wall);
	if (game->textures->exit)
		mlx_destroy_image(game->mlx, game->textures->exit);
	if (game->textures->floor)
		mlx_destroy_image(game->mlx, game->textures->floor);
}

void	free_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
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

void	free_game(t_game *game)
{
	free_map(game->map);
	free_img(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
