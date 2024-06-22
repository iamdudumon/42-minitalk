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

static void	start_sending_msg(int pid, char *msg)
{
	char	*pids;
	char	*print_s1;
	char	*print_s2;

	pids = ft_itoa(pid);
	print_s1 = ft_strjoin("My pid is ", pids);
	print_s2 = ft_strjoin(print_s1, "\n");
	write(1, print_s2, 11 + ft_strlen(pids) + 1);
	free(pids);
	free(print_s1);
	free(print_s2);
	send_ack(pid, msg);
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Wrong argument. bye bye\n", 25);
		return (0);
	}
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = ack_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	start_sending_msg(ft_atoi(argv[1]), argv[2]);
}
