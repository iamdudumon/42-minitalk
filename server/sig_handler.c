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

static void	ft_kill(int pid, int signo)
{
	if (kill(pid, signo) == -1)
	{
		write(1, "SIGUSR Error, Non-existend Pid\n", 31);
		exit(1);
	}
}

static void	store_binary(int signo)
{
	static char	ch;
	static int	len;

	if (signo == SIGUSR2)
		ch |= (1 << len);
	if (++len == CODE_SIZE)
	{
		if (g_msg.len == BUFFER_SIZE)
		{
			write(1, g_msg.buf, g_msg.len);
			ft_memset(g_msg.buf, 0, BUFFER_SIZE);
			g_msg.len = 0;
		}
		g_msg.buf[g_msg.len] = ch;
		if (g_msg.buf[g_msg.len] == '\0')
		{
			write(1, g_msg.buf, g_msg.len);
			write(1, "\n", 1);
			init_msg(0, sigack_hadler);
		}
		ch = 0;
		len = 0;
		g_msg.len++;
	}
}

void	srv_sig_handler(int signo, siginfo_t *info, void *context)
{
	if (g_msg.clt_pid == info->si_pid)
	{
		store_binary(signo);
		ft_kill(info->si_pid, signo);
	}
	else
		ft_kill(info->si_pid, SIGUSR2);

}

void	sigack_hadler(int signo, siginfo_t *info, void *context)
{
	if (info->si_pid == g_msg.clt_pid)
	{
		init_msg(info->si_pid, srv_sig_handler);
		print_clt_info();
	}
	g_msg.clt_pid = info->si_pid;
	ft_kill(info->si_pid, SIGUSR1);
}
