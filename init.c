/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:23:12 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/24 15:21:56 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_file_lines(char *file_path, int *lines_out)
{
	char	**map;
	int		fd;
	int		lines;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	lines = count_lines(fd);
	close(fd);
	map = malloc((lines + 1) * sizeof(char *));
	if (!map)
	{
		perror("Error");
		exit(1);
	}
	*lines_out = lines;
	return (map);
}

char	**read_map(char *file_path)
{
	char	**map;
	char	*line;
	int		fd;
	int		lines;
	int		i;

	map = read_file_lines(file_path, &lines);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		remove_newline(line);
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	valid_map(char **map)
{
	if (!is_rect(map))
	{
		ft_printf("Error\nMap is not rectangular\n");
		free_map(map);
		exit(1);
	}
	if (!is_wall(map))
	{
		ft_printf("Error\nMap is not surrounded by walls\n");
		free_map(map);
		exit(1);
	}
	if (!elements(map))
	{
		ft_printf("Error\nMissing or incorrect elements\n");
		free_map(map);
		exit(1);
	}
	if (!has_valid_path(map))
	{
		ft_printf("Error\nNo valid path exists\n");
		free_map(map);
		exit(1);
	}
	ft_printf("Valid map\n");
}

void	init(t_game *game, char **map)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error initializing mlx\n");
		exit(1);
	}
	game->map = map;
	game->height = 0;
	while (map[game->height])
		game->height++;
	game->width = ft_strlen(map[0]);
	game->win = mlx_new_window(game->mlx, game->width
			* 64, game->height * 64, "so_long");
	if (!game->win)
	{
		ft_printf("Error creating window\n");
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
	if (!tex->wall || !tex->floor || !tex->player
		|| !tex->collect || !tex->exit)
	{
		write(2, "Error loading textures\n", 23);
		exit(EXIT_FAILURE);
	}
}
