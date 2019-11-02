/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:50:07 by akrache           #+#    #+#             */
/*   Updated: 2019/09/25 20:41:25 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		*ft_freeptr(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

int			error_msg(int ret)
{
	write(2, "Error\n", 6);
	return (ret);
}

bool		check_double(t_stack *s, int data)
{
	while (s)
	{
		if (s->data == data)
			return (true);
		s = s->next;
	}
	return (false);
}

void		op_write(t_stack **a, t_stack **b, char op)
{
	if (op == SA)
		write(1, "sa\n", 3);
	else if (op == SB)
		write(1, "sb\n", 3);
	else if (op == SS)
		write(1, "ss\n", 3);
	else if (op == PA)
		write(1, "pa\n", 3);
	else if (op == PB)
		write(1, "pb\n", 3);
	else if (op == RA)
		write(1, "ra\n", 3);
	else if (op == RB)
		write(1, "rb\n", 3);
	else if (op == RR)
		write(1, "rr\n", 3);
	else if (op == RRA)
		write(1, "rra\n", 4);
	else if (op == RRB)
		write(1, "rrb\n", 4);
	else if (op == RRR)
		write(1, "rrr\n", 4);
	do_ops(a, b, op);
}

int			closest_rarra(t_stack **a, int s)
{
	if ((*a)->next->data == s)
		return (1);
	else if ((*a)->next->next->data == s)
		return (2);
	else if ((*a)->last->data == s)
		return (3);
	else if ((*a)->last->prev->data == s)
		return (4);
	return (0);
}
