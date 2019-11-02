/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:35:03 by akrache           #+#    #+#             */
/*   Updated: 2019/09/25 20:38:52 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool		add(t_stack **s, int data)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (false);
	new->data = data;
	new->next = *s;
	new->prev = NULL;
	if (*s)
		(*s)->prev = new;
	if (!(*s))
		new->last = new;
	else if (!(*s)->next)
		new->last = *s;
	else
		new->last = (*s)->last;
	*s = new;
	return (true);
}

long		pop(t_stack **s)
{
	t_stack	*pop;
	int		data;

	if (*s)
	{
		pop = *s;
		if ((*s)->next)
			(*s)->next->last = (*s)->last;
		*s = (*s)->next;
		pop->next = NULL;
		pop->prev = NULL;
		pop->last = NULL;
		data = pop->data;
		free(pop);
		return (data);
	}
	return (TOO_BIG);
}

static void	do_ops2(t_stack **a, t_stack **b, char c)
{
	if (c == SS)
	{
		swap(a);
		swap(b);
	}
	else if (c == RR)
	{
		rotate(a);
		rotate(b);
	}
	else if (c == RRR)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

void		do_ops(t_stack **a, t_stack **b, char c)
{
	if (c == SA)
		swap(a);
	else if (c == SB)
		swap(b);
	else if (c == PB)
		push(b, a);
	else if (c == PA)
		push(a, b);
	else if (c == RA)
		rotate(a);
	else if (c == RB)
		rotate(b);
	else if (c == RRA)
		reverse_rotate(a);
	else if (c == RRB)
		reverse_rotate(b);
	else
		do_ops2(a, b, c);
}

int			are_sorted(t_stack **a, t_stack **b)
{
	t_stack *tmp;

	tmp = *a;
	if (*b)
		return (0);
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
