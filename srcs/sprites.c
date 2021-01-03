/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:17:42 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:44:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_numsprites(t_frame *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->sprites.numsprites = 0;
	while (game->worldmap2[i])
	{
		j = 0;
		while (game->worldmap2[i][j])
		{
			if (game->worldmap2[i][j] == '2' || game->worldmap2[i][j] == '3'
				|| game->worldmap2[i][j] == '4' || game->worldmap2[i][j] == '5')
				game->sprites.numsprites += 1;
			j++;
		}
		i++;
	}
}

static void	malloc_arrays(t_sprites *sprites)
{
	sprites->spriteorder = malloc((sprites->numsprites) *sizeof(int));
	if (!sprites->spriteorder)
		return ;
	sprites->spritedist = malloc((sprites->numsprites) *sizeof(double));
	if (!sprites->spritedist)
		return ;
	sprites->spr = malloc((sprites->numsprites) *sizeof(t_spriteloc));
	if (!sprites->spr)
		return ;
}

void	init_sprites(t_frame *game)
{
	int	k;
	int	i;
	int	j;

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
				game->sprites.spr[k].sprtex = (int)(game->worldmap2[i][j] - 48);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites(double *spritedist, int *spriteorder, int size)
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

void	init_sprarray(t_frame *game)
{
	int	i;

	i = 0;
	while (i < game->sprites.numsprites)
	{
		game->sprites.spriteorder[i] = i;
		game->sprites.spritedist[i] = ((game->player.posx - game->sprites.spr[i].x)
				*(game->player.posx - game->sprites.spr[i].x)
				+ (game->player.posy - game->sprites.spr[i].y)
				* (game->player.posy - game->sprites.spr[i].y));
		i++;
	}
	sort_sprites(game->sprites.spritedist, game->sprites.spriteorder,
	game->sprites.numsprites);
}
