/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:37:58 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 15:14:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_frame *game, t_raycast *raycaster, int x)
{
	raycaster->camerax = 2 * x / (double)game->screenwidth - 1;
	raycaster->raydirx = game->player.dirx + game->player.planex * raycaster->camerax;
	raycaster->raydiry = game->player.diry + game->player.planey * raycaster->camerax;
	raycaster->mapx = (int)game->player.posx;
	raycaster->mapy = (int)game->player.posy;
	raycaster->deltadistx = fabs(1 / raycaster->raydirx);
	raycaster->deltadisty = fabs(1 / raycaster->raydiry);
	raycaster->hit = 0;
}

void	dda_preparations(t_frame *game, t_raycast *raycaster)
{
	if (raycaster->raydirx < 0)
	{
		raycaster->stepx = -1;
		raycaster->sidedistx = (game->player.posx - raycaster->mapx)
			* raycaster->deltadistx;
	}
	else
	{
		raycaster->stepx = 1;
		raycaster->sidedistx = (raycaster->mapx + 1.0 - game->player.posx)
			* raycaster->deltadistx;
	}
	if (raycaster->raydiry < 0)
	{
		raycaster->stepy = -1;
		raycaster->sidedisty = (game->player.posy - raycaster->mapy)
			* raycaster->deltadisty;
	}
	else
	{
		raycaster->stepy = 1;
		raycaster->sidedisty = (raycaster->mapy + 1.0 - game->player.posy)
			* raycaster->deltadisty;
	}
}

void	dda_perform(t_frame *game, t_raycast *raycaster)
{
	while (raycaster->hit == 0)
	{
		if (raycaster->sidedistx < raycaster->sidedisty)
		{
			raycaster->sidedistx += raycaster->deltadistx;
			raycaster->mapx += raycaster->stepx;
			raycaster->side = 0;
		}
		else
		{
			raycaster->sidedisty += raycaster->deltadisty;
			raycaster->mapy += raycaster->stepy;
			raycaster->side = 1;
		}
		if (game->worldmap2[raycaster->mapx][raycaster->mapy] == '1')
			raycaster->hit = 1;
	}
}
