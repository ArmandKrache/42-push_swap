/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:55:27 by akrache           #+#    #+#             */
/*   Updated: 2019/09/25 20:14:24 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long		get_param(char *str)
{
	int		i;
	long	res;
	bool	negative;

	if ((str[0] < 48 || str[0] > 57) && str[0] != '-')
		return (TOO_BIG);
	negative = (str[0] == '-') ? true : false;
	res = negative ? 0 : str[0] - '0';
	i = 1;
	while (str[i] && i <= 11)
	{
		if (str[i] < 48 || str[i] > 57)
			return (TOO_BIG);
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (res == TOO_BIG || (str[i] && i > 10) || res > INT_MAX
		|| (negative && res == 2147483648))
		return (TOO_BIG);
	return (negative ? res * -1 : res);
}

static int		multi_param(t_stack **a, char *arg)
{
	int				i;
	long			data;
	char			**tab;
	unsigned int	cpt;

	cpt = 0;
	if (!(tab = ft_strsplit(arg, ' ')))
		return (-1);
	i = 0;
	while (tab[i])
		i++;
	while (--i >= 0)
	{
		if ((data = get_param(tab[i])) == TOO_BIG || check_double(*a, data)
			|| !add(a, (int)data))
			break ;
		cpt++;
	}
	if (i >= 0 && !ft_splitfree(tab, -1))
		return (-1);
	ft_splitfree(tab, -1);
	return (cpt);
}

unsigned int	build_stack(t_stack **a, int i, char **arg)
{
	int				r;
	long			data;
	unsigned int	cpt;

	cpt = 0;
	while (i > 0)
	{
		r = 1;
		if (arg[i][0] == '\0')
			r = 0;
		else if (ft_strchr(arg[i], ' '))
		{
			if ((r = multi_param(a, arg[i])) == -1)
				return (error_msg(0));
		}
		else if ((data = get_param(arg[i])) == TOO_BIG || check_double(*a, data)
			|| !add(a, (int)data))
			break ;
		cpt += r;
		i--;
	}
	if (i > 0)
		return (error_msg(0));
	return (cpt);
}
