/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:11:30 by lgatibel          #+#    #+#             */
/*   Updated: 2016/02/10 11:11:07 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_set_line(t_cache *cache, char **line)
{
	int		fin;

	fin = -1;
	if ((fin = ft_strichr(cache->str, '\n')) == -1)
	{
		*line = ft_strdup(cache->str);
		cache->str = "";
		return (0);
	}
	else
	{
		*line = ft_strsub(cache->str, 0, fin);
		cache->str = ft_strdup(&cache->str[fin + 1]);
		return (1);
	}
}

int				ft_read(char **line, int fd, t_cache *cache, int fin)
{
	int		bytes;
	char	buff[BUFF_SIZE + 1];

	bytes = 0;
	while (fin == -1 && (bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if ((fin = ft_strichr(buff, '\n')) == -1)
			*line = ft_strjoin(*line, buff);
		else
		{
			*line = ft_strjoin(*line, ft_strsub(buff, 0, fin));
			cache->str = ft_strdup(&buff[fin + 1]);
			return (-2);
		}
	}
	return (bytes);
}

int				get_next_line(int const fd, char **line)
{
	static t_cache	*cache;
	int				fin;
	int				bytes;

	bytes = 0;
	fin = -1;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = "";
	if (cache && ft_set_line(cache, line) == 1)
		return (1);
	else
	{
		cache = (t_cache *)malloc(sizeof(t_cache));
		cache->str = "";
	}
	bytes = ft_read(line, fd, cache, fin);
	if (bytes == -2 || (bytes == 0 && ft_strlen(*line) > 0 && fin == -1))
		return (1);
	if (bytes == -1)
		return (-1);
	return (0);
}
