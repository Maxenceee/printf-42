/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:59:41 by rchallie          #+#    #+#             */
/*   Updated: 2023/12/15 16:50:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_num_ulen(unsigned long num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	if (count == 0)
		count = 1;
	return (count);
}

static char	*ft_gen(char *rtn, unsigned long nbr, int len)
{
	if (nbr == 0)
		return (ft_strdup("0"));
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	rtn[len] = '\0';
	while (--len)
	{
		rtn[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	rtn[0] = (nbr % 10) + '0';
	return (rtn);
}

char	*ft_u_itoa(uint32_t n)
{
	int		len;
	long	nbr;

	nbr = n;
	len = get_num_ulen(nbr);
	return (ft_gen(NULL, nbr, len));
}
