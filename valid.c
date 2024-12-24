/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:20:50 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/24 15:53:49 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(char **map, int x, int y, bool **visited)
{
	if (x < 0 || y < 0 || !map[x] || !map[x][y]
			|| map[x][y] == '1' || visited[x][y])
		return ;
	visited[x][y] = true;
	dfs(map, x + 1, y, visited);
	dfs(map, x - 1, y, visited);
	dfs(map, x, y + 1, visited);
	dfs(map, x, y - 1, visited);
}

void	initialize_visited(bool ***visited, int rows, int cols)
{
	int	i;

	i = 0;
	*visited = (bool **)malloc(rows * sizeof(bool *));
	while (i < rows)
	{
		(*visited)[i] = (bool *)malloc(cols * sizeof(bool));
		ft_memset((*visited)[i], false, cols * sizeof(bool));
		i++;
	}
}

void	find_start_position(char **map, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	info->start_x = -1;
	info->start_y = -1;
	while (i < info->rows)
	{
		j = 0;
		while (j < info->cols)
		{
			if (map[i][j] == 'P')
			{
				info->start_x = i;
				info->start_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	check_path_exists(char **map, bool **visited, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->rows)
	{
		j = 0;
		while (j < info->cols)
		{
			if (map[i][j] == 'E' && visited[i][j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	has_valid_path(char **map)
{
	t_info	info;
	int		path_exists;
	int		i;

	if (map == NULL)
		return (0);
	info.rows = 0;
	while (map[info.rows] != NULL)
		info.rows++;
	info.cols = strlen(map[0]);
	initialize_visited(&info.visited, info.rows, info.cols);
	find_start_position(map, &info);
	dfs(map, info.start_x, info.start_y, info.visited);
	path_exists = check_path_exists(map, info.visited, &info);
	i = 0;
	while (i < info.rows)
		free(info.visited[i++]);
	free(info.visited);
	return (path_exists);
}
