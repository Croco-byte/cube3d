/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:44:00 by user42            #+#    #+#             */
/*   Updated: 2020/12/31 13:03:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_s_tex(t_frame *game, char *line, int i)
{
	int length;

	if (game->paths.spath != 0)
	{
		ft_printf("Redefinition of main sprite path. Ignoring...\n");
		return ;
	}
	length = 0;
	i++;
	i += pass_spaces(line, i);
	while (line[i + length] && !ft_isspace(line[i + length]))
		length++;
	game->paths.spath = ft_substr(line, i, length);
}

void	get_s2_tex(t_frame *game, char *line, int i)
{
	int length;

	if (game->paths.s2path != 0)
	{
		ft_printf("Redefinition of optional sprite 2 path. Ignoring...\n");
		return ;
	}
	length = 0;
	i += 2;
	i += pass_spaces(line, i);
	while (line[i + length] && !ft_isspace(line[i + length]))
		length++;
	game->paths.s2path = ft_substr(line, i, length);
}

void	get_s3_tex(t_frame *game, char *line, int i)
{
	int length;

	if (game->paths.s3path != 0)
	{
		ft_printf("Redefinition of optional sprite 3 path. Ignoring...\n");
		return ;
	}
	length = 0;
	i += 2;
	i += pass_spaces(line, i);
	while (line[i + length] && !ft_isspace(line[i + length]))
		length++;
	game->paths.s3path = ft_substr(line, i, length);
}

void	get_s4_tex(t_frame *game, char *line, int i)
{
	int length;

	if (game->paths.s4path != 0)
	{
		ft_printf("Redefinition of optional sprite 4 path. Ignoring...\n");
		return ;
	}
	length = 0;
	i += 2;
	i += pass_spaces(line, i);
	while (line[i + length] && !ft_isspace(line[i + length]))
		length++;
	game->paths.s4path = ft_substr(line, i, length);
}
