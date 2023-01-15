/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:23:24 by makbas            #+#    #+#             */
/*   Updated: 2023/01/15 17:24:59 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void	character(int pid, char character)
{
	int	bit;
	int	bit_i;
	int	c_ascii;

	c_ascii = character;
	bit_i = 0;
	bit = 128;
	while (bit_i < 8)
	{
		if (c_ascii >= bit && bit > 0)
		{
			c_ascii = c_ascii - bit;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		bit_i++;
		bit /= 2;
		usleep(100);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - 48) * sign;
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
		i++;
	}
	return (num);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;
	int		i;

	if (argc != 3)
	{
		write(1, "hatalı argüman sayısı", 26);
		return (0);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (str[i])
	{
		character(pid, str[i]);
		i++;
	}
	character(pid, 10);
}
