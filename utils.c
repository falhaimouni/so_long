/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:15:13 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/24 10:22:00 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game *game)
{
	game->collected = 0;
	game->count = 0;
	game->c = 0;
}

int	count_lines(int fd)
{
	char	*line;
	int		lines;

	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
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
		while (map[i][j++])
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collect++;
		}
		i++;
	}
	return (player == 1 && exit == 1 && collect > 0);
}
