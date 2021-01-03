/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:06:56 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 16:50:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*line_from_save(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc((i + 1) *sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	malloc_fails(char **line, char *save, int *last_line)
{
	if (!*line || (!save && *last_line != 1))
	{
		free(*line);
		free(save);
		return (1);
	}
	else
		return (0);
}

char	*alloc_buff(void)
{
	char	*result;

	result = malloc(sizeof(char) * 64 + 1);
	return (result);
}

void	init_gnl(int *last_line, int *reader)
{
	*last_line = 0;
	*reader = 1;
}

int	get_next_line(int fd, char **line)
{
	static char		*save = 0;
	char			*buff;
	int				reader;
	int				last_line;

	init_gnl(&last_line, &reader);
	buff = alloc_buff();
	if (fd < 0 || !line || 64 <= 0 || !(buff))
		return (-1);
	while (has_return(save) != 1 && reader != 0)
	{
		reader = read(fd, buff, 64);
		if (reader == -1)
			return (-1);
		buff[reader] = '\0';
		save = ft_gnljoin(save, buff);
	}
	free(buff);
	*line = line_from_save(save);
	save = update_save(save, &last_line);
	if (malloc_fails(line, save, &last_line))
		return (-1);
	if (reader == 0)
		return (0);
	return (1);
}
