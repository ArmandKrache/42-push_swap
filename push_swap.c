/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:32:09 by akrache           #+#    #+#             */
/*   Updated: 2019/10/02 14:20:15 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort(int *tab, int nb)
{
	int i;
	int j;
	int min;
	int tmp;

	i = 0;
	while (i < nb - 1)
	{
		min = i;
		j = i + 1;
		while (j < nb)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		tmp = tab[min];
		tab[min] = tab[i];
		tab[i] = tmp;
		i++;
	}
}

static void	lil_pre_calc(t_stack **a, int *tab, int nb)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = 0;
	while (i < nb)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->data == tab[i])
			{
				tmp->data = i;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

static int	pre_calc(t_stack **a, int nb)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	if (!(tab = (int *)malloc(sizeof(int) * nb)))
		return (0);
	i = 0;
	tmp = *a;
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	ft_sort(tab, nb);
	lil_pre_calc(a, tab, nb);
	free(tab);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;
	unsigned int	nb;

	if (argc < 2)
		return (error_msg(0));
	a = NULL;
	b = NULL;
	if ((nb = build_stack(&a, argc - 1, argv)) == 0 || !(pre_calc(&a, nb))
		|| are_sorted(&a, &b))
	{
		stack_free(&a);
		stack_free(&b);
		return (0);
	}
	if (nb <= 10)
		small_push_swap(&a, &b, nb);
	else
		push_swap(&a, &b, nb);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
