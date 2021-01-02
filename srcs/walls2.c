/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:52:46 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 16:55:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_draw_coordinates(t_frame *game, t_raycast *raycaster)
{
	if (raycaster->side == 0)
		raycaster->perpWallDist = (raycaster->mapX - game->player.posX +
		(1 - raycaster->stepX) / 2) / raycaster->rayDirX;
	else
		raycaster->perpWallDist = (raycaster->mapY - game->player.posY +
		(1 - raycaster->stepY) / 2) / raycaster->rayDirY;
	raycaster->lineHeight = (int)(game->screenHeight2 /
		raycaster->perpWallDist);
	raycaster->drawStart = -raycaster->lineHeight / 2 + game->screenHeight2 / 2;
	if (raycaster->drawStart < 0)
		raycaster->drawStart = 0;
	raycaster->drawEnd = raycaster->lineHeight / 2 + game->screenHeight2 / 2;
	if (raycaster->drawEnd >= game->screenHeight2)
		raycaster->drawEnd = game->screenHeight2 - 1;
}

void	calc_texture_coordinates(t_frame *game, t_raycast *raycaster)
{
	if (raycaster->side == 0)
		raycaster->wallX =
		game->player.posY + raycaster->perpWallDist * raycaster->rayDirY;
	else
		raycaster->wallX =
		game->player.posX + raycaster->perpWallDist * raycaster->rayDirX;
	raycaster->wallX -= floor((raycaster->wallX));
	raycaster->texX =
	(int)(raycaster->wallX * (double)(game->textures.texWidth));
	if (raycaster->side == 0 && raycaster->rayDirX > 0)
		raycaster->texX = game->textures.texWidth - raycaster->texX - 1;
	if (raycaster->side == 1 && raycaster->rayDirY < 0)
		raycaster->texX = game->textures.texWidth - raycaster->texX - 1;
	raycaster->step = 1.0 * game->textures.texHeight / raycaster->lineHeight;
	raycaster->texPos =
	(raycaster->drawStart - game->screenHeight2 / 2 + raycaster->lineHeight / 2)
	* raycaster->step;
}

void	draw_stripe_in_buffer(t_frame *game, t_raycast *raycaster, int x)
{
	int y;

	y = raycaster->drawStart;
	while (y++ < raycaster->drawEnd)
	{
		raycaster->texY = (int)raycaster->texPos
		& (game->textures.texHeight - 1);
		raycaster->texPos += raycaster->step;
		raycaster->color = 0;
		if (raycaster->side == 1 && game->player.posY > raycaster->mapY)
			raycaster->color = game->textures.westTex
			[game->textures.texHeight * raycaster->texY + raycaster->texX];
		else if (raycaster->side == 1 && game->player.posY < raycaster->mapY)
			raycaster->color = game->textures.eastTex
			[game->textures.texHeight * raycaster->texY + raycaster->texX];
		else if (raycaster->side == 0 && game->player.posX > raycaster->mapX)
			raycaster->color = game->textures.northTex
			[game->textures.texHeight * raycaster->texY + raycaster->texX];
		else if (raycaster->side == 0 && game->player.posX < raycaster->mapX)
			raycaster->color = game->textures.southTex
			[game->textures.texHeight * raycaster->texY + raycaster->texX];
		if (raycaster->side == 1)
			raycaster->color = (raycaster->color >> 1) & 8355711;
		game->buffer[y][x] = raycaster->color;
	}
}
