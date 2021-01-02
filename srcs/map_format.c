/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:42:34 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 17:00:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == '3'
		|| c == '4' || c == '5' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ')
		return (1);
	return (0);
}

void	check_map_content(t_frame *game)
{
	int i;
	int j;

	i = 0;
	while (game->worldmap2[i])
	{
		j = 0;
		while (game->worldmap2[i][j])
		{
			if (!is_map_char(game->worldmap2[i][j]))
			{
				ft_printf("Unknown map char %c (line %i). Exiting...\n",
				game->worldmap2[i][j], i);
				clean_exit(game);
			}
			j++;
		}
		i++;
	}
}
