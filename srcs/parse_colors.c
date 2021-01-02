/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:39:19 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 16:57:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color(char *line, int *i)
{
	int color;

	color = 0;
	while (line[*i] && ft_isdigit(line[*i]))
	{
		color *= 10;
		color += line[*i] - 48;
		*i = (*i) + 1;
	}
	return (color);
}

int			parse_color(char *line, int i)
{
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	i++;
	i += pass_spaces(line, i);
	r = get_color(line, &i);
	if (line[i])
		i++;
	g = get_color(line, &i);
	if (line[i])
		i++;
	b = get_color(line, &i);
	return (rgb_to_int(0, r, g, b));
}
