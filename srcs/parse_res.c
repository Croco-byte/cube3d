/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:14:13 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:08:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_width(t_frame *game, char *line, int *i)
{
	while (line[*i] && !ft_isspace(line[*i]))
	{
		if (ft_isdigit(line[*i]))
		{
			game->screenwidth *= 10;
			game->screenwidth += line[*i] - 48;
		}
		else
		{
			ft_printf("Can't get resolution width. Exiting...\n");
			clean_exit(game);
		}
		*i = (*i) + 1;
	}
}

static void	get_height(t_frame *game, char *line, int *i)
{
	while (line[*i] && !ft_isspace(line[*i]))
	{
		if (ft_isdigit(line[*i]))
		{
			game->screenheight *= 10;
			game->screenheight += line[*i] - 48;
		}
		else
		{
			ft_printf("Can't get resolution height. Exiting...\n");
			clean_exit(game);
		}
		*i = (*i) + 1;
	}
}

void	get_resolution(t_frame *game, char *line, int i)
{
	int	max_width;
	int	max_height;

	i++;
	i += pass_spaces(line, i);
	get_width(game, line, &i);
	i += pass_spaces(line, i);
	get_height(game, line, &i);
	mlx_get_screen_size(game->mlx, &max_width, &max_height);
	if (game->screenwidth > max_width)
		game->screenwidth = max_width;
	if (game->screenheight > max_height)
		game->screenheight = max_height;
}
