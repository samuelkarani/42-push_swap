/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:29:14 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/12 16:04:32 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_s(t_stack *a, t_stack *b)
{
	int tmp;

	tmp = a->num;
	a->num = b->num;
	b->num = tmp;
}

void	sort(t_stack *s, int (*cmp)(int, int))
{
	t_stack	*i;
	t_stack	*j;
	int		flag;

	if (s)
	{
		i = s;
		while (i->next)
		{
			flag = 0;
			j = s;
			while (j->next)
			{
				if ((*cmp)(j->num, j->next->num) == 0)
				{
					swap_s(j, j->next);
					flag = 1;
				}
				j = j->next;
			}
			if (flag == 0)
				break ;
			i = i->next;
		}
	}
}

t_stack	*copy_s(t_stack *s, int l)
{
	t_stack *new;

	new = NULL;
	while (s && l-- > 0)
	{
		push(&new, s->num);
		s = s->next;
	}
	return (new);
}

int		median(t_stack *s, int l, int (*cmp)(int, int))
{
	t_stack *c;
	t_stack *c_s;
	int		ret;
	int		m;

	c = copy_s(s, l);
	sort(c, cmp);
	m = size(c) / 2;
	c_s = c;
	while (m-- > 0)
		c = c->next;
	ret = c->num;
	destroy(&c_s);
	return (ret);
}

void	print(t_stack *a, t_stack *b, int c)
{
	while (a || b)
	{
		if (c)
		{
			a ? ft_printf("%s%4d%s", GREEN, a->num, RESET) :
				ft_printf("%4s", "");
			b ? ft_printf("%s%4d%s\n", GREEN, b->num, RESET) :
				ft_printf("%3s\n", "");
		}
		else
		{
			a ? ft_printf("%d ", a->num) : ft_printf("  ");
			b ? ft_printf("%d\n", b->num) : ft_printf(" \n");
		}
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_printf("\n");
}
