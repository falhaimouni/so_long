/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:21:05 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/09 12:26:32 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int	width;
	int	height;
} t_game;

typedef struct s_elem
{
	void	*player;
	void	*collect;
	void	*exit;
	void	*wall;
	void	*floor;	
} t_elem;

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

#endif
