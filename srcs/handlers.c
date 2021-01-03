/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:54:38 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 15:27:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocate_buffers(t_frame *game)
{
	int	y;

	y = 0;
	game->buffer = malloc(game->screenheight * sizeof(int *));
	if (!game->buffer)
		return ;
	while (y < game->screenheight)
	{
		game->buffer[y] = malloc(game->screenwidth * sizeof(int));
		if (!game->buffer[y])
			return ;
		y++;
	}
	game->zbuffer = malloc(game->screenwidth * sizeof(double));
	if (!game->zbuffer)
		return ;
}

void	init_buffer(t_frame *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->screenheight / 2)
	{
		x = 0;
		while (x < game->screenwidth)
			game->buffer[y][x++] = game->ceiling;
		y++;
	}
	while (y < game->screenheight)
	{
		x = 0;
		while (x < game->screenwidth)
			game->buffer[y][x++] = game->floor;
		y++;
	}
}

void	handle_movements(t_frame *game)
{
	if (game->player.moveforward)
		move_forward(game);
	if (game->player.moveback)
		move_back(game);
	if (game->player.moveleft)
		move_left(game);
	if (game->player.moveright)
		move_right(game);
	if (game->player.rotateleft)
		rotate_left(game);
	if (game->player.rotateright)
		rotate_right(game);
}

void	do_walls(t_frame *game)
{
	t_raycast	raycaster;
	int			x;

	x = 0;
	while (x < game->screenwidth)
	{
		init_raycast(game, &raycaster, x);
		dda_preparations(game, &raycaster);
		dda_perform(game, &raycaster);
		calc_draw_coordinates(game, &raycaster);
		calc_texture_coordinates(game, &raycaster);
		draw_stripe_buffer(game, &raycaster, x);
		game->zbuffer[x] = raycaster.perpwalldist;
		x++;
	}
}

void	do_sprites(t_frame *game)
{
	int			i;
	t_sprutils	sprutils;

	i = 0;
	init_sprarray(game);
	while (i < game->sprites.numsprites)
	{
		init_sprutils(game, &sprutils, i);
		spr_coordinates(game, &sprutils);
		spr_draw(game, &sprutils, i);
		i++;
	}
}
