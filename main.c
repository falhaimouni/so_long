/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:20:16 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/18 13:29:21 by falhaimo         ###   ########.fr       */
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
		//line = get_next_line(fd);
		lines++;
		free(line);
	}
	//free(line);
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

char	**read_map(char *file_path)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;
	int		lines;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	lines = count_lines(fd);
	close(fd);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
	{
		perror("Error");
		close(fd);
		exit(1);
	}
	i = 0;
	while ((line = get_next_line(fd)))
	{
		remove_newline(line);
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
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

void	valid_map(char **map)
{
	if (!is_rect(map))
	{
		ft_printf("Error rect\n");
		exit(1);
	}
	if (!elements(map))
	{
		ft_printf("Error elem\n");
		exit(1);
	}
	ft_printf("Valid map\n");
}

void	init(t_game *game, char **map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error init\n");
		exit(1);
	}
	game->map = map;
	game->height = 0;
	while (map[game->height])
		game->height++;
	game->width = ft_strlen(map[0]);
	game->win = mlx_new_window(game->mlx, game->width * 32, game->height * 32, "so_long");
	if (!game->win)
	{
		ft_printf("Error\n");
		exit(1);
	}
	
}
void	load_textures(t_game *game, t_elem *tex)
{
	int	wid;
	int	h;

	tex->wall = mlx_xpm_file_to_image(game->mlx, "tex/wall.xpm", &wid, &h);
	tex->floor = mlx_xpm_file_to_image(game->mlx, "tex/floor.xpm", &wid, &h);
	tex->player = mlx_xpm_file_to_image(game->mlx, "tex/cat.xpm", &wid, &h);
	tex->collect = mlx_xpm_file_to_image(game->mlx, "tex/mouse.xpm", &wid, &h);
	tex->exit = mlx_xpm_file_to_image(game->mlx, "tex/exit.xpm", &wid, &h);
	if (!tex->wall || !tex->floor
		|| !tex->player || !tex->collect || !tex->exit)
	{
		write(2, "Error loading textures\n", 23);
		exit(EXIT_FAILURE);
	}
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


void	render_map(t_game *game, t_elem *textures)
{
	char	tile;
	void	*img;
	int		x;
	int		y;

	if (!game->mlx || !textures->wall)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
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
				img = textures->player;
			else if (tile == 'C')
				img = textures->collect;
			mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
			if (!game->win)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_game	game;
	t_elem	textures;

	if (argc != 2)
	{
		ft_printf("Wrong argumemts\n");
		return (1);
	}
	map = read_map(argv[1]);
	valid_map(map);
	init(&game, map);
	load_textures(&game, &textures);
	render_map(&game, &textures);
	free_map(map);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
