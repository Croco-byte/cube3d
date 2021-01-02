/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 17:15:38 by user42            #+#    #+#             */
/*   Updated: 2020/12/27 13:13:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	event_handler(t_frame *game)
{
	mlx_hook(game->win, 33, 0, &clean_exit, game);
	mlx_hook(game->win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->win, 3, 1L << 1, &key_release, game);
}

int		key_press(int keycode, t_frame *game)
{
	if (keycode == ESC_KEY)
		clean_exit(game);
	if (keycode == Z_KEY)
		game->player.moveForward = 1;
	if (keycode == S_KEY)
		game->player.moveBack = 1;
	if (keycode == D_KEY)
		game->player.moveRight = 1;
	if (keycode == Q_KEY)
		game->player.moveLeft = 1;
	if (keycode == A_KEY)
		game->player.rotateLeft = 1;
	if (keycode == E_KEY)
		game->player.rotateRight = 1;
	return (0);
}

int		key_release(int keycode, t_frame *game)
{
	if (keycode == Z_KEY)
		game->player.moveForward = 0;
	if (keycode == S_KEY)
		game->player.moveBack = 0;
	if (keycode == Q_KEY)
		game->player.moveLeft = 0;
	if (keycode == D_KEY)
		game->player.moveRight = 0;
	if (keycode == A_KEY)
		game->player.rotateLeft = 0;
	if (keycode == E_KEY)
		game->player.rotateRight = 0;
	return (0);
}
