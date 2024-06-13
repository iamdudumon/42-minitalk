/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:10:23 by dukim             #+#    #+#             */
/*   Updated: 2024/06/09 16:10:26 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"
#include <signal.h>

extern t_msg	g_msg;

void	ft_kill(int pid, int signo)
{
	g_msg.recevied = 0;
	kill(pid, signo);
	// if (kill(pid, signo) == -1)
	// {
	// 	ft_printf("SIUSR(%d) Error\n", signo);
	// 	exit(1);
	// }
	usleep(100000);
	if (!g_msg.recevied)
		ft_kill(pid, signo);

}

void	store_binary(int signo)
{
	static char	ch;
	static int	len;

	if (signo == SIGUSR2)
		ch |= (1 << len);
	len++;
	if (len == CODE_SIZE)
	{
		g_msg.buf[g_msg.len++] = ch;
		if (g_msg.buf[g_msg.len - 1] == '\0')
		{
			ft_printf("client(%d): %s\n", g_msg.clt_pid, g_msg.buf);
			init_msg(0, sigack_hadler);
		}
		ch = 0;
		len = 0;
	}
}

void	sigusr_controler(int signo, siginfo_t *info, void* context)
{
	g_msg.recevied = 1;
	if (g_msg.clt_pid == info->si_pid)
	{
		store_binary(signo);
		ft_kill(info->si_pid, signo);
	}
	else
	{
		if (signo == SIGUSR1)
			ft_kill(info->si_pid, SIGUSR2);
		else
			ft_kill(info->si_pid, SIGUSR1);
	}
}

void	sigack_hadler(int signo, siginfo_t *info, void* context)
{
	g_msg.recevied = 1;
	init_msg(info->si_pid, sigusr_controler);
	ft_kill(info->si_pid, SIGUSR1);
}
