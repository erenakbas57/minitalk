/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbas <makbas@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:23:24 by makbas            #+#    #+#             */
/*   Updated: 2023/01/14 18:52:40 by makbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	character(int pid, char c)
{
	int	bit;
	int	i;
	int	cn;

	cn = c;
	i = 0;
	bit = 128;
	while (i <= 7)
	{
		if (cn >= bit && bit > 0)
		{
			cn = cn - bit;
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		i++;
		bit /= 2;
		usleep(100);
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - 48);
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
		ft_printf("hatalı argüman sayısı");
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
}
