/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:25:01 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 16:35:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*create_result(t_attr tmp, int nb_len)
{
	char	*result;

	if (tmp.width > nb_len && tmp.width > tmp.dot)
	{
		result = malloc((tmp.width + 1) *sizeof(char));
		if (!result)
			return (0);
	}
	else if (tmp.dot > nb_len && tmp.dot > tmp.width)
	{
		result = malloc((tmp.dot + 1) *sizeof(char));
		if (!result)
			return (0);
	}
	else
	{
		result = malloc((nb_len + 1) *sizeof(char));
		if (!result)
			return (0);
	}
	return (result);
}

static void	fill_right(char *nb_str, char *result, t_attr tmp, int nb_len)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (nb_str[0] == '-' && tmp.zeros == 1)
		result[i++] = '-';
	while (k < tmp.width - nb_len)
	{
		if (tmp.zeros == 0)
			result[i] = ' ';
		if (tmp.zeros == 1)
			result[i] = '0';
		i++;
		k++;
	}
	if (nb_str[0] == '-' && tmp.zeros == 1)
		ft_strlcpy(result + i, nb_str + 1, nb_len);
	else
		ft_strlcpy(result + i, nb_str, nb_len + 1);
}

static void	fill_left(char *nb_str, char *result, t_attr tmp)
{
	int	i;

	i = 0;
	while (nb_str[i])
	{
		result[i] = nb_str[i];
		i++;
	}
	while (i < tmp.width)
	{
		if (tmp.zeros == 0)
			result[i] = ' ';
		if (tmp.zeros == 1)
			result[i] = '0';
		i++;
	}
	result[i] = '\0';
}

int	handle_int(int nb, t_attr tmp)
{
	char	*result;
	char	*nb_str;
	int		nb_len;

	nb_str = ft_itoa_dot(nb, tmp);
	if (!nb_str)
		return (0);
	nb_len = (int)ft_strlen(nb_str);
	result = create_result(tmp, nb_len);
	if (!result)
		return (0);
	if (tmp.width <= nb_len)
		ft_strlcpy(result, nb_str, nb_len + 1);
	else
	{
		if (tmp.minus == 0)
			fill_right(nb_str, result, tmp, nb_len);
		if (tmp.minus == 1)
			fill_left(nb_str, result, tmp);
	}
	ft_putstr_fd(result, 1);
	nb_len = (int)ft_strlen(result);
	free(nb_str);
	free(result);
	return (nb_len);
}
