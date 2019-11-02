/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:10:42 by akrache           #+#    #+#             */
/*   Updated: 2019/10/05 17:10:01 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	get_op(char *s)
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\0')
		return (SA);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\0')
		return (SB);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\0')
		return (SS);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\0')
		return (PA);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\0')
		return (PB);
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\0')
		return (RA);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\0')
		return (RB);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\0')
		return (RR);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\0')
		return (RRA);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\0')
		return (RRB);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\0')
		return (RRR);
	return (0);
}

static int	ops_realloc(char **ops, unsigned int size, unsigned int i)
{
	char	*tmp;
	char	*fr;
	char	t;

	fr = *ops;
	if (!(tmp = (char *)malloc(sizeof(char) * size)))
		return (0);
	t = (*ops)[i];
	(*ops)[i] = '\0';
	ft_strcpy(tmp, *ops);
	tmp[i] = t;
	*ops = tmp;
	free(fr);
	return (1);
}

static int	nb_op(char *str)
{
	unsigned int	i;
	int				cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			cpt++;
		i++;
	}
	cpt++;
	return (cpt);
}

char		*parse_ops(char *str)
{
	char				*ops;
	unsigned int		i;
	unsigned int		cpt;
	char				buf[4];
	int					j;

	i = -1;
	if (!(ops = (char *)malloc(sizeof(char) * (nb_op(str)))))
		return (NULL);
	cpt = 0;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\n' && (buf[j] = '\0') == '\0')
		{
			if ((ops[cpt++] = get_op(buf)) == 0)
				return (ft_freeptr(ops));
			j = 0;
		}
		else
			buf[j++] = str[i];
		if (j == 4)
			return (ft_freeptr(ops));
	}
	return ((ops[cpt] = '\0') == '\0' && j != 0 ? ft_freeptr(ops) : ops);
}

char		*parsing(void)
{
	int				r;
	char			*buf;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = 4096;
	if (!(buf = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while ((r = read(0, buf + i, 1) == 1))
	{
		if (i == size - 1)
		{
			size *= 2;
			if (!ops_realloc(&buf, size, i))
				return (ft_freeptr(buf));
		}
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
