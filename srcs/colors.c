/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:40:06 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 13:32:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	trgb_to_values(int trgb, char c)
{
	if (c == 't')
		return ((trgb & (0xFF << 24)) >> 24);
	if (c == 'r')
		return ((trgb & (0xFF << 16)) >> 16);
	if (c == 'g')
		return ((trgb & (0xFF << 8)) >> 8);
	if (c == 'b')
		return (trgb & 0xFF);
	return (0);
}
