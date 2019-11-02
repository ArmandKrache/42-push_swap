/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrache <akrache@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:45:56 by akrache           #+#    #+#             */
/*   Updated: 2019/09/26 14:23:05 by akrache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# define TOO_BIG 0x80000000
# define SA 65
# define SB 66
# define SS 67
# define PA 68
# define PB 69
# define RA 70
# define RB 71
# define RR 72
# define RRA 73
# define RRB 74
# define RRR 75

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*last;
}					t_stack;

/*
** Stack and Operations
*/

unsigned int		build_stack(t_stack **a, int i, char **arg);
void				stack_free(t_stack **s);
bool				add(t_stack **s, int data);
long				pop(t_stack **s);
void				swap(t_stack **s);
void				push(t_stack **dest, t_stack **src);
void				rotate(t_stack **s);
void				reverse_rotate(t_stack **s);
void				do_ops(t_stack **a, t_stack **b, char c);
int					are_sorted(t_stack **a, t_stack **b);

/*
** Push Swap
*/

void				four_push_swap(t_stack **a, t_stack **b, int s);
bool				inv_sorted(t_stack **s);
void				three_inv_sort(t_stack **a, t_stack **b, int end);
void				four_inv_push_swap(t_stack **a, t_stack **b, int end);
void				five_inv_push_swap(t_stack **a, t_stack **b, int end);
void				small_push_swap(t_stack **a, t_stack **b, int nb);
void				push_swap(t_stack **a, t_stack **b, int nb);

/*
** Checker
*/

char				*parsing(void);
char				*parse_ops(char *str);

/*
** Tools
*/

void				*ft_freeptr(void *ptr);
int					error_msg(int ret);
bool				check_double(t_stack *s, int data);
int					closest_rarra(t_stack **a, int s);
void				op_write(t_stack **a, t_stack **b, char op);
char				**ft_strsplit(char const *s, char c);
void				*ft_splitfree(char **res, int s);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);

#endif
