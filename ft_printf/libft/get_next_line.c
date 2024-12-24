/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falhaimo <falhaimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:21:39 by falhaimo          #+#    #+#             */
/*   Updated: 2024/12/24 09:35:28 by falhaimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*freee(char *buffer, char *line)
{
	if (line)
		free(line);
	if (buffer)
		free(buffer);
	return (NULL);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	subline(char **cur_line, char *buf)
{
	char	*line;
	int		i;	

	i = 0;
	while ((*cur_line)[i] != '\n' && (*cur_line)[i] != '\0')
		i++;
	if ((*cur_line)[i] == '\n')
	{
		line = ft_substr(*cur_line, 0, i + 1);
		if (!line)
		{
			free(*cur_line);
			*cur_line = NULL;
			return ;
		}
		ft_strcpy(buf, *cur_line + i + 1);
	}
	else
	{
		line = ft_strdup(*cur_line);
		buf[0] = '\0';
	}
	free(*cur_line);
	*cur_line = line;
}

static char	*join(char *buffer, char *buf, int fd)
{
	char	*line;
	char	*tline;
	int		bnum;

	line = ft_strdup(buf);
	while (!ft_strchr(line, '\n'))
	{
		bnum = read(fd, buffer, BUFFER_SIZE);
		if (bnum < 0)
			return (freee(buffer, line));
		if (*line == '\0' && bnum == 0)
			return (freee(buffer, line));
		if (bnum == 0)
			break ;
		buffer[bnum] = '\0';
		tline = ft_strjoin(line, buffer);
		free(line);
		line = tline;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*buffer;
	char		*cur_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	cur_line = join(buffer, buf, fd);
	if (!cur_line)
	{
		*buf = '\0';
		return (NULL);
	}
	subline(&cur_line, buf);
	return (cur_line);
}
