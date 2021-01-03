/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:29:36 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:43:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_paths(t_frame *game)
{
	game->paths.nopath = 0;
	game->paths.sopath = 0;
	game->paths.wepath = 0;
	game->paths.eapath = 0;
	game->paths.spath = 0;
	game->paths.s2path = 0;
	game->paths.s3path = 0;
	game->paths.s4path = 0;
}

void	init_game(t_frame *game)
{
	game->screenwidth = 0;
	game->screenheight = 0;
	game->ceiling = 0;
	game->floor = 0;
	game->buffer = 0;
	game->worldmap2 = 0;
	game->zbuffer = 0;
	game->win = 0;
	init_paths(game);
	game->textures.north.img = 0;
	game->textures.south.img = 0;
	game->textures.east.img = 0;
	game->textures.west.img = 0;
	game->sprites.sprite1.img = 0;
	game->sprites.sprite2.img = 0;
	game->sprites.sprite3.img = 0;
	game->sprites.sprite4.img = 0;
	game->sprites.spriteorder = 0;
	game->sprites.spritedist = 0;
	game->sprites.spr = 0;
}

int	clean_exit(t_frame *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_game_buffer(game);
	free_game_worldmap(game);
	free_textures_images(game);
	free_sprites_images(game);
	free(game->zbuffer);
	free(game->paths.nopath);
	free(game->paths.sopath);
	free(game->paths.wepath);
	free(game->paths.eapath);
	free(game->paths.spath);
	free(game->paths.s2path);
	free(game->paths.s3path);
	free(game->paths.s4path);
	free(game->sprites.spriteorder);
	free(game->sprites.spritedist);
	free(game->sprites.spr);
	exit(0);
}

void	draw_in_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_buffer_in_image(t_frame *game, t_img *render)
{
	int	z;
	int	y;

	z = 0;
	while (z < game->screenheight)
	{
		y = 0;
		while (y < game->screenwidth)
		{
			draw_in_image(render, y, z, game->buffer[z][y]);
			y++;
		}
		z++;
	}
}
