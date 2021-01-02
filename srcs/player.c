/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:36:32 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 17:01:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_north_south(t_frame *game, int i, int j)
{
	if (game->worldmap2[i][j] == 'N')
	{
		game->player.posX = i + 0.5;
		game->player.posY = j + 0.5;
		game->player.dirX = -1;
		game->player.dirY = 0;
		game->player.planeX = 0;
		game->player.planeY = 0.66;
	}
	if (game->worldmap2[i][j] == 'S')
	{
		game->player.posX = i + 0.5;
		game->player.posY = j + 0.5;
		game->player.dirX = 1;
		game->player.dirY = 0;
		game->player.planeX = 0;
		game->player.planeY = -0.66;
	}
}

void	check_west_east(t_frame *game, int i, int j)
{
	if (game->worldmap2[i][j] == 'W')
	{
		game->player.posX = i + 0.5;
		game->player.posY = j + 0.5;
		game->player.dirX = 0;
		game->player.dirY = -1;
		game->player.planeX = -0.66;
		game->player.planeY = 0;
	}
	if (game->worldmap2[i][j] == 'E')
	{
		game->player.posX = i + 0.5;
		game->player.posY = j + 0.5;
		game->player.dirX = 0;
		game->player.dirY = 1;
		game->player.planeX = 0.66;
		game->player.planeY = 0;
	}
}

void	place_player(t_frame *game)
{
	int i;
	int j;

	i = 0;
	while (game->worldmap2[i])
	{
		j = 0;
		while (game->worldmap2[i][j])
		{
			check_north_south(game, i, j);
			check_west_east(game, i, j);
			j++;
		}
		i++;
	}
}

void	init_player(t_frame *game)
{
	game->player.posX = 0;
	game->player.posY = 0;
	place_player(game);
	if (game->player.posX < 1 || game->player.posY < 1)
	{
		ft_printf("Incorrect player position. Exiting...\n");
		clean_exit(game);
	}
	game->player.moveSpeed = (double)game->screenWidth2 / 10000 +
	(double)game->screenHeight2 / 10000;
	game->player.rotSpeed = (double)game->screenWidth2 / 10000 +
	(double)game->screenHeight2 / 10000;
	game->player.moveForward = 0;
	game->player.moveBack = 0;
	game->player.moveLeft = 0;
	game->player.moveRight = 0;
	game->player.rotateLeft = 0;
	game->player.rotateRight = 0;
}

int		can_move(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == ' ')
		return (1);
	return (0);
}

void	move_forward(t_frame *game)
{
	char next_box;

	next_box = game->worldmap2
	[(int)(game->player.posX + game->player.dirX * game->player.moveSpeed)]
	[(int)game->player.posY];
	if (can_move(next_box))
		game->player.posX += game->player.dirX * game->player.moveSpeed;
	next_box = game->worldmap2
	[(int)game->player.posX]
	[(int)(game->player.posY + game->player.dirY * game->player.moveSpeed)];
	if (can_move(next_box))
		game->player.posY += game->player.dirY * game->player.moveSpeed;
}

void	move_back(t_frame *game)
{
	char next_box;

	next_box = game->worldmap2
	[(int)(game->player.posX - game->player.dirX * game->player.moveSpeed)]
	[(int)game->player.posY];
	if (can_move(next_box))
		game->player.posX -= game->player.dirX * game->player.moveSpeed;
	next_box = game->worldmap2
	[(int)game->player.posX]
	[(int)(game->player.posY - game->player.dirY * game->player.moveSpeed)];
	if (can_move(next_box))
		game->player.posY -= game->player.dirY * game->player.moveSpeed;
}

void	move_right(t_frame *game)
{
	char next_box;

	next_box = game->worldmap2
	[(int)(game->player.posX + game->player.planeX * game->player.moveSpeed)]
	[(int)game->player.posY];
	if (can_move(next_box))
		game->player.posX += game->player.planeX * game->player.moveSpeed;
	next_box = game->worldmap2
	[(int)game->player.posX]
	[(int)(game->player.posY + game->player.planeY * game->player.moveSpeed)];
	if (can_move(next_box))
		game->player.posY += game->player.planeY * game->player.moveSpeed;
}

void	move_left(t_frame *game)
{
	char next_box;

	next_box = game->worldmap2
	[(int)(game->player.posX - game->player.planeX * game->player.moveSpeed)]
	[(int)game->player.posY];
	if (can_move(next_box))
		game->player.posX -= game->player.planeX * game->player.moveSpeed;
	next_box = game->worldmap2
	[(int)game->player.posX]
	[(int)(game->player.posY - game->player.planeY * game->player.moveSpeed)];
	if (can_move(next_box))
		game->player.posY -= game->player.planeY * game->player.moveSpeed;
}
