/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:48:09 by akrache           #+#    #+#             */
/*   Updated: 2019/10/07 11:08:54 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**#include <stdio.h>
**void		display(t_stack **a, t_stack **b, int nb, int len_b)
**{
**	t_stack *tmp;
**
**	tmp = *a;
**	printf("----- stack A -----\n");
**	while (tmp)
**	{
**		printf("  data = %d  \n", tmp->data);
**		tmp = tmp->next;
**	}
**	printf("\n----- stack B -----\n");
**	tmp = *b;
**	while (tmp)
**	{
**		printf("  data = %d  \n", tmp->data);
**		tmp = tmp->next;
**	}
**	printf("nb == %d | len_b == %d\n", nb, len_b);
**}
*/

static char	*read_instructions(void)
{
	char	*ops;
	char	*str;

	if (!(str = parsing()))
		return (NULL);
	if (!(ops = parse_ops(str)))
		return (ft_freeptr(str));
	free(str);
	return (ops);
}

int			checker(t_stack **a, t_stack **b)
{
	char	*ops;
	int		i;

	if (!(ops = read_instructions()))
		return (error_msg(0));
	i = 0;
	while (ops[i])
	{
		do_ops(a, b, ops[i]);
		i++;
	}
	if (are_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(ops);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!(build_stack(&a, argc - 1, argv)) || !checker(&a, &b))
		;
	stack_free(&a);
	stack_free(&b);
	return (0);
}
