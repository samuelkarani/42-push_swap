/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:17:09 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/12 16:00:28 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_stack *a, t_stack *b, int *flags)
{
	ft_printf("init\n");
	print(a, b, flags[1]);
}

void	checker(t_stack *a, int *flags)
{
	t_stack	*b;
	char	*inst;

	b = NULL;
	if (flags[0])
		init(a, b, flags);
	while (get_next_line(STDIN_FILENO, &inst) == 1)
	{
		if (check_inst(inst))
		{
			apply_inst((t_stack **[]){&a, &b}, inst, flags, 0);
			free(inst);
			if (flags[0])
				print(a, b, flags[1]);
		}
		else
			error();
	}
	if (check_win(a, b))
		win();
	else
		ko();
	destroy(&a);
	destroy(&b);
}

int		main(int ac, char **av)
{
	return (main_shared(ac, av, &checker));
}
