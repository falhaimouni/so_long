/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:21:05 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/22 14:44:43 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_elem
{
	void	*player;
	void	*collect;
	void	*exit;
	void	*wall;
	void	*floor;	
} t_elem;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collected;
    int     total_collectibles;
    void	*player;
    int move;
    t_elem *textures;
}   t_game;

# include "ft_printf/ft_printf.h"
# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

void	render_map(t_game *game, t_elem *textures);
void	find_player_position(char **map, t_game *game);
void	move_player(t_game *game, int dx, int dy);
void	free_map(char **map);
int     count_collectibles(char **map);
char	**read_map(char *file_path);
void	valid_map(char **map);
void	init(t_game *game, char **map);
void	load_textures(t_game *game, t_elem *tex);
int	count_lines(int fd);
void	remove_newline(char *line);
int	is_rect(char **map);
int	elements(char **map);
int	key_hook(int keycode, t_game *game);
void	render_palyer(t_game *game, t_elem *textures);



#endif
