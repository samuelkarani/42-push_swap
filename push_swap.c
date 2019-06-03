/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 20:54:56 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/24 20:42:30 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recurse(t_stack **ss[], int *slens, int *flags, int ca)
{
	int		m;

	if (ca)
	{
		m = median(*ss[0], slens[0], &lt);
		partition(ss, slens, flags, (int[]){m, 0});
		push_swap(ss, (int[]){glen(slens[0]), slens[0] / 2}, flags);
	}
	else
	{
		m = median(*ss[1], slens[1], &gt);
		partition(ss, slens, flags, (int[]){m, 1});
		push_swap(ss, (int[]){slens[1] / 2, glen(slens[1])}, flags);
	}
}

void	base_case(t_stack **ss[], int *slens, int *flags)
{
	if (slens[1] <= 3 && check_sorted_upto(*ss[0], slens[0], &lt)
		&& check_sorted_upto(*ss[1], slens[1], &gt))
		pa(ss[0], ss[1], slens[1], flags);
}

void	push_swap(t_stack **ss[], int *slens, int *flags)
{
	if (!check_sorted_upto(*ss[0], slens[0], &lt))
	{
		if (slens[0] <= 3)
		{
			if (slens[0] == 3)
				sort_three(ss[0], ss[1], flags, 0);
			check_swap(ss[0], ss[1], flags);
		}
		if (slens[0] > 3)
			recurse(ss, (int[]){slens[0], slens[1]}, flags, 1);
	}
	if (!check_sorted_upto(*ss[1], slens[1], &gt))
	{
		if (slens[1] <= 3)
		{
			if (slens[1] == 3)
				sort_three(ss[0], ss[1], flags, 1);
			check_swap(ss[0], ss[1], flags);
		}
		if (slens[1] > 3)
			recurse(ss, (int[]){slens[0], slens[1]}, flags, 0);
	}
	else if (slens[1] > 3)
		pa(ss[0], ss[1], slens[1], flags);
	base_case(ss, slens, flags);
}

void	prepare(t_stack *a, int *flags)
{
	t_stack *b;

	b = NULL;
	if (flags[0])
		check_print("init", flags, a, b);
	push_swap((t_stack **[]){&a, &b}, (int[]){size(a), 0}, flags);
	destroy(&a);
	destroy(&b);
}

int		main(int ac, char **av)
{
	return (main_shared(ac, av, &prepare));
}
