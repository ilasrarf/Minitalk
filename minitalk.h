/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilasrarf <ilasrarf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:00:03 by ilasrarf          #+#    #+#             */
/*   Updated: 2023/02/09 19:40:02 by ilasrarf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>

void	ft_handel(int num, siginfo_t *info, void *f);
int		ft_atoi(const char *str);
int		ft_pwr(int x);
void	ft_send_end(int c);
void	ft_mess(int num);
void	ft_check_pid(int *se, int *new, int *i, unsigned char *buf);
#endif