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

void	store_binary(char ch)
{
	g_msg.buf[g_msg.len++] = ch;
	if (g_msg.buf[g_msg.len - 1] == '\0')
	{
		ft_printf("client(%d): %s\n", g_msg.clt_pid, g_msg.buf);
		init_msg(0, sigack_hadler);
	}
}

void	sigusr_controler(int signo, siginfo_t *info, void* context)
{
	if (g_msg.clt_pid == info->si_pid)
	{
		sigusr_handler(signo);
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
}

void	sigusr_handler(int signo)
{
	static char	ch;
	static int	len;

	if (signo == SIGUSR2)
		ch |= (1 << len);
	len++;
	if (len == CODE_SIZE)
	{
		store_binary(ch);
		ch = 0;
		len = 0;
	}
}

void	sigack_hadler(int signo, siginfo_t *info, void* context)
{
	init_msg(info->si_pid, sigusr_controler);
	kill(info->si_pid, SIGUSR1);
}
