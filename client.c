/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:42:13 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/02/08 14:39:25 by ilasrarf         ###   ########.fr       */
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

int main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	int	i;
	int	j;
	unsigned char 	bit;

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
			usleep(700);
			i--;
		}
		j++;
	}
}

