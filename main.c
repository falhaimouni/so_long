/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:20:16 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/09 14:04:08 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(char *file_path)
{
	int	fd;
	int	i;
	char	**map;
	char	*line;
	
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(1);
	}
	map = malloc(100 * sizeof(char *));
	if (!map)
	{
		perror("Error");
		close(fd);
		exit(1);
	}
	i = 0;
	while((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	is_rect(char **map)
{
	int	i;
	size_t	len;
	
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
	return(player == 1 && exit == 1 && collect > 0);
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
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64, "so_long");
	if (!game->win)
	{
		ft_printf("Error\n");
		exit(1);
	}
}
void load_textures(t_game *game, t_elem *textures)
{
    int img_width, img_height;
    textures->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &img_width, &img_height);
//     textures->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &img_width, &img_height);
//     textures->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &img_width, &img_height);
//     textures->collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &img_width, &img_height);
//     textures->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &img_width, &img_height);
    if (!textures->wall)
    {
        write(2, "Error loading textures\n", 23);
        exit(EXIT_FAILURE);
    }
}
void render_map(t_game *game, t_elem *textures)
{
	if (!game->mlx || !textures->wall) {
    write(2, "Error: Invalid mlx or texture\n", 30);
    exit(EXIT_FAILURE);
	}

    int x, y;
    y = 0;
    while (y < game->height)
    {
        x = 0;
        while (x < game->width)
        {
            char tile = game->map[y][x];
            void *img;
            if (tile == '1')
                img = textures->wall;
        //     else if (tile == '0')
        //         img = textures->floor;
        //     else if (tile == 'P')
        //         img = textures->player;
        //     else if (tile == 'C')
        //         img = textures->collect;
        //     else if (tile == 'E')
        //         img = textures->exit;
	ft_printf("mlx: %p, win: %p, wall texture: %p\n", game->mlx, game->win, textures->wall);

            mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
	    if (!game->win) {
    write(2, "Error creating window\n", 22);
    exit(EXIT_FAILURE);
}
            x++;
        }
        y++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Wrong argumemts\n");
        return (1);
    }
    t_game game;
    t_elem textures;
    char **map = read_map(argv[1]);
    valid_map(map);
    init(&game, map);
    load_textures(&game, &textures);
    render_map(&game, &textures);
    mlx_loop(game.mlx); // Start the MiniLibX event loop
    return (0);
}
// int	main()
// {
	
// 	// void	*mlx;
// 	// //void	*mlx_win;
	
// 	// mlx = mlx_init();
// 	// mlx_new_window(mlx, 800, 600, "Ozha");
// 	// mlx_loop(mlx);
// 	// return(0);
// }