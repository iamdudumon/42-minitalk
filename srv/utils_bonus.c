/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:29:47 by dukim             #+#    #+#             */
/*   Updated: 2024/06/11 18:29:51 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server_bonus.h"

extern t_msg	g_msg;

void	init_msg(int clt_pid, void (*handler)(int, siginfo_t *, void *))
{
	ft_memset(g_msg.buf, 0, sizeof(char) * BUFFER_SIZE);
	g_msg.len = 0;
	g_msg.clt_pid = clt_pid;
	g_msg.sa.sa_flags = SA_SIGINFO | SA_RESTART;
	g_msg.sa.sa_sigaction = *handler;
	sigemptyset(&g_msg.sa.sa_mask);
	sigaction(SIGUSR1, &g_msg.sa, NULL);
	sigaction(SIGUSR2, &g_msg.sa, NULL);
}

void	print_srv_info(int pid)
{
	char	*pids;
	char	*print_s1;
	char	*print_s2;

	pids = ft_itoa(pid);
	print_s1 = ft_strjoin("server pid: ", pids);
	print_s2 = ft_strjoin(print_s1, "\n\n");
	write(1, print_s2, 13 + ft_strlen(pids) + 2);
	free(pids);
	free(print_s1);
	free(print_s2);
}

void	print_clt_info(int clt_pid, int error)
{
	char	*clt_pids;
	char	*print_s1;
	char	*print_s2;

	clt_pids = ft_itoa(clt_pid);
	print_s1 = ft_strjoin(clt_pids, " client] sended\n");
	print_s2 = ft_strjoin("[", print_s1);
	write(1, print_s2, 1 + ft_strlen(clt_pids) + 17);
	if (error)
		write(1, "Wrong Signal... bye bye\n", 25);
	free(clt_pids);
	free(print_s1);
	free(print_s2);
}
