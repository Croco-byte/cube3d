/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:03:56 by user42            #+#    #+#             */
/*   Updated: 2020/12/27 15:09:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_frame *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(game->player.rotSpeed) -
						game->player.dirY * sin(game->player.rotSpeed);
	game->player.dirY = old_dirx * sin(game->player.rotSpeed) +
						game->player.dirY * cos(game->player.rotSpeed);
	old_planex = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(game->player.rotSpeed) -
							game->player.planeY * sin(game->player.rotSpeed);
	game->player.planeY = old_planex * sin(game->player.rotSpeed) +
							game->player.planeY * cos(game->player.rotSpeed);
}

void	rotate_right(t_frame *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(-game->player.rotSpeed) -
						game->player.dirY * sin(-game->player.rotSpeed);
	game->player.dirY = old_dirx * sin(-game->player.rotSpeed) +
						game->player.dirY * cos(-game->player.rotSpeed);
	old_planex = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(-game->player.rotSpeed) -
							game->player.planeY * sin(-game->player.rotSpeed);
	game->player.planeY = old_planex * sin(-game->player.rotSpeed) +
							game->player.planeY * cos(-game->player.rotSpeed);
}
