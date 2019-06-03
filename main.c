/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 23:26:34 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/12 16:57:05 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_arg(t_stack **a, char *snum)
{
	long n;

	if (check_integer(snum))
	{
		n = ft_atoi_l(snum);
		if (check_size(n))
		{
			if (check_duplicates(*a, n))
				push(a, n);
			else
				error_free(snum);
		}
		else
			error_free(snum);
	}
	else
		error_free(snum);
	free(snum);
}

void	get_integers(char *s, t_stack **a)
{
	int		i;
	int		b;
	int		idx;

	i = 0;
	b = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			if ((idx = ft_stridx(s + i, ' ')) == -1)
			{
				idx = ft_strlen(s);
				b = 1;
			}
			handle_arg(a, ft_strsub(s, i, idx));
			if (b)
				break ;
			i += idx;
		}
		i++;
	}
	copy_reverse(a);
}

int		handle_flags(char *s, int *flags)
{
	if (s[0] == '-')
	{
		if ((s[1] == 'c' && s[2] == 'v') || (s[1] == 'v' && s[2] == 'c'))
		{
			flags[0] = 1;
			flags[1] = 1;
		}
		else if (s[1] == 'v' && !s[2])
			flags[0] = 1;
		else if (s[1] == 'c' && !s[2])
			flags[1] = 1;
		else if (ft_isdigit(s[1]))
			return (-1);
		else
			error();
	}
	else
		return (-1);
	return (0);
}

void	handle_args(t_stack **a, char *s)
{
	long n;

	if (check_space(s))
		get_integers(s, a);
	else if (check_integer(s))
	{
		n = ft_atoi_l(s);
		if (check_size(n))
		{
			if (check_duplicates(*a, n))
				push(a, n);
			else
				error();
		}
		else
			error();
	}
	else
		error();
}

int		main_shared(int ac, char **av, void (*f)(t_stack*, int *flags))
{
	t_stack	*a;
	int		flags[2];
	int		i;

	if (ac > 1)
	{
		flags[0] = 0;
		flags[1] = 0;
		i = 1;
		while (i < ac)
		{
			if (handle_flags(av[i], flags) == -1)
				break ;
			i++;
		}
		a = NULL;
		while (--ac >= i)
			handle_args(&a, av[ac]);
		(*f)(a, flags);
	}
	return (0);
}
