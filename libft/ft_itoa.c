/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:45:14 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 14:37:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		result_size(int n)
{
	int count;

	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char		*case_of_zero(void)
{
	char *result;

	if (!(result = malloc(2 * sizeof(char))))
		return (0);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static void		reverse_result(char *result)
{
	int		i;
	int		j;
	char	temp;

	i = (result[0] == '-') ? 1 : 0;
	j = ft_strlen(result) - 1;
	while (i < j)
	{
		temp = result[i];
		result[i] = result[j];
		result[j] = temp;
		i++;
		j--;
	}
}

char			*ft_itoa(int n)
{
	long	nbr;
	int		i;
	char	*result;

	nbr = (long)n;
	i = 0;
	if (n == 0)
		return (case_of_zero());
	if (!(result = malloc((result_size(n) + 1) * sizeof(char))))
		return (0);
	if (nbr < 0)
	{
		nbr *= -1;
		result[i++] = '-';
	}
	while (nbr)
	{
		result[i] = (nbr % 10) + 48;
		nbr /= 10;
		i++;
	}
	result[i] = '\0';
	reverse_result(result);
	return (result);
}
