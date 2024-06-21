/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:29:54 by dukim             #+#    #+#             */
/*   Updated: 2024/06/11 18:29:55 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"

t_msg	g_msg;

int	main()
{
	int	pid;

	pid = getpid();
	write(1, ft_strjoin("server pid: ", ft_itoa(pid)), 13 + 7);
	write(1, "\n\n", 2);
	init_msg(0, sigack_hadler);
	while (1)
	{
		// if (!g_msg.clt_pid && !g_msg.recevied)
		// 	ft_kill(g_msg.clt_pid, g_msg.sended);
		// usleep(1000);
		pause();
	}
}
