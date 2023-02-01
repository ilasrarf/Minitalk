/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:41:20 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/01/31 20:00:25 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handel(int num)
{
	if (num == SIGINT)
		ft_printf("SIGINT\n");
	if (num == SIGTERM)
		ft_printf("SIGTERM\n");
	if (num == SIGUSR1)
		ft_printf("HELLO USER1\n");
	if (num == SIGUSR2)
		ft_printf("HELLO USER2\n");
}

int main()
{
	ft_printf("PID: %d\n",getpid());
	signal(SIGUSR1, ft_handel);
	while (1);
}
