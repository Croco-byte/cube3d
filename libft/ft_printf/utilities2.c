/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:14:35 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 16:54:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long	invert_negatives(long nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	init(char *base, long n, long *nbr, int *i)
{
	base = "0123456789abcdef";
	*nbr = n;
	*i = 0;
}

void	init2(char c, char *base, int *i)
{
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	*i = 0;
}
