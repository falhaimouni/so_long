/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:20:16 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/24 10:44:48 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_map(game->map);
	free_img(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_map(game->map);
		free_img(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(0);
	}
	if (keycode == 65361 || keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 65362 || keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 65363 || keycode == 100)
		move_player(game, 1, 0);
	else if (keycode == 65364 || keycode == 115)
		move_player(game, 0, 1);
	mlx_clear_window(game->mlx, game->win);
	render_map(game, game->textures);
	render_palyer(game, game->textures);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;
	t_elem	textures;

	if (argc != 2)
	{
		ft_printf("Wrong arguments\n");
		return (1);
	}
	map = read_map(argv[1]);
	valid_map(map);
	init(&game, map);
	init_vars(&game);
	load_textures(&game, &textures);
	game.textures = &textures;
	render_map(&game, &textures);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.win);
	mlx_destroy_display(game.mlx);
	return (0);
}
