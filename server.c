/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:23:26 by makbas            #+#    #+#             */
/*   Updated: 2023/01/14 20:03:09 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	control(int bit)
{
	static int	i = 7;
	static char	c = 0;

	c |= bit << i;
	if (i == 0)
	{
		i = 7;
		write(1, &c, 1);
		c = 0;
	}
	else
		i--;
}

void	transfer(int pid)
{
	if (pid == SIGUSR1)
		control(1);
	else if (pid == SIGUSR2)
		control(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID : %d\nMesaj bekleniyor...\n", pid);
	while (1)
	{
		signal(SIGUSR1, transfer);
		signal(SIGUSR2, transfer);
		pause();
	}
}
