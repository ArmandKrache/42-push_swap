/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_ps2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:52:55 by akrache           #+#    #+#             */
/*   Updated: 2019/09/25 20:41:43 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	inv_sorted(t_stack **s)
{
	t_stack *tmp;

	tmp = *s;
	while (tmp && tmp->next)
	{
		if (tmp->data < tmp->next->data)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	three_inv_sort(t_stack **a, t_stack **b, int end)
{
	if ((*b)->data == end && (*b)->next->data == end - 2)
	{
		op_write(a, b, SB);
		op_write(a, b, RB);
	}
	else if ((*b)->data == end - 2 && (*b)->next->data == end)
		op_write(a, b, RB);
	else if ((*b)->data == end - 1 && (*b)->next->data == end - 2)
		op_write(a, b, RRB);
	else if ((*b)->data == end - 1 && (*b)->next->data == end)
		op_write(a, b, SB);
	else if ((*b)->data == end - 2 && (*b)->next->data == end - 1)
	{
		op_write(a, b, RB);
		op_write(a, b, SB);
	}
}

void	four_inv_push_swap(t_stack **a, t_stack **b, int end)
{
	if ((*b)->data == end)
		op_write(a, b, PA);
	else
	{
		if ((*b)->last->data == end)
			op_write(a, b, RRB);
		else if ((*b)->next->data == end)
			op_write(a, b, SB);
		else
		{
			op_write(a, b, RB);
			op_write(a, b, RB);
		}
		op_write(a, b, PA);
	}
	if (!inv_sorted(b))
		three_inv_sort(a, b, end - 1);
	op_write(a, b, PB);
}

void	five_inv_push_swap(t_stack **a, t_stack **b, int end)
{
	if ((*b)->data == end)
		op_write(a, b, PA);
	else
	{
		if ((*b)->last->data == end)
			op_write(a, b, RRB);
		else if ((*b)->next->data == end)
			op_write(a, b, SB);
		else if ((*b)->next->next->data == end)
		{
			op_write(a, b, RB);
			op_write(a, b, RB);
		}
		else
		{
			op_write(a, b, RRB);
			op_write(a, b, RRB);
		}
		op_write(a, b, PA);
	}
	if (!inv_sorted(b))
		four_inv_push_swap(a, b, end - 1);
	op_write(a, b, PB);
}
