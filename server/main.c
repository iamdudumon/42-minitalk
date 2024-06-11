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
	ft_printf("server pid: %d\n", pid);

	init_msg(0, sigack_hadler);
	sigaction(SIGUSR1, &g_msg.handler, NULL);
	sigaction(SIGUSR2, &g_msg.handler, NULL);
	while (1)
		pause();
}
