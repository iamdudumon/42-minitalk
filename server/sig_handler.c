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

void    sigusr1_handler(int signo)
{
    ft_printf("0");
}

void    sigusr2_handler(int signo)
{
    ft_printf("1");
}