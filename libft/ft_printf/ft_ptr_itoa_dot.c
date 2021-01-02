/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_itoa_dot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 11:39:44 by user42            #+#    #+#             */
/*   Updated: 2020/12/10 13:14:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		result_size(long n, t_attr tmp)
{
	int count;

	count = itoa_size_base(n, 16);
	if (tmp.dot > count)
		count += (tmp.dot - count);
	if (n < 0)
		count++;
	return (count);
}

static char		*case_of_zero(void)
{
	char	*result;

	if (!(result = malloc(4 * sizeof(char))))
		return (0);
	ft_strlcpy(result, "0x0", 4);
	return (result);
}

static void		reverse_result(char *result)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
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

char			*ft_ptr_itoa_dot(long n, t_attr tmp)
{
	long	nbr;
	int		i;
	char	*result;
	char	*base;

	base = "0123456789abcdef";
	nbr = n;
	i = 0;
	if (n == 0)
		return (case_of_zero());
	if (!(result = malloc((result_size(n, tmp) + 1 + 2) * sizeof(char))))
		return (0);
	nbr = (nbr < 0) ? nbr * -1 : nbr;
	while (nbr)
	{
		result[i++] = base[nbr % 16];
		nbr /= 16;
	}
	if (n < 0)
		result[i++] = '-';
	result[i++] = 'x';
	result[i++] = '0';
	result[i] = '\0';
	reverse_result(result);
	return (result);
}
