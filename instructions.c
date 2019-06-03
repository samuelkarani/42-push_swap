/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:01:32 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/12 16:44:08 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int tmp;

	if (!s || !s->next)
		ko_exit();
	tmp = s->num;
	s->num = s->next->num;
	s->next->num = tmp;
}

void	rotate_up(t_stack *s)
{
	int	first;

	if (!s)
		ko_exit();
	first = s->num;
	while (s->next)
	{
		s->num = s->next->num;
		s = s->next;
	}
	s->num = first;
}

void	rotate_down(t_stack *s)
{
	t_stack	*p;
	int		top;
	int		prev;

	if (!s)
		ko_exit();
	prev = s->num;
	p = s;
	s = s->next;
	while (s)
	{
		top = s->num;
		s->num = prev;
		prev = top;
		s = s->next;
	}
	p->num = prev;
}

void	apply_ro(t_stack **a, t_stack **b, char *s)
{
	if (ft_strcmp(s, "ra") == 0)
		rotate_up(*a);
	if (ft_strcmp(s, "rb") == 0)
		rotate_up(*b);
	if (ft_strcmp(s, "rr") == 0)
	{
		rotate_up(*a);
		rotate_up(*b);
	}
	if (ft_strcmp(s, "rra") == 0)
		rotate_down(*a);
	if (ft_strcmp(s, "rrb") == 0)
		rotate_down(*b);
	if (ft_strcmp(s, "rrr") == 0)
	{
		rotate_down(*a);
		rotate_down(*b);
	}
}

void	apply_inst(t_stack **ss[], char *s, int *flags, int ps)
{
	t_stack **a;
	t_stack **b;

	a = ss[0];
	b = ss[1];
	if (ft_strcmp(s, "sa") == 0)
		swap(*a);
	if (ft_strcmp(s, "sb") == 0)
		swap(*b);
	if (ft_strcmp(s, "ss") == 0)
	{
		swap(*a);
		swap(*b);
	}
	if (ft_strcmp(s, "pa") == 0)
		push(a, pop(b));
	if (ft_strcmp(s, "pb") == 0)
		push(b, pop(a));
	apply_ro(a, b, s);
	if (ps)
		check_print(s, flags, *a, *b);
}
