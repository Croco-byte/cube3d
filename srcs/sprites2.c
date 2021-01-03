/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:10:59 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 15:29:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprutils(t_frame *game, t_sprutils *sprutils, int i)
{
	sprutils->spritex = game->sprites.spr[game->sprites.spriteorder[i]].x
		- game->player.posx;
	sprutils->spritey = game->sprites.spr[game->sprites.spriteorder[i]].y
		- game->player.posy;
	sprutils->invdet = 1.0 / (game->player.planex * game->player.diry
			- game->player.dirx * game->player.planey);
	sprutils->transformx = sprutils->invdet * (game->player.diry
			* sprutils->spritex - game->player.dirx * sprutils->spritey);
	sprutils->transformy = sprutils->invdet * (-game->player.planey
			* sprutils->spritex + game->player.planex * sprutils->spritey);
	sprutils->spritescreenx = (int)((game->screenwidth / 2)
			*(1 + sprutils->transformx / sprutils->transformy));
	sprutils->spriteheight = abs((int)(game->screenheight / (sprutils->transformy)));
}

void	spr_coordinates(t_frame *game, t_sprutils *sprutils)
{
	sprutils->drawstarty = -sprutils->spriteheight / 2 + game->screenheight / 2;
	if (sprutils->drawstarty < 0)
		sprutils->drawstarty = 0;
	sprutils->drawendy = sprutils->spriteheight / 2 + game->screenheight / 2;
	if (sprutils->drawendy >= game->screenheight)
		sprutils->drawendy = game->screenheight - 1;
	sprutils->spritewidth = abs((int)(game->screenheight / (sprutils->transformy)));
	sprutils->drawstartx = -sprutils->spritewidth / 2 + sprutils->spritescreenx;
	if (sprutils->drawstartx < 0)
		sprutils->drawstartx = 0;
	sprutils->drawendx = sprutils->spritewidth / 2 + sprutils->spritescreenx;
	if (sprutils->drawendx >= game->screenwidth)
		sprutils->drawendx = game->screenwidth - 1;
}

void	choose_sprite(t_frame *game, t_sprutils *sprutils, int i)
{
	if (game->sprites.spr[game->sprites.spriteorder[i]].sprtex == 2)
		sprutils->color = game->sprites.sprite1tex
			[game->sprites.texwidth * sprutils->texy + sprutils->texx];
	if (game->sprites.spr[game->sprites.spriteorder[i]].sprtex == 3)
		sprutils->color = game->sprites.sprite2tex
			[game->sprites.texwidth * sprutils->texy + sprutils->texx];
	if (game->sprites.spr[game->sprites.spriteorder[i]].sprtex == 4)
		sprutils->color = game->sprites.sprite3tex
			[game->sprites.texwidth * sprutils->texy + sprutils->texx];
	if (game->sprites.spr[game->sprites.spriteorder[i]].sprtex == 5)
		sprutils->color = game->sprites.sprite4tex
			[game->sprites.texwidth * sprutils->texy + sprutils->texx];
}

void	ver_spr(t_frame *game, t_sprutils *sprutils, int i, int stripe)
{
	int	y;

	y = sprutils->drawstarty;
	while (y < sprutils->drawendy)
	{
		sprutils->d = (y) * 256 - game->screenheight * 128
			+ sprutils->spriteheight * 128;
		sprutils->texy = ((sprutils->d * game->sprites.texheight)
				/ sprutils->spriteheight) / 256;
		sprutils->color = 0;
		choose_sprite(game, sprutils, i);
		if ((sprutils->color & 0x00FFFFFF) != 0
			&& (sprutils->color & 0x0067FF77) != 0)
			game->buffer[y][stripe] = sprutils->color;
		y++;
	}
}

void	spr_draw(t_frame *game, t_sprutils *sprutils, int i)
{
	int	stripe;

	stripe = sprutils->drawstartx;
	while (stripe < sprutils->drawendx)
	{
		sprutils->texx = (int)(256 * (stripe - (-sprutils->spritewidth / 2
						+ sprutils->spritescreenx)) * game->sprites.texwidth
				/ sprutils->spritewidth) / 256;
		if (sprutils->transformy > 0 && stripe > 0
			&& stripe < game->screenwidth
			&& sprutils->transformy < game->zbuffer[stripe])
		{
			ver_spr(game, sprutils, i, stripe);
		}
		stripe++;
	}
}
