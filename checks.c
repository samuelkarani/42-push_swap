/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:36:01 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/12 15:27:19 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_integer(char *s)
{
	while (*s)
	{
		if (!(ft_isdigit(*s) || *s == '-'))
			return (0);
		s++;
	}
	return (1);
}

int	check_size(long n)
{
	return (n < MAX_INT && n > MIN_INT);
}

int	check_duplicates(t_stack *s, int n)
{
	while (s)
	{
		if (s->num == n)
			return (0);
		s = s->next;
	}
	return (1);
}

int	check_inst(char *s)
{
	if (ft_strcmp(s, "sa") == 0
		|| ft_strcmp(s, "sb") == 0
		|| ft_strcmp(s, "ss") == 0
		|| ft_strcmp(s, "pa") == 0
		|| ft_strcmp(s, "pb") == 0
		|| ft_strcmp(s, "ra") == 0
		|| ft_strcmp(s, "rb") == 0
		|| ft_strcmp(s, "rr") == 0
		|| ft_strcmp(s, "rra") == 0
		|| ft_strcmp(s, "rrb") == 0
		|| ft_strcmp(s, "rrr") == 0)
		return (1);
	return (0);
}

int	check_space(char *s)
{
	while (*s)
	{
		if (*s == ' ')
			return (1);
		s++;
	}
	return (0);
}
