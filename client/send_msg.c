/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:53:40 by dukim             #+#    #+#             */
/*   Updated: 2024/06/22 15:53:42 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"

extern t_msg	g_msg;

static void	ft_kill(int pid, int signo)
{
	if (kill(pid, signo) == -1)
	{
		write(1, "SIGUSR Error, Non-existend Pid\n", 31);
		exit(1);
	}
}

void	send_sigack(int pid, char *msg)
{
	ft_kill(pid, SIGUSR1);
}

void	ack_handler(int signo, siginfo_t *info, void *context)
{
	if (signo == SIGUSR2)
	{
		write(1, "Server is busy...\nRetry sending message!\n", 42);
		exit(1);
	}
	g_msg.sa.sa_flags = SA_SIGINFO | SA_RESTART;
	g_msg.sa.sa_sigaction = clt_sig_handler;
	sigemptyset(&g_msg.sa.sa_mask);
	sigaction(SIGUSR1, &g_msg.sa, NULL);
	sigaction(SIGUSR2, &g_msg.sa, NULL);
	send_sigack(info->si_pid, g_msg.msg);
}

void	clt_sig_handler(int signo, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	ch;

	if (bit == CODE_SIZE)
	{
		if (ch == '\0')
		{
			write(1, "You've successfully sent your message.\n", 40)
			exit(0);
		}
		bit = 0;
		g_msg.len++;
	}
	ch = g_msg.msg[g_msg.len];
	if ((ch & (1 << bit)) == 0)
		ft_kill(info->si_pid, SIGUSR1);
	else
		ft_kill(info->si_pid, SIGUSR2);
	bit++;
}

