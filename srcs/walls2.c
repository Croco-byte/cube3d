/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:52:46 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 15:27:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_draw_coordinates(t_frame *game, t_raycast *raycaster)
{
	if (raycaster->side == 0)
		raycaster->perpwalldist = (raycaster->mapx - game->player.posx
				+ (1 - raycaster->stepx) / 2) / raycaster->raydirx;
	else
		raycaster->perpwalldist = (raycaster->mapy - game->player.posy
				+ (1 - raycaster->stepy) / 2) / raycaster->raydiry;
	raycaster->lineheight = (int)(game->screenheight
			/ raycaster->perpwalldist);
	raycaster->drawstart = -raycaster->lineheight / 2 + game->screenheight / 2;
	if (raycaster->drawstart < 0)
		raycaster->drawstart = 0;
	raycaster->drawend = raycaster->lineheight / 2 + game->screenheight / 2;
	if (raycaster->drawend >= game->screenheight)
		raycaster->drawend = game->screenheight - 1;
}

void	calc_texture_coordinates(t_frame *game, t_raycast *raycaster)
{
	if (raycaster->side == 0)
		raycaster->wallx = game->player.posy
			+ raycaster->perpwalldist * raycaster->raydiry;
	else
		raycaster->wallx = game->player.posx
			+ raycaster->perpwalldist * raycaster->raydirx;
	raycaster->wallx -= floor((raycaster->wallx));
	raycaster->texx = (int)(raycaster->wallx * (double)(game->textures.texwidth));
	if (raycaster->side == 0 && raycaster->raydirx > 0)
		raycaster->texx = game->textures.texwidth - raycaster->texx - 1;
	if (raycaster->side == 1 && raycaster->raydiry < 0)
		raycaster->texx = game->textures.texwidth - raycaster->texx - 1;
	raycaster->step = 1.0 * game->textures.texheight / raycaster->lineheight;
	raycaster->texpos = (raycaster->drawstart - game->screenheight
			/ 2 + raycaster->lineheight / 2)
		* raycaster->step;
}

void	draw_stripe_buffer(t_frame *game, t_raycast *raycaster, int x)
{
	int	y;

	y = raycaster->drawstart;
	while (y++ < raycaster->drawend)
	{
		raycaster->texy = (int)raycaster->texpos
			& (game->textures.texheight - 1);
		raycaster->texpos += raycaster->step;
		raycaster->color = 0;
		if (raycaster->side == 1 && game->player.posy > raycaster->mapy)
			raycaster->color = game->textures.westtex
				[game->textures.texheight * raycaster->texy + raycaster->texx];
		else if (raycaster->side == 1 && game->player.posy < raycaster->mapy)
			raycaster->color = game->textures.easttex
				[game->textures.texheight * raycaster->texy + raycaster->texx];
		else if (raycaster->side == 0 && game->player.posx > raycaster->mapx)
			raycaster->color = game->textures.northtex
				[game->textures.texheight * raycaster->texy + raycaster->texx];
		else if (raycaster->side == 0 && game->player.posx < raycaster->mapx)
			raycaster->color = game->textures.southtex
				[game->textures.texheight * raycaster->texy + raycaster->texx];
		if (raycaster->side == 1)
			raycaster->color = (raycaster->color >> 1) & 8355711;
		game->buffer[y][x] = raycaster->color;
	}
}
