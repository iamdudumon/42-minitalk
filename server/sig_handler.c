/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:47:17 by dukim             #+#    #+#             */
/*   Updated: 2024/05/26 17:47:21 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"

extern t_msg    msg;

void    flush_buffer()
{
    if (msg.seg_no == 0)
        ft_printf("client: ");
    ft_printf("%s\n", msg.buf);
    ft_memset(msg.buf, 0, BUFFER_SIZE);
    msg.buf_len = 0;
    msg.seg_no++;
}

void    store_binary()
{
    msg.binary[CODE_SIZE] = 0;
    msg.buf[msg.buf_len++] = to_char(msg.binary);
    ft_memset(msg.binary, 0, CODE_SIZE + 1);
    msg.bin_len = 0;
    if (msg.buf_len == BUFFER_SIZE)
        flush_buffer();
    if (msg.buf[msg.buf_len - 1] == '\0')
    {
        ft_printf("client: %s\n", msg.buf);
        ft_memset(msg.buf, 0, BUFFER_SIZE);
        msg.buf_len = 0;
        msg.seg_no = 0;
    }
}

void    sigusr_handler(int signo)
{
    char    ch;

    if (signo == SIGUSR1)
        ch = '0';
    else
        ch = '1';
    msg.binary[msg.bin_len++] = ch;
    if (msg.bin_len == CODE_SIZE)
        store_binary();
}
