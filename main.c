/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:20:16 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/29 11:38:58 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] == 'r' && file[len - 2] == 'e'
		&& file[len - 3] == 'b' && file[len - 4] == '.')
		return (1);
	return (0);
}

int	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_wall(char **map)
{
	size_t	len;
	int		i;
	int		last_row_index;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	if (!check_walls(map[0]))
		return (0);
	i = 0;
	while (map[i + 1])
		i++;
	last_row_index = i;
	if (!check_walls(map[last_row_index]))
		return (0);
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_game(game);
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

	if (argc != 2 || !file(argv[1]))
	{
		ft_printf("Error\n");
		return (1);
	}
	map = read_map(argv[1]);
	valid_map(map);
	init(&game, map);
	init_vars(&game);
	load_textures(&game, &textures);
	game.textures = &textures;
	render_map(&game, &textures);
	mlx_hook(game.win, 17, 0, free_game, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
