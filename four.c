/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:29:15 by akrache           #+#    #+#             */
/*   Updated: 2019/10/03 18:42:14 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	four_ops(t_stack **a, t_stack **b, char ops[])
{
	int i;

	i = -1;
	while (ops[++i])
		op_write(a, b, ops[i]);
}

static void	four_push_swap4(t_stack **a, t_stack **b, int s)
{
	if ((*a)->data == s + 3 && (*a)->next->data == s + 2
		&& (*a)->next->next->data == s + 1 && (*a)->last->data == s)
		four_ops(a, b, "AFFA");
	else if ((*a)->data == s + 3 && (*a)->next->data == s + 2
		&& (*a)->next->next->data == s && (*a)->last->data == s + 1)
		four_ops(a, b, "AFF");
}

static void	four_push_swap3(t_stack **a, t_stack **b, int s)
{
	if ((*a)->data == s + 2 && (*a)->next->data == s + 1
		&& (*a)->next->next->data == s + 3 && (*a)->last->data == s)
		four_ops(a, b, "AI");
	else if ((*a)->data == s + 2 && (*a)->next->data == s
		&& (*a)->next->next->data == s + 1 && (*a)->last->data == s + 3)
		four_ops(a, b, "IAFF");
	else if ((*a)->data == s + 2 && (*a)->next->data == s
		&& (*a)->next->next->data == s + 3 && (*a)->last->data == s + 1)
		four_ops(a, b, "AIA");
	else if ((*a)->data == s + 3 && (*a)->next->data == s
		&& (*a)->next->next->data == s + 2 && (*a)->last->data == s + 1)
		four_ops(a, b, "FFAI");
	else if ((*a)->data == s + 3 && (*a)->next->data == s
		&& (*a)->next->next->data == s + 1 && (*a)->last->data == s + 2)
		four_ops(a, b, "F");
	else if ((*a)->data == s + 3 && (*a)->next->data == s + 1
		&& (*a)->next->next->data == s && (*a)->last->data == s + 2)
		four_ops(a, b, "FA");
	else if ((*a)->data == s + 3 && (*a)->next->data == s + 1
		&& (*a)->next->next->data == s + 2 && (*a)->last->data == s)
		four_ops(a, b, "IAF");
	else
		four_push_swap4(a, b, s);
}

static void	four_push_swap2(t_stack **a, t_stack **b, int s)
{
	if ((*a)->data == s + 1 && (*a)->next->data == s + 2
		&& (*a)->next->next->data == s && (*a)->last->data == s + 3)
		four_ops(a, b, "FFAF");
	else if ((*a)->data == s + 1 && (*a)->next->data == s + 3
		&& (*a)->next->next->data == s && (*a)->last->data == s + 2)
		four_ops(a, b, "AFA");
	else if ((*a)->data == s + 1 && (*a)->next->data == s + 3
		&& (*a)->next->next->data == s + 2 && (*a)->last->data == s)
		four_ops(a, b, "FAFF");
	else if ((*a)->data == s + 1 && (*a)->next->data == s + 2
		&& (*a)->next->next->data == s + 3 && (*a)->last->data == s)
		four_ops(a, b, "I");
	else if ((*a)->data == s + 2 && (*a)->next->data == s + 3
		&& (*a)->next->next->data == s + 1 && (*a)->last->data == s)
		four_ops(a, b, "FFA");
	else if ((*a)->data == s + 2 && (*a)->next->data == s + 3
		&& (*a)->next->next->data == s && (*a)->last->data == s + 1)
		four_ops(a, b, "FF");
	else if ((*a)->data == s + 2 && (*a)->next->data == s + 1
		&& (*a)->next->next->data == s && (*a)->last->data == s + 3)
		four_ops(a, b, "AFFAF");
	else
		four_push_swap3(a, b, s);
}

void		four_push_swap(t_stack **a, t_stack **b, int s)
{
	if ((*a)->data == s && (*a)->next->data == s + 1
	&& (*a)->next->next->data == s + 3 && (*a)->last->data == s + 2)
		four_ops(a, b, "FFAFF");
	else if ((*a)->data == s && (*a)->next->data == s + 3
		&& (*a)->next->next->data == s + 1 && (*a)->last->data == s + 2)
		four_ops(a, b, "AF");
	else if ((*a)->data == s && (*a)->next->data == s + 3
		&& (*a)->next->next->data == s + 2 && (*a)->last->data == s + 1)
		four_ops(a, b, "AFFAI");
	else if ((*a)->data == s && (*a)->next->data == s + 2
		&& (*a)->next->next->data == s + 1 && (*a)->last->data == s + 3)
		four_ops(a, b, "FAI");
	else if ((*a)->data == s && (*a)->next->data == s + 2
		&& (*a)->next->next->data == s + 3 && (*a)->last->data == s + 1)
		four_ops(a, b, "IA");
	else if ((*a)->data == s + 1 && (*a)->next->data == s
		&& (*a)->next->next->data == s + 3 && (*a)->last->data == s + 2)
		four_ops(a, b, "AFFAFF");
	else if ((*a)->data == s + 1 && (*a)->next->data == s
		&& (*a)->next->next->data == s + 2 && (*a)->last->data == s + 3)
		four_ops(a, b, "A");
	else
		four_push_swap2(a, b, s);
}
