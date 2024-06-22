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

int	main(void)
{
	int	pid;

	pid = getpid();
	print_srv_info(pid);
	init_msg(0, sigack_hadler);
	while (1)
		pause();
}
