/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:40:21 by akrache           #+#    #+#             */
/*   Updated: 2019/11/02 20:47:24 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rborrrb(t_stack **b, int x, int nb)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *b;
	while (i < nb && tmp)
	{
		if (tmp->data == x)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i <= nb / 2 ? true : false);
}

static bool	raorrra(t_stack **a, int x, int nb)
{
	int		i;
	int		j;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (i < nb && tmp)
	{
		if (tmp->data <= x)
			break ;
		tmp = tmp->next;
		i++;
	}
	j = 0;
	tmp = (*a)->last;
	while (j < nb && tmp)
	{
		if (tmp->data <= x)
			break ;
		tmp = tmp->prev;
		j++;
	}
	return (i <= j ? true : false);
}

static int	algo3(t_stack **a, t_stack **b, int len_b)
{
	while (!are_sorted(a, b))
	{
		if ((*b)->data == (*a)->data - 1)
		{
			op_write(a, b, PA);
			len_b--;
		}
		else if (rborrrb(b, (*a)->data - 1, len_b))
			op_write(a, b, RB);
		else
			op_write(a, b, RRB);
		if (!(*b))
			break ;
	}
	return (len_b);
}

static int	algo2(t_stack **a, t_stack **b, int *tab, double mod)
{
	while ((*a)->next)
	{
		if ((*a)->data != tab[0] - 1)
		{
			op_write(a, b, PB);
			tab[1]++;
		}
		else if (raorrra(a, mod, tab[0] - tab[1]))
			op_write(a, b, RA);
		else
			op_write(a, b, RRA);
	}
	return (tab[1]);
}

void		push_swap(t_stack **a, t_stack **b, int nb)
{
	int			len_b;
	double		mod;

	len_b = 0;
	mod = nb / 8.0;
	while (mod < nb && (*a)->next)
	{
		while (len_b <= mod)
		{
			if ((*a)->data <= mod)
			{
				op_write(a, b, PB);
				len_b++;
			}
			else if (raorrra(a, mod, nb - len_b))
				op_write(a, b, RA);
			else
				op_write(a, b, RRA);
		}
		mod += nb / 8.0;
	}
	len_b = algo2(a, b, (int[2]){nb, len_b}, mod);
	len_b = algo3(a, b, len_b);
}
