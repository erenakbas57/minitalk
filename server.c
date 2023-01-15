/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:23:26 by makbas            #+#    #+#             */
/*   Updated: 2023/01/15 17:25:19 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	control(int bit)
{
	static int	bit_i = 7;
	static char	character = 0;

	character |= bit << bit_i;
	if (bit_i == 0)
	{
		bit_i = 7;
		write(1, &character, 1);
		character = 0;
	}
	else
		bit_i--;
}

void	transfer(int signal)
{
	if (signal == SIGUSR1)
		control(1);
	else if (signal == SIGUSR2)
		control(0);
}

void	write_pid(int pid)
{
	if (pid > 10)
		write_pid(pid / 10);
	write(1, &"0123456789"[pid % 10], 1);
}

int	main(void)
{
	write(1, "Server PID: ", 13);
	write_pid(getpid());
	write(1, "\nMesaj bekleniyor...\n", 22);
	signal(SIGUSR1, transfer);
	signal(SIGUSR2, transfer);
	while (1)
		pause();
}
