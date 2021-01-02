/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:37:58 by user42            #+#    #+#             */
/*   Updated: 2020/12/29 13:34:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_raycast(t_frame *game, t_raycast *raycaster, int x)
{
	raycaster->cameraX = 2 * x / (double)game->screenWidth2 - 1;
	raycaster->rayDirX =
				game->player.dirX + game->player.planeX * raycaster->cameraX;
	raycaster->rayDirY =
				game->player.dirY + game->player.planeY * raycaster->cameraX;
	raycaster->mapX = (int)game->player.posX;
	raycaster->mapY = (int)game->player.posY;
	raycaster->deltaDistX = fabs(1 / raycaster->rayDirX);
	raycaster->deltaDistY = fabs(1 / raycaster->rayDirY);
	raycaster->hit = 0;
}

void	dda_preparations(t_frame *game, t_raycast *raycaster)
{
	if (raycaster->rayDirX < 0)
	{
		raycaster->stepX = -1;
		raycaster->sideDistX =
				(game->player.posX - raycaster->mapX) * raycaster->deltaDistX;
	}
	else
	{
		raycaster->stepX = 1;
		raycaster->sideDistX =
		(raycaster->mapX + 1.0 - game->player.posX) * raycaster->deltaDistX;
	}
	if (raycaster->rayDirY < 0)
	{
		raycaster->stepY = -1;
		raycaster->sideDistY =
				(game->player.posY - raycaster->mapY) * raycaster->deltaDistY;
	}
	else
	{
		raycaster->stepY = 1;
		raycaster->sideDistY =
		(raycaster->mapY + 1.0 - game->player.posY) * raycaster->deltaDistY;
	}
}

void	dda_perform(t_frame *game, t_raycast *raycaster)
{
	while (raycaster->hit == 0)
	{
		if (raycaster->sideDistX < raycaster->sideDistY)
		{
			raycaster->sideDistX += raycaster->deltaDistX;
			raycaster->mapX += raycaster->stepX;
			raycaster->side = 0;
		}
		else
		{
			raycaster->sideDistY += raycaster->deltaDistY;
			raycaster->mapY += raycaster->stepY;
			raycaster->side = 1;
		}
		if (game->worldmap2[raycaster->mapX][raycaster->mapY] == '1')
			raycaster->hit = 1;
	}
}
