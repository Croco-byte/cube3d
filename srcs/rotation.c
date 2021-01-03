/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:03:56 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:17:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_frame *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(game->player.rotspeed)
		- game->player.diry * sin(game->player.rotspeed);
	game->player.diry = old_dirx * sin(game->player.rotspeed)
		+ game->player.diry * cos(game->player.rotspeed);
	old_planex = game->player.planex;
	game->player.planex = game->player.planex * cos(game->player.rotspeed)
		- game->player.planey * sin(game->player.rotspeed);
	game->player.planey = old_planex * sin(game->player.rotspeed)
		+ game->player.planey * cos(game->player.rotspeed);
}

void	rotate_right(t_frame *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->player.dirx;
	game->player.dirx = game->player.dirx * cos(-game->player.rotspeed)
		- game->player.diry * sin(-game->player.rotspeed);
	game->player.diry = old_dirx * sin(-game->player.rotspeed)
		+ game->player.diry * cos(-game->player.rotspeed);
	old_planex = game->player.planex;
	game->player.planex = game->player.planex * cos(-game->player.rotspeed)
		- game->player.planey * sin(-game->player.rotspeed);
	game->player.planey = old_planex * sin(-game->player.rotspeed)
		+ game->player.planey * cos(-game->player.rotspeed);
}
