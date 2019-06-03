/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:27:27 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/12 16:03:44 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sorted(t_stack *s, int (*cmp)(int, int))
{
	if (!s)
		return (1);
	while (s->next)
	{
		if ((*cmp)(s->num, s->next->num) == 0)
			break ;
		s = s->next;
	}
	return (!s->next);
}

int		check_sorted_upto(t_stack *s, int upto, int (*cmp)(int, int))
{
	if (!s)
		return (upto == 0);
	if (!s->next)
		return (upto == 1);
	while (s->next && --upto)
	{
		if ((*cmp)(s->num, s->next->num) == 0)
			return (0);
		s = s->next;
	}
	return (1);
}

int		check_win(t_stack *a, t_stack *b)
{
	return (check_sorted(a, &lt) && !b);
}

void	check_print(char *s, int *flags, t_stack *a, t_stack *b)
{
	if (flags[1])
		ft_printf("%s%s%s\n", RED, s, RESET);
	else
		ft_printf("%s\n", s);
	if (flags[0])
		print(a, b, flags[1]);
}
