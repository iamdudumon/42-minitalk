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

#ifndef FT_SERVER_BONUS_H
# define FT_SERVER_BONUS_H

# include <signal.h>
# include "../libft/libft.h"

# define CODE_SIZE  8
# define BUFFER_SIZE 1024

typedef struct s_msg
{
	char				buf[BUFFER_SIZE];
	int					len;
	int					clt_pid;
	struct sigaction	sa;
}						t_msg;

void	sigack_hadler(int signo, siginfo_t *info, void *context);
void	srv_sig_handler(int signo, siginfo_t *info, void *context);
void	init_msg(int clt_pid, void (*handler)(int, siginfo_t*, void*));
void	print_srv_info(int pid);
void	print_clt_info(int clt_pid, int error);

#endif
