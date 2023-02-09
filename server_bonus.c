/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:22:49 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/02/08 16:12:24 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pwr(int x)
{
	int	i;
	int	sum;

	sum = 1;
	i = 0;
	while (i < x)
	{
		sum = sum * 2;
		i++;
	}
	return (sum);
}

void	ft_handel(int num, siginfo_t *info, void *f)
{
	static int				i = 7;
	static unsigned char	buf = 0;
	static int				se;
	static int				new;

	(void)f;
	if (!se)
		se = info->si_pid;
	new = info->si_pid;
	if (se != new)
	{
		se = new;
		i = 7;
		buf = 0;
	}
	if (i >= 0)
	{
		if (num == SIGUSR2)
			buf = buf + ft_pwr(i);
		i--;
	}
	if (i < 0)
	{
		if (buf == 0)
			kill(se, SIGUSR1);
		write(1, &buf, 1);
		buf = 0;
		i = 7;
	}
}

int	main()
{
	struct	sigaction sig;

	sig.sa_sigaction = ft_handel;
	sig.sa_flags = SA_SIGINFO;
	printf("%d\n", getpid());
	while(1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
}
