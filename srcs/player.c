/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:36:32 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 15:20:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_north_south(t_frame *game, int i, int j)
{
	if (game->worldmap2[i][j] == 'N')
	{
		game->player.posx = i + 0.5;
		game->player.posy = j + 0.5;
		game->player.dirx = -1;
		game->player.diry = 0;
		game->player.planex = 0;
		game->player.planey = 0.66;
	}
	if (game->worldmap2[i][j] == 'S')
	{
		game->player.posx = i + 0.5;
		game->player.posy = j + 0.5;
		game->player.dirx = 1;
		game->player.diry = 0;
		game->player.planex = 0;
		game->player.planey = -0.66;
	}
}

void	check_west_east(t_frame *game, int i, int j)
{
	if (game->worldmap2[i][j] == 'W')
	{
		game->player.posx = i + 0.5;
		game->player.posy = j + 0.5;
		game->player.dirx = 0;
		game->player.diry = -1;
		game->player.planex = -0.66;
		game->player.planey = 0;
	}
	if (game->worldmap2[i][j] == 'E')
	{
		game->player.posx = i + 0.5;
		game->player.posy = j + 0.5;
		game->player.dirx = 0;
		game->player.diry = 1;
		game->player.planex = 0.66;
		game->player.planey = 0;
	}
}

void	place_player(t_frame *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->worldmap2[i])
	{
		j = 0;
		while (game->worldmap2[i][j])
		{
			check_north_south(game, i, j);
			check_west_east(game, i, j);
			j++;
		}
		i++;
	}
}

void	init_player(t_frame *game)
{
	game->player.posx = 0;
	game->player.posy = 0;
	place_player(game);
	if (game->player.posx < 1 || game->player.posy < 1)
	{
		ft_printf("Incorrect player position. Exiting...\n");
		clean_exit(game);
	}
	game->player.movespeed = (double)game->screenwidth / 10000
		+ (double)game->screenheight / 10000;
	game->player.rotspeed = (double)game->screenwidth / 10000
		+ (double)game->screenheight / 10000;
	game->player.moveforward = 0;
	game->player.moveback = 0;
	game->player.moveleft = 0;
	game->player.moveright = 0;
	game->player.rotateleft = 0;
	game->player.rotateright = 0;
}
