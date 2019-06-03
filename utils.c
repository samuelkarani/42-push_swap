/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:53:13 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/12 15:58:34 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}

void	win(void)
{
	ft_putendl("OK");
}

void	ko(void)
{
	ft_putendl("KO");
}

int		gt(int a, int b)
{
	return (a > b);
}

int		lt(int a, int b)
{
	return (a < b);
}
