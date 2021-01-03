/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 12:18:57 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:06:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_last_line(t_frame *game)
{
	int	start;
	int	end;
	int	startwall;

	start = 0;
	end = ft_strlen(game->worldmap2[game->nboflines - 1]) - 1;
	startwall = -1;
	while (game->worldmap2[game->nboflines - 1][start] == ' ')
		start++;
	while (game->worldmap2[game->nboflines - 1][end] == ' ')
		end--;
	if (game->worldmap2[game->nboflines - 1][end] == '1')
		startwall = end;
	while (start <= end)
	{
		if (game->worldmap2[game->nboflines - 1][start] != '1')
		{
			ft_printf("Last line isn't closed. Exiting...\n");
			clean_exit(game);
		}
		start++;
	}
	return (startwall);
}

static int	check_last_right(int i, t_frame *game)
{
	int	j;
	int	count;

	count = 0;
	j = ft_strlen(game->worldmap2[i]) - 1;
	while (game->worldmap2[i][j] == ' ')
	{
		j--;
		count++;
	}
	if (game->worldmap2[i][j] != '1')
	{
		ft_printf("Right side of line %i isn't closed. Exiting...\n", i);
		clean_exit(game);
	}
	return (count);
}

static void	check_right_inf(t_frame *game, int i, int startwall, int nextwall)
{
	int	temp;

	if (nextwall < startwall - 1)
	{
		temp = nextwall + 1;
		while (temp < startwall)
		{
			if (game->worldmap2[i + 1][temp] != '1')
			{
				ft_printf("Map isn't closed at line %i. Exiting...\n",
					i + 1, startwall, nextwall);
				clean_exit(game);
			}
			temp++;
		}
	}
}

static void	check_right_sup(t_frame *game, int i, int startwall, int nextwall)
{
	int	temp;

	if (nextwall > startwall + 1)
	{
		temp = nextwall - 1;
		while (temp > startwall)
		{
			if (game->worldmap2[i][temp] != '1')
			{
				ft_printf("Map isn't closed at line %i. Exiting...\n",
					i, startwall, nextwall);
				clean_exit(game);
			}
			temp--;
		}
	}
}

void	check_right(t_frame *game)
{
	int	i;
	int	j;
	int	startwall;
	int	nextwall;

	i = game->nboflines - 2;
	startwall = check_last_line(game);
	nextwall = 0;
	while (i >= 0)
	{
		j = ft_strlen(game->worldmap2[i]) - 1;
		j -= check_last_right(i, game);
		nextwall = j;
		check_right_inf(game, i, startwall, nextwall);
		check_right_sup(game, i, startwall, nextwall);
		startwall = nextwall;
		i--;
	}
}
