/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:19:30 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 15:20:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	can_move(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == ' ')
		return (1);
	return (0);
}

void	move_forward(t_frame *game)
{
	char	next_box;

	next_box = game->worldmap2
		[(int)(game->player.posx + game->player.dirx * game->player.movespeed)]
		[(int)game->player.posy];
	if (can_move(next_box))
		game->player.posx += game->player.dirx * game->player.movespeed;
	next_box = game->worldmap2
		[(int)game->player.posx]
		[(int)(game->player.posy + game->player.diry * game->player.movespeed)];
	if (can_move(next_box))
		game->player.posy += game->player.diry * game->player.movespeed;
}

void	move_back(t_frame *game)
{
	char	next_box;

	next_box = game->worldmap2
		[(int)(game->player.posx - game->player.dirx * game->player.movespeed)]
		[(int)game->player.posy];
	if (can_move(next_box))
		game->player.posx -= game->player.dirx * game->player.movespeed;
	next_box = game->worldmap2
		[(int)game->player.posx]
		[(int)(game->player.posy - game->player.diry * game->player.movespeed)];
	if (can_move(next_box))
		game->player.posy -= game->player.diry * game->player.movespeed;
}

void	move_right(t_frame *game)
{
	char	next_box;

	next_box = game->worldmap2
		[(int)(game->player.posx + game->player.planex * game->player.movespeed)]
		[(int)game->player.posy];
	if (can_move(next_box))
		game->player.posx += game->player.planex * game->player.movespeed;
	next_box = game->worldmap2
		[(int)game->player.posx]
		[(int)(game->player.posy + game->player.planey * game->player.movespeed)];
	if (can_move(next_box))
		game->player.posy += game->player.planey * game->player.movespeed;
}

void	move_left(t_frame *game)
{
	char	next_box;

	next_box = game->worldmap2
		[(int)(game->player.posx - game->player.planex * game->player.movespeed)]
		[(int)game->player.posy];
	if (can_move(next_box))
		game->player.posx -= game->player.planex * game->player.movespeed;
	next_box = game->worldmap2
		[(int)game->player.posx]
		[(int)(game->player.posy - game->player.planey * game->player.movespeed)];
	if (can_move(next_box))
		game->player.posy -= game->player.planey * game->player.movespeed;
}
