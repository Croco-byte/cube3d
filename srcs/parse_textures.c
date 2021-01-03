/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:41:09 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:09:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_no_tex(t_frame *game, char *line, int i)
{
	int	length;

	if (game->paths.nopath != 0)
	{
		ft_printf("Redefinition of north tex path. Ignoring...\n");
		return ;
	}
	length = 0;
	i += 2;
	i += pass_spaces(line, i);
	while (line[i + length] && !ft_isspace(line[i + length]))
		length++;
	game->paths.nopath = ft_substr(line, i, length);
}

void	get_so_tex(t_frame *game, char *line, int i)
{
	int	length;

	if (game->paths.sopath != 0)
	{
		ft_printf("Redefinition of south tex path. Ignoring...\n");
		return ;
	}
	length = 0;
	i += 2;
	i += pass_spaces(line, i);
	while (line[i + length] && !ft_isspace(line[i + length]))
		length++;
	game->paths.sopath = ft_substr(line, i, length);
}

void	get_we_tex(t_frame *game, char *line, int i)
{
	int	length;

	if (game->paths.wepath != 0)
	{
		ft_printf("Redefinition of west tex path. Ignoring...\n");
		return ;
	}
	length = 0;
	i += 2;
	i += pass_spaces(line, i);
	while (line[i + length] && !ft_isspace(line[i + length]))
		length++;
	game->paths.wepath = ft_substr(line, i, length);
}

void	get_ea_tex(t_frame *game, char *line, int i)
{
	int	length;

	if (game->paths.eapath != 0)
	{
		ft_printf("Redefinition of east tex path. Ignoring...\n");
		return ;
	}
	length = 0;
	i += 2;
	i += pass_spaces(line, i);
	while (line[i + length] && !ft_isspace(line[i + length]))
		length++;
	game->paths.eapath = ft_substr(line, i, length);
}
