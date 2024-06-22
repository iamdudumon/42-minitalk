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

t_msg	g_msg;

void	ft_kill(int pid, int signo)
{
	if (kill(pid, signo) == -1)
	{
		write(1, "SIUSR Error, Non-existend Pid\n", 31);
		exit(1);
	}
}

void	ack_handler(int signo, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	ch;

	if (bit == CODE_SIZE)
	{
		if (ch == '\0')
			exit(1);
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

void	send_ack(int pid, char *msg)
{
	g_msg.msg = msg;
	g_msg.len = 0;
	ft_kill(pid, SIGUSR1);
	while (1)
		pause();
}
