/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:49:40 by user42            #+#    #+#             */
/*   Updated: 2020/11/21 15:45:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**realloc_tab(char **tab, char *str)
{
	char	**nouveau_tab;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if ((nouveau_tab = malloc(sizeof(char*) * (i + 1 + 1))) == 0)
		return (0);
	i = 0;
	while (tab[i])
	{
		nouveau_tab[i] = tab[i];
		i++;
	}
	free(tab);
	nouveau_tab[i] = str;
	nouveau_tab[i + 1] = 0;
	return (nouveau_tab);
}

static void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*extract_word(const char *s, char c, size_t *index)
{
	size_t	j;
	char	*str;

	j = 0;
	while (s[*index + j] && s[*index + j] != c)
		j++;
	if ((str = (char *)malloc(sizeof(char) * (j + 1))) == 0)
		return (0);
	j = 0;
	while (s[*index + j] && s[*index + j] != c)
	{
		str[j] = s[*index + j];
		j++;
	}
	str[j] = 0;
	*index += j;
	return (str);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if ((tab = (char **)malloc(sizeof(char *) * 1)) == 0)
		return (0);
	tab[0] = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if ((str = extract_word(s, c, &i)) == 0)
			{
				free_tab(tab);
				return (0);
			}
			tab = realloc_tab(tab, str);
		}
	}
	return (tab);
}
