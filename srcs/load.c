/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:52:27 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:02:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	load_textures1(t_frame *game, t_textures *textures)
{
	textures->north.img = mlx_xpm_file_to_image(game->mlx,
			game->paths.nopath, &(textures->texwidth), &(textures->texheight));
	if (!textures->north.img)
	{
		ft_printf("Couldn't load north texture. Exiting...\n");
		clean_exit(game);
	}
	textures->north.addr = mlx_get_data_addr(textures->north.img,
			&textures->north.bits_per_pixel, &textures->north.line_length,
			&textures->north.endian);
	textures->northtex = (int *)textures->north.addr;
	textures->south.img = mlx_xpm_file_to_image(game->mlx,
			game->paths.sopath, &(textures->texwidth), &(textures->texheight));
	if (!textures->south.img)
	{
		ft_printf("Couldn't load south texture. Exiting...\n");
		clean_exit(game);
	}
	textures->south.addr = mlx_get_data_addr(textures->south.img,
			&textures->south.bits_per_pixel, &textures->south.line_length,
			&textures->south.endian);
	textures->southtex = (int *)textures->south.addr;
}

static void	load_textures2(t_frame *game, t_textures *textures)
{
	textures->west.img = mlx_xpm_file_to_image(game->mlx,
			game->paths.wepath, &(textures->texwidth), &(textures->texheight));
	if (!textures->west.img)
	{
		ft_printf("Couldn't load west texture. Exiting...\n");
		clean_exit(game);
	}
	textures->west.addr = mlx_get_data_addr(textures->west.img,
			&textures->west.bits_per_pixel, &textures->west.line_length,
			&textures->west.endian);
	textures->westtex = (int *)textures->west.addr;
	textures->east.img = mlx_xpm_file_to_image(game->mlx,
			game->paths.eapath, &(textures->texwidth), &(textures->texheight));
	if (!textures->east.img)
	{
		ft_printf("Couldn't load east texture. Exiting...\n");
		clean_exit(game);
	}
	textures->east.addr = mlx_get_data_addr(textures->east.img,
			&textures->east.bits_per_pixel, &textures->east.line_length,
			&textures->east.endian);
	textures->easttex = (int *)textures->east.addr;
}

static void	load_sprites1(t_frame *game, t_sprites *sprites)
{
	sprites->sprite1.img = mlx_xpm_file_to_image(game->mlx,
			game->paths.spath, &(sprites->texwidth), &(sprites->texheight));
	if (!sprites->sprite1.img)
	{
		ft_printf("Couldn't load main sprite. Exiting...\n");
		clean_exit(game);
	}
	sprites->sprite1.addr = mlx_get_data_addr(sprites->sprite1.img,
			&sprites->sprite1.bits_per_pixel, &sprites->sprite1.line_length,
			&sprites->sprite1.endian);
	sprites->sprite1tex = (int *)sprites->sprite1.addr;
	sprites->sprite2.img = mlx_xpm_file_to_image(game->mlx,
			game->paths.s2path, &(sprites->texwidth), &(sprites->texheight));
	if (!sprites->sprite2.img)
	{
		ft_printf("Couldn't load sprite 2. Exiting...\n");
		clean_exit(game);
	}
	sprites->sprite2.addr = mlx_get_data_addr(sprites->sprite2.img,
			&sprites->sprite2.bits_per_pixel, &sprites->sprite2.line_length,
			&sprites->sprite2.endian);
	sprites->sprite2tex = (int *)sprites->sprite2.addr;
}

static void	load_sprites2(t_frame *game, t_sprites *sprites)
{
	sprites->sprite3.img = mlx_xpm_file_to_image(game->mlx,
			game->paths.s3path, &(sprites->texwidth), &(sprites->texheight));
	if (!sprites->sprite3.img)
	{
		ft_printf("Couldn't load sprite 3. Exiting...\n");
		clean_exit(game);
	}
	sprites->sprite3.addr = mlx_get_data_addr(sprites->sprite3.img,
			&sprites->sprite3.bits_per_pixel, &sprites->sprite3.line_length,
			&sprites->sprite3.endian);
	sprites->sprite3tex = (int *)sprites->sprite3.addr;
	sprites->sprite4.img = mlx_xpm_file_to_image(game->mlx,
			game->paths.s4path, &(sprites->texwidth), &(sprites->texheight));
	if (!sprites->sprite4.img)
	{
		ft_printf("Couldn't load sprite 4. Exiting...\n");
		clean_exit(game);
	}
	sprites->sprite4.addr = mlx_get_data_addr(sprites->sprite4.img,
			&sprites->sprite4.bits_per_pixel, &sprites->sprite4.line_length,
			&sprites->sprite4.endian);
	sprites->sprite4tex = (int *)sprites->sprite4.addr;
}

void	load(t_frame *game, t_textures *textures, t_sprites *sprites)
{
	load_textures1(game, textures);
	load_textures2(game, textures);
	load_sprites1(game, sprites);
	load_sprites2(game, sprites);
}
