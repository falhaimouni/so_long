/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:20:16 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/22 15:08:36 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd)
{
	char	*line;
	int		lines;

	lines = 0;
	while ((line = get_next_line(fd)))
	{
		lines++;
		free(line);
	}
	return (lines);
}

void	remove_newline(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = 0;
	while (line[len] != '\0')
		len++;
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	is_rect(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	elements(char **map)
{
	int	i;
	int	j;
	int	player;
	int	exit;
	int	collect;

	i = 0;
	player = 0;
	exit = 0;
	collect = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	return (player == 1 && exit == 1 && collect > 0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307) 
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == 65361 || keycode == 97)
	{
		printf("move left\n");
		move_player(game, -1, 0);
		
	}
	else if (keycode == 65362 || keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 65363 || keycode == 100)
		move_player(game, 1, 0);
	else if (keycode == 65364 || keycode == 115)
		move_player(game, 0, 1);
	mlx_clear_window(game->mlx, game->win);
	render_map(game, game->textures);
	render_palyer(game, game->textures);
	
	return 0;
}

int main(int argc, char **argv)
{
	char    **map;
	t_game  game;
	t_elem  textures;

	if (argc != 2)
	{
		ft_printf("Wrong arguments\n");
		return (1);
	}
	map = read_map(argv[1]);
	valid_map(map);
	init(&game, map);
	load_textures(&game, &textures);
	game.textures = &textures;
	render_map(&game, &textures);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	free_map(map);
	return (0);
}
