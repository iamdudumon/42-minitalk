/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:50:00 by dukim             #+#    #+#             */
/*   Updated: 2024/06/22 15:50:01 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"

t_msg	g_msg;

static void	start_sending_msg(int pid, char *msg)
{
	char	*pids;
	char	*print_s1;
	char	*print_s2;

	if (pid == 0)
	{
		write(1, "Wrong Pid\n", 11);
		exit(1);
	}
	pids = ft_itoa(getpid());
	print_s1 = ft_strjoin("My pid is ", pids);
	print_s2 = ft_strjoin(print_s1, "\n");
	write(1, print_s2, 11 + ft_strlen(pids) + 1);
	free(pids);
	free(print_s1);
	free(print_s2);
	g_msg.msg = msg;
	g_msg.len = 0;
	send_sigack(pid);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		write(1, "Wrong argument. bye bye\n", 25);
		return (0);
	}
	g_msg.sa.sa_flags = SA_SIGINFO | SA_RESTART;
	g_msg.sa.sa_sigaction = ack_handler;
	sigemptyset(&g_msg.sa.sa_mask);
	sigaction(SIGUSR1, &g_msg.sa, NULL);
	sigaction(SIGUSR2, &g_msg.sa, NULL);
	start_sending_msg(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}
