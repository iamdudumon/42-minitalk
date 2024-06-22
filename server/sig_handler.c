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
		write(1, "SIUSR Error, Non-existend Pid\n", 31);
		exit(1);
	}
}

static void	store_binary(int signo)
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
			write(1, ft_strjoin(g_msg.buf, "\n"), ft_strlen(g_msg.buf) + 1);
			init_msg(0, sigack_hadler);
		}
		ch = 0;
		len = 0;
	}
}

void	sigusr_controler(int signo, siginfo_t *info, void *context)
{
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

void	sigack_hadler(int signo, siginfo_t *info, void *context)
{
	init_msg(info->si_pid, sigusr_controler);
	print_clt_info();
	ft_kill(info->si_pid, SIGUSR1);
}
