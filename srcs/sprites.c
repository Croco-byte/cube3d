/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:17:42 by user42            #+#    #+#             */
/*   Updated: 2020/12/30 16:27:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_numsprites(t_frame *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	game->sprites.numSprites = 0;
	while (game->worldmap2[i])
	{
		j = 0;
		while (game->worldmap2[i][j])
		{
			if (game->worldmap2[i][j] == '2' || game->worldmap2[i][j] == '3'
			|| game->worldmap2[i][j] == '4' || game->worldmap2[i][j] == '5')
				game->sprites.numSprites += 1;
			j++;
		}
		i++;
	}
}

static void		malloc_arrays(t_sprites *sprites)
{
	sprites->spriteOrder = malloc((sprites->numSprites) * sizeof(int));
	sprites->spriteDist = malloc((sprites->numSprites) * sizeof(double));
	sprites->spr = malloc((sprites->numSprites) * sizeof(t_spriteLoc));
}

void			init_sprites(t_frame *game)
{
	int k;
	int i;
	int j;

	k = 0;
	i = 0;
	get_numsprites(game);
	malloc_arrays(&game->sprites);
	while (game->worldmap2[i])
	{
		j = 0;
		while (game->worldmap2[i][j])
		{
			if (game->worldmap2[i][j] == '2' || game->worldmap2[i][j] == '3'
			|| game->worldmap2[i][j] == '4' || game->worldmap2[i][j] == '5')
			{
				game->sprites.spr[k].x = i + 0.5;
				game->sprites.spr[k].y = j + 0.5;
				game->sprites.spr[k].sprTex = (int)(game->worldmap2[i][j] - 48);
				k++;
			}
			j++;
		}
		i++;
	}
}

void			sort_sprites(double *spritedist, int *spriteorder, int size)
{
	int		i;
	int		j;
	int		temp;
	double	temp2;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (spritedist[i] < spritedist[j])
			{
				temp = spriteorder[i];
				spriteorder[i] = spriteorder[j];
				spriteorder[j] = temp;
				temp2 = spritedist[i];
				spritedist[i] = spritedist[j];
				spritedist[j] = temp2;
			}
			j++;
		}
		i++;
	}
}

void			init_sprarray(t_frame *game)
{
	int i;

	i = 0;
	while (i < game->sprites.numSprites)
	{
		game->sprites.spriteOrder[i] = i;
		game->sprites.spriteDist[i] =
		((game->player.posX - game->sprites.spr[i].x) *
		(game->player.posX - game->sprites.spr[i].x) +
		(game->player.posY - game->sprites.spr[i].y) *
		(game->player.posY - game->sprites.spr[i].y));
		i++;
	}
	sort_sprites(game->sprites.spriteDist, game->sprites.spriteOrder,
	game->sprites.numSprites);
}
