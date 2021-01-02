/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:54:38 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 14:09:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	allocate_buffers(t_frame *game)
{
	int y;

	y = 0;
	if (!(game->buffer = malloc(game->screenHeight2 * sizeof(int *))))
		return ;
	while (y < game->screenHeight2)
	{
		if (!(game->buffer[y] = malloc(game->screenWidth2 * sizeof(int))))
			return ;
		y++;
	}
	if (!(game->ZBuffer = malloc(game->screenWidth2 * sizeof(double))))
		return ;
}

void	init_buffer(t_frame *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->screenHeight2 / 2)
	{
		x = 0;
		while (x < game->screenWidth2)
			game->buffer[y][x++] = game->ceiling;
		y++;
	}
	while (y < game->screenHeight2)
	{
		x = 0;
		while (x < game->screenWidth2)
			game->buffer[y][x++] = game->floor;
		y++;
	}
}

void	handle_movements(t_frame *game)
{
	if (game->player.moveForward)
		move_forward(game);
	if (game->player.moveBack)
		move_back(game);
	if (game->player.moveLeft)
		move_left(game);
	if (game->player.moveRight)
		move_right(game);
	if (game->player.rotateLeft)
		rotate_left(game);
	if (game->player.rotateRight)
		rotate_right(game);
}

void	do_walls(t_frame *game)
{
	t_raycast	raycaster;
	int			x;

	x = 0;
	while (x < game->screenWidth2)
	{
		init_raycast(game, &raycaster, x);
		dda_preparations(game, &raycaster);
		dda_perform(game, &raycaster);
		calc_draw_coordinates(game, &raycaster);
		calc_texture_coordinates(game, &raycaster);
		draw_stripe_in_buffer(game, &raycaster, x);
		game->ZBuffer[x] = raycaster.perpWallDist;
		x++;
	}
}

void	do_sprites(t_frame *game)
{
	int			i;
	t_sprutils	sprutils;

	i = 0;
	init_sprarray(game);
	while (i < game->sprites.numSprites)
	{
		init_sprutils(game, &sprutils, i);
		spr_coordinates(game, &sprutils);
		spr_draw(game, &sprutils, i);
		i++;
	}
}
