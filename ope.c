/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:06:58 by akrache           #+#    #+#             */
/*   Updated: 2019/09/25 18:52:48 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		stack_free(t_stack **s)
{
	t_stack *tmp;

	while ((*s))
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}

void		swap(t_stack **s)
{
	t_stack *tmp;

	if ((*s) && (*s)->next)
	{
		tmp = (*s)->next;
		(*s)->next = tmp->next;
		(*s)->prev = tmp;
		if (!tmp->next)
		{
			(*s)->last = *s;
			tmp->last = *s;
		}
		else
			tmp->last = (*s)->last;
		tmp->next = *s;
		tmp->prev = NULL;
		*s = tmp;
	}
}

void		push(t_stack **dest, t_stack **src)
{
	long data;

	data = pop(src);
	if (data == TOO_BIG)
		return ;
	add(dest, (int)data);
}

void		rotate(t_stack **s)
{
	t_stack *tmp;

	if (*s && (*s)->next)
	{
		tmp = (*s)->next;
		tmp->prev = NULL;
		(*s)->last->next = *s;
		(*s)->prev = (*s)->last;
		tmp->last = *s;
		(*s)->next = NULL;
		(*s)->last = *s;
		*s = tmp;
	}
}

void		reverse_rotate(t_stack **s)
{
	t_stack *tmp;

	if (*s && (*s)->next)
	{
		tmp = (*s)->last;
		tmp->prev->next = NULL;
		(*s)->last = tmp->prev;
		tmp->last = tmp->prev;
		tmp->prev = NULL;
		(*s)->prev = tmp;
		tmp->next = *s;
		*s = tmp;
	}
}
