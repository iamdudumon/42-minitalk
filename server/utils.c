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

#include "ft_server.h"

extern t_msg	g_msg;

void init_msg(int clt_pid, void (*handler)(int, siginfo_t *, void *))
{
	ft_memset(g_msg.buf, 0, sizeof(char) * BUFFER_SIZE);
	g_msg.len = 0;
	g_msg.clt_pid = clt_pid;
	g_msg.handler.sa_flags = SA_SIGINFO;
	g_msg.handler.sa_sigaction = *handler;
	sigaction(SIGUSR1, &g_msg.handler, NULL);
	sigaction(SIGUSR2, &g_msg.handler, NULL);
}
