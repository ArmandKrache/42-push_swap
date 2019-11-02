/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:17:46 by akrache           #+#    #+#             */
/*   Updated: 2019/09/26 14:27:08 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_nb_words(char const *s, char c)
{
	int	i;
	int	nb;
	int	j;

	if (!s)
		return (0);
	j = ft_strlen(s) - 1;
	nb = 0;
	i = 0;
	while ((s[j] == c && j >= 0))
		j--;
	while (i <= j)
	{
		while ((s[i] == c && s[i] != '\0'))
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		nb++;
	}
	return (nb);
}

static	int	ft_nwl(char const *s, int index, char c)
{
	int res;

	res = 1;
	while (s[index] != c && s[index])
	{
		res++;
		index++;
	}
	return (res);
}

void		*ft_splitfree(char **res, int s)
{
	int i;

	i = -1;
	if (s == -1)
	{
		while (res[++i])
			free(res[i]);
	}
	else
	{
		while (++i < s)
			free(res[i]);
	}
	if (res)
		free(res);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		h;

	if (!(res = (char **)malloc((ft_nb_words(s, c) + 1) * sizeof(char*))) || !s)
		return (NULL);
	h = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c && s[i]))
			i++;
		if (!(res[h] = (char *)malloc(ft_nwl(s, i, c) * sizeof(char) + 1)))
			return (ft_splitfree(res, h - 1));
		j = 0;
		while (s[i] != c && s[i])
			res[h][j++] = s[i++];
		res[h++][j] = '\0';
	}
	res[ft_nb_words(s, c)] = 0;
	return (res);
}
