/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:10:59 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 16:57:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprutils(t_frame *game, t_sprutils *sprutils, int i)
{
	sprutils->spriteX = game->sprites.spr[game->sprites.spriteOrder[i]].x -
						game->player.posX;
	sprutils->spriteY = game->sprites.spr[game->sprites.spriteOrder[i]].y -
						game->player.posY;
	sprutils->invDet = 1.0 / (game->player.planeX * game->player.dirY -
							game->player.dirX * game->player.planeY);
	sprutils->transformX = sprutils->invDet * (game->player.dirY *
					sprutils->spriteX - game->player.dirX * sprutils->spriteY);
	sprutils->transformY = sprutils->invDet * (-game->player.planeY *
				sprutils->spriteX + game->player.planeX * sprutils->spriteY);
	sprutils->spriteScreenX = (int)((game->screenWidth2 / 2) *
							(1 + sprutils->transformX / sprutils->transformY));
	sprutils->spriteHeight =
		abs((int)(game->screenHeight2 / (sprutils->transformY)));
}

void	spr_coordinates(t_frame *game, t_sprutils *sprutils)
{
	sprutils->drawStartY =
		-sprutils->spriteHeight / 2 + game->screenHeight2 / 2;
	if (sprutils->drawStartY < 0)
		sprutils->drawStartY = 0;
	sprutils->drawEndY = sprutils->spriteHeight / 2 + game->screenHeight2 / 2;
	if (sprutils->drawEndY >= game->screenHeight2)
		sprutils->drawEndY = game->screenHeight2 - 1;
	sprutils->spriteWidth =
		abs((int)(game->screenHeight2 / (sprutils->transformY)));
	sprutils->drawStartX = -sprutils->spriteWidth / 2 +
							sprutils->spriteScreenX;
	if (sprutils->drawStartX < 0)
		sprutils->drawStartX = 0;
	sprutils->drawEndX = sprutils->spriteWidth / 2 + sprutils->spriteScreenX;
	if (sprutils->drawEndX >= game->screenWidth2)
		sprutils->drawEndX = game->screenWidth2 - 1;
}

void	choose_sprite(t_frame *game, t_sprutils *sprutils, int i)
{
	if (game->sprites.spr[game->sprites.spriteOrder[i]].sprTex == 2)
		sprutils->color = game->sprites.sprite1Tex
		[game->sprites.texWidth * sprutils->texY + sprutils->texX];
	if (game->sprites.spr[game->sprites.spriteOrder[i]].sprTex == 3)
		sprutils->color = game->sprites.sprite2Tex
		[game->sprites.texWidth * sprutils->texY + sprutils->texX];
	if (game->sprites.spr[game->sprites.spriteOrder[i]].sprTex == 4)
		sprutils->color = game->sprites.sprite3Tex
		[game->sprites.texWidth * sprutils->texY + sprutils->texX];
	if (game->sprites.spr[game->sprites.spriteOrder[i]].sprTex == 5)
		sprutils->color = game->sprites.sprite4Tex
		[game->sprites.texWidth * sprutils->texY + sprutils->texX];
}

void	draw_vert_spr(t_frame *game, t_sprutils *sprutils, int i, int stripe)
{
	int y;

	y = sprutils->drawStartY;
	while (y < sprutils->drawEndY)
	{
		sprutils->d = (y) * 256 - game->screenHeight2 * 128 +
					sprutils->spriteHeight * 128;
		sprutils->texY = ((sprutils->d * game->sprites.texHeight) /
						sprutils->spriteHeight) / 256;
		sprutils->color = 0;
		choose_sprite(game, sprutils, i);
		if ((sprutils->color & 0x00FFFFFF) != 0 &&
		(sprutils->color & 0x0067FF77) != 0)
			game->buffer[y][stripe] = sprutils->color;
		y++;
	}
}

void	spr_draw(t_frame *game, t_sprutils *sprutils, int i)
{
	int stripe;

	stripe = sprutils->drawStartX;
	while (stripe < sprutils->drawEndX)
	{
		sprutils->texX = (int)(256 * (stripe - (-sprutils->spriteWidth / 2
		+ sprutils->spriteScreenX)) * game->sprites.texWidth /
		sprutils->spriteWidth) / 256;
		if (sprutils->transformY > 0 && stripe > 0
							&& stripe < game->screenWidth2
							&& sprutils->transformY < game->ZBuffer[stripe])
		{
			draw_vert_spr(game, sprutils, i, stripe);
		}
		stripe++;
	}
}
