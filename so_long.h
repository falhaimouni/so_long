/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:21:05 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/29 11:30:02 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_elem
{
	void	*player;
	void	*collect;
	void	*exit;
	void	*wall;
	void	*floor;	
}	t_elem;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collected;
	int		c;
	void	*player;
	int		count;
	int		move;
	t_elem	*textures;
}	t_game;

typedef struct s_info
{
	bool	**visited;
	int		rows;
	int		cols;
	int		start_x;
	int		start_y;
}	t_info;

void	init_vars(t_game *game);
int		count_lines(int fd);
void	remove_newline(char *line);
int		is_rect(char **map);
int		elements(char **map);
void	render_map(t_game *game, t_elem *textures);
void	move_player(t_game *game, int dx, int dy);
void	free_map(char **map);
int		count_collectibles(char **map);
char	**read_map(char *file_path);
void	valid_map(char **map);
void	init(t_game *game, char **map);
void	load_textures(t_game *game, t_elem *tex);
int		count_lines(int fd);
void	remove_newline(char *line);
int		is_rect(char **map);
int		elements(char **map);
int		key_hook(int keycode, t_game *game);
void	render_palyer(t_game *game, t_elem *textures);
void	free_img(t_game *game);
void	free_window(t_game *game);
void	free_map(char **map);
int		check_walls(char *line);
int		is_wall(char **map);
int		free_game(t_game *game);
void	dfs(char **map, int x, int y, bool **visited);
int		has_valid_path(char **map);
#endif
