/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:54:49 by dukim             #+#    #+#             */
/*   Updated: 2024/06/22 15:54:53 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLIENT_H
# define FT_CLIENT_H

# include <signal.h>
# include "../libft/libft.h"

# define CODE_SIZE  8

typedef struct s_msg
{
	char				*msg;
	int					len;
	struct sigaction	sa;
}			t_msg;

void	send_sigack(int pid, char *msg);
void	ack_handler(int signo, siginfo_t *info, void *context);
void	clt_sig_handler(int signo, siginfo_t *info, void *context);

#endif
