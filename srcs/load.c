/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:52:27 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 17:01:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_textures1(t_frame *game, t_textures *textures)
{
	textures->north.img = mlx_xpm_file_to_image(game->mlx,
	game->paths.nopath, &(textures->texWidth), &(textures->texHeight));
	if (!textures->north.img)
	{
		ft_printf("Couldn't load north texture. Exiting...\n");
		clean_exit(game);
	}
	textures->north.addr = mlx_get_data_addr(textures->north.img,
	&textures->north.bits_per_pixel, &textures->north.line_length,
	&textures->north.endian);
	textures->northTex = (int *)textures->north.addr;
	textures->south.img = mlx_xpm_file_to_image(game->mlx,
	game->paths.sopath, &(textures->texWidth), &(textures->texHeight));
	if (!textures->south.img)
	{
		ft_printf("Couldn't load south texture. Exiting...\n");
		clean_exit(game);
	}
	textures->south.addr = mlx_get_data_addr(textures->south.img,
	&textures->south.bits_per_pixel, &textures->south.line_length,
	&textures->south.endian);
	textures->southTex = (int *)textures->south.addr;
}

static void	load_textures2(t_frame *game, t_textures *textures)
{
	textures->west.img = mlx_xpm_file_to_image(game->mlx,
	game->paths.wepath, &(textures->texWidth), &(textures->texHeight));
	if (!textures->west.img)
	{
		ft_printf("Couldn't load west texture. Exiting...\n");
		clean_exit(game);
	}
	textures->west.addr = mlx_get_data_addr(textures->west.img,
	&textures->west.bits_per_pixel, &textures->west.line_length,
	&textures->west.endian);
	textures->westTex = (int *)textures->west.addr;
	textures->east.img = mlx_xpm_file_to_image(game->mlx,
	game->paths.eapath, &(textures->texWidth), &(textures->texHeight));
	if (!textures->east.img)
	{
		ft_printf("Couldn't load east texture. Exiting...\n");
		clean_exit(game);
	}
	textures->east.addr = mlx_get_data_addr(textures->east.img,
	&textures->east.bits_per_pixel, &textures->east.line_length,
	&textures->east.endian);
	textures->eastTex = (int *)textures->east.addr;
}

static void	load_sprites1(t_frame *game, t_sprites *sprites)
{
	sprites->sprite1.img = mlx_xpm_file_to_image(game->mlx,
	game->paths.spath, &(sprites->texWidth), &(sprites->texHeight));
	if (!sprites->sprite1.img)
	{
		ft_printf("Couldn't load main sprite. Exiting...\n");
		clean_exit(game);
	}
	sprites->sprite1.addr = mlx_get_data_addr(sprites->sprite1.img,
	&sprites->sprite1.bits_per_pixel, &sprites->sprite1.line_length,
	&sprites->sprite1.endian);
	sprites->sprite1Tex = (int *)sprites->sprite1.addr;
	sprites->sprite2.img = mlx_xpm_file_to_image(game->mlx,
	game->paths.s2path, &(sprites->texWidth), &(sprites->texHeight));
	if (!sprites->sprite2.img)
	{
		ft_printf("Couldn't load sprite 2. Exiting...\n");
		clean_exit(game);
	}
	sprites->sprite2.addr = mlx_get_data_addr(sprites->sprite2.img,
	&sprites->sprite2.bits_per_pixel, &sprites->sprite2.line_length,
	&sprites->sprite2.endian);
	sprites->sprite2Tex = (int *)sprites->sprite2.addr;
}

static void	load_sprites2(t_frame *game, t_sprites *sprites)
{
	sprites->sprite3.img = mlx_xpm_file_to_image(game->mlx,
	game->paths.s3path, &(sprites->texWidth), &(sprites->texHeight));
	if (!sprites->sprite3.img)
	{
		ft_printf("Couldn't load sprite 3. Exiting...\n");
		clean_exit(game);
	}
	sprites->sprite3.addr = mlx_get_data_addr(sprites->sprite3.img,
	&sprites->sprite3.bits_per_pixel, &sprites->sprite3.line_length,
	&sprites->sprite3.endian);
	sprites->sprite3Tex = (int *)sprites->sprite3.addr;
	sprites->sprite4.img = mlx_xpm_file_to_image(game->mlx,
	game->paths.s4path, &(sprites->texWidth), &(sprites->texHeight));
	if (!sprites->sprite4.img)
	{
		ft_printf("Couldn't load sprite 4. Exiting...\n");
		clean_exit(game);
	}
	sprites->sprite4.addr = mlx_get_data_addr(sprites->sprite4.img,
	&sprites->sprite4.bits_per_pixel, &sprites->sprite4.line_length,
	&sprites->sprite4.endian);
	sprites->sprite4Tex = (int *)sprites->sprite4.addr;
}

void		load(t_frame *game, t_textures *textures, t_sprites *sprites)
{
	load_textures1(game, textures);
	load_textures2(game, textures);
	load_sprites1(game, sprites);
	load_sprites2(game, sprites);
}
