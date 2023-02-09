/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:54 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/02/08 14:39:21 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	size_t	signe;

	signe = 1;
	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	return (res * signe);
}

void	ft_send_end(int	c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(c, SIGUSR1);
		usleep(200);
		i++;
	}
}

void	ft_mess(int	num)
{
	if (num == SIGUSR1)
		write(1, "THE PRINTING IT'S OVER", 22);
	exit(0);
}

int main(int ac, char **av)
{
	int	i;
	int	j;
	unsigned char 	bit;

	signal(SIGUSR1, ft_mess);
	if (ac != 3)
		return (write(1, "!error!", 7),0);
	j = 0;
	while (av[2][j])
	{
		i = 7;
		while (i >= 0)
		{
			bit = ((av[2][j] >> i) & 1);
			if(bit == 0)
				kill(ft_atoi(av[1]), SIGUSR1);
			else if (bit == 1)
				kill(ft_atoi(av[1]), SIGUSR2);
			usleep(200);
			i--;
		}
		j++;
	}
	ft_send_end(ft_atoi(av[1]));
	return (0);
}

