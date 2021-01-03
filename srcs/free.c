/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:53:28 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 13:32:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game_buffer(t_frame *game)
{
	int	i;

	i = 0;
	if (!game->buffer)
		return ;
	while (i < game->screenheight)
	{
		free(game->buffer[i]);
		i++;
	}
	free(game->buffer);
}

void	free_game_worldmap(t_frame *game)
{
	int	i;

	i = 0;
	if (!game->worldmap2)
		return ;
	while (game->worldmap2[i])
	{
		free(game->worldmap2[i]);
		i++;
	}
	free(game->worldmap2);
}

void	free_textures_images(t_frame *game)
{
	if (game->textures.north.img != 0)
		mlx_destroy_image(game->mlx, game->textures.north.img);
	if (game->textures.south.img != 0)
		mlx_destroy_image(game->mlx, game->textures.south.img);
	if (game->textures.west.img != 0)
		mlx_destroy_image(game->mlx, game->textures.west.img);
	if (game->textures.east.img != 0)
		mlx_destroy_image(game->mlx, game->textures.east.img);
}

void	free_sprites_images(t_frame *game)
{
	if (game->sprites.sprite1.img != 0)
		mlx_destroy_image(game->mlx, game->sprites.sprite1.img);
	if (game->sprites.sprite2.img != 0)
		mlx_destroy_image(game->mlx, game->sprites.sprite2.img);
	if (game->sprites.sprite3.img != 0)
		mlx_destroy_image(game->mlx, game->sprites.sprite3.img);
	if (game->sprites.sprite4.img != 0)
		mlx_destroy_image(game->mlx, game->sprites.sprite4.img);
}
