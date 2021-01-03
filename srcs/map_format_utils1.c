/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:16:19 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:06:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_first_line(t_frame *game)
{
	int	start;
	int	end;
	int	startwall;

	start = 0;
	end = ft_strlen(game->worldmap2[0]) - 1;
	startwall = -1;
	while (game->worldmap2[0][start] == ' ')
		start++;
	while (game->worldmap2[0][end] == ' ')
		end--;
	if (game->worldmap2[0][start] == '1')
		startwall = start;
	while (start <= end)
	{
		if (game->worldmap2[0][start] != '1')
		{
			ft_printf("First line isn't closed. Exiting...\n");
			clean_exit(game);
		}
		start++;
	}
	return (startwall);
}

static int	check_first_left(int i, t_frame *game)
{
	int	j;

	j = 0;
	while (game->worldmap2[i][j] == ' ')
		j++;
	if (game->worldmap2[i][j] != '1')
	{
		ft_printf("Left side of line %i isn't closed. Exiting...\n", i);
		clean_exit(game);
	}
	return (j);
}

static void	check_left_inf(t_frame *game, int i, int startwall, int nextwall)
{
	int	temp;

	if (nextwall < startwall - 1)
	{
		temp = nextwall;
		while (temp < startwall)
		{
			if (game->worldmap2[i][temp] != '1')
			{
				ft_printf("Map isn't closed at line %i. Exiting...\n",
					i, startwall, nextwall);
				clean_exit(game);
			}
			temp++;
		}
	}
}

static void	check_left_sup(t_frame *game, int i, int startwall, int nextwall)
{
	int	temp;

	if (nextwall > startwall + 1)
	{
		temp = nextwall - 1;
		while (temp > startwall)
		{
			if (game->worldmap2[i - 1][temp] != '1')
			{
				ft_printf("Map isn't closed at line %i. Exiting...\n",
					i - 1, startwall, nextwall);
				clean_exit(game);
			}
			temp--;
		}
	}
}

void	check_left(t_frame *game)
{
	int	i;
	int	j;
	int	startwall;
	int	nextwall;

	i = 1;
	j = 0;
	startwall = check_first_line(game);
	nextwall = 0;
	while (game->worldmap2[i])
	{
		j = 0;
		j += check_first_left(i, game);
		nextwall = j;
		check_left_inf(game, i, startwall, nextwall);
		check_left_sup(game, i, startwall, nextwall);
		startwall = nextwall;
		i++;
	}
}
