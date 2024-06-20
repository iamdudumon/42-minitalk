/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:30:06 by dukim             #+#    #+#             */
/*   Updated: 2024/06/11 18:30:08 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVER_H
# define FT_SERVER_H
# define CODE_SIZE  8

#include "../ft_printf/ft_printf.h"
#include <signal.h>

typedef struct	s_msg
{
	char				buf[BUFFER_SIZE];
	int					len;
	int					clt_pid;
	// int					sended;
	// int					recevied;
	struct sigaction	sa;
}				t_msg;

void	sigack_hadler(int signo, siginfo_t *info, void* context);
void	init_msg(int clt_pid, void (*handler)(int, siginfo_t*, void*));
// void	ft_kill(int pid, int signo);

#endif
