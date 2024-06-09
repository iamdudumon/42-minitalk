/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:10:23 by dukim             #+#    #+#             */
/*   Updated: 2024/06/09 16:10:26 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"

extern t_msg	msg;

void	store_binary(char ch)
{
	msg.buf[msg.len++] = ch;
	if (msg.buf[msg.len - 1] == '\0')
	{
		ft_printf("client: %s\n", msg.buf);
		ft_memset(msg.buf, 0, sizeof(t_msg));
	}
}

void	sigack_handler(int signo)
{

}

void	sigusr_handler(int signo)
{
	static char	ch;
	static int	len;

	if (signo == SIGUSR2)
		ch |= (1 << len);
	len++;
	if (len == CODE_SIZE)
	{
		store_binary(ch);
		ch = 0;
		len = 0;
	}
}
