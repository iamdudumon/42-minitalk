/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dukim <dukim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:13:00 by dukim             #+#    #+#             */
/*   Updated: 2024/02/29 11:26:51 by dukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atoi(const char *nptr)
{
	unsigned int	sum;

	sum = 0;
	while (ft_isdigit(*nptr))
	{
		sum = sum * 10 + (*nptr - '0');
		nptr++;
	}
	return (sum);
}
