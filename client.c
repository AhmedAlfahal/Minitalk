/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:39:05 by aalfahal          #+#    #+#             */
/*   Updated: 2023/01/22 17:51:15 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>

void	to_binary(int pid, char c)
{
	static int	bits;

	if (bits < 7)
	{
		bits++;
		to_binary(pid, c >> 1);
	}
	else if (bits == 7)
		bits = 0;
	if (c % 2 == 1)
	{
		kill(pid, SIGUSR2);
		usleep(250);
	}
	else if (c % 2 == 0)
	{
		kill(pid, SIGUSR1);
		usleep(250);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	pid = 0;
	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			exit(0);
		while (av[2][i])
			to_binary(pid, av[2][i++]);
	}
	return (0);
}
