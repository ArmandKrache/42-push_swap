/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:24:33 by akrache           #+#    #+#             */
/*   Updated: 2019/10/07 11:10:13 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stack **a, t_stack **b, int start)
{
	if ((*a)->data == start && (*a)->next->data == start + 2)
	{
		op_write(a, b, SA);
		op_write(a, b, RA);
	}
	else if ((*a)->data == start + 2 && (*a)->next->data == start)
		op_write(a, b, RA);
	else if ((*a)->data == start + 1 && (*a)->next->data == start + 2)
		op_write(a, b, RRA);
	else if ((*a)->data == start + 1 && (*a)->next->data == start)
		op_write(a, b, SA);
	else if ((*a)->data == start + 2 && (*a)->next->data == start + 1)
	{
		op_write(a, b, RA);
		op_write(a, b, SA);
	}
}

static void	five_push_swap(t_stack **a, t_stack **b, int start)
{
	int r;

	if ((*a)->data == start)
	{
		op_write(a, b, PB);
		four_push_swap(a, b, start + 1);
	}
	else
	{
		if ((r = closest_rarra(a, start)) <= 2)
			op_write(a, b, RA);
		if (r == 2)
			op_write(a, b, RA);
		else if (r > 2 && r <= 4)
			op_write(a, b, RRA);
		if (r == 4)
			op_write(a, b, RRA);
		op_write(a, b, PB);
		four_push_swap(a, b, start + 1);
	}
	op_write(a, b, PA);
}

static void	ten_bis(t_stack **a, t_stack **b, int nb, int len_b)
{
	if (len_b == 4)
	{
		if (!inv_sorted(b))
			four_inv_push_swap(a, b, len_b - 1);
		nb == 8 && !are_sorted(a, b) ? four_push_swap(a, b, 4)
			: five_push_swap(a, b, 4);
		while (len_b--)
			op_write(a, b, PA);
	}
	else
	{
		if (!inv_sorted(b))
			five_inv_push_swap(a, b, len_b - 1);
		if (!are_sorted(a, b))
			five_push_swap(a, b, 5);
		while (len_b--)
			op_write(a, b, PA);
	}
}

void		ten_push_swap(t_stack **a, t_stack **b, int nb)
{
	int len_b;

	len_b = 0;
	while (len_b < nb / 2)
	{
		if ((*a)->data < nb / 2)
		{
			op_write(a, b, PB);
			len_b++;
		}
		else
			op_write(a, b, RA);
	}
	if (len_b == 3)
	{
		if (!inv_sorted(b))
			three_inv_sort(a, b, len_b - 1);
		nb == 6 && !are_sorted(a, b) ? three_sort(a, b, 3)
			: four_push_swap(a, b, 3);
		while (len_b--)
			op_write(a, b, PA);
	}
	else
		ten_bis(a, b, nb, len_b);
}

void		small_push_swap(t_stack **a, t_stack **b, int nb)
{
	if (nb == 2 && (*a)->data == 1)
		op_write(a, b, SA);
	else if (nb == 3)
		three_sort(a, b, 0);
	else if (nb == 4 && !are_sorted(a, b))
		four_push_swap(a, b, 0);
	else if (nb == 5 && !are_sorted(a, b))
		five_push_swap(a, b, 0);
	else
		ten_push_swap(a, b, nb);
}
