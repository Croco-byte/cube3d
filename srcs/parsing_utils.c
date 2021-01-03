/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:17:23 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:12:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_digit(char c)
{
	if (c == '0' || c == '1' || c == '2'
		|| c == '3' || c == '4' || c == '5')
		return (1);
	return (0);
}

int	pass_spaces(char *line, int i)
{
	int	spaces_number;

	spaces_number = 0;
	while (line[i] && ft_isspace(line[i]))
	{
		spaces_number++;
		i++;
	}
	return (spaces_number);
}

char	*ft_mapjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	s1_size;
	size_t	s2_size;
	char	*result;

	i = -1;
	k = -1;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	if (!s1 && !s2)
		return (0);
	result = malloc((s1_size + s2_size + 2) *sizeof(char));
	if (!result)
		return (0);
	while (++i < s1_size)
		result[i] = s1[i];
	while (++k < s2_size)
		result[i + k] = s2[k];
	result[i + k++] = '\n';
	result[i + k] = '\0';
	free((char *)s1);
	return (result);
}

int	open_map(t_frame *game, int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_printf("No map provided. Exiting...\n");
		clean_exit(game);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Couldn't open map. Exiting...\n");
		clean_exit(game);
	}
	return (fd);
}
