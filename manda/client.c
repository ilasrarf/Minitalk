/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:42:13 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/02/06 15:16:45 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
				kill(atoi(av[1]), SIGUSR1);
			else if (bit == 1)
				kill(atoi(av[1]), SIGUSR2);
			usleep(700);
			i--;
		}
		j++;
	}
}

