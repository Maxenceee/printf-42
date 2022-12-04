/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:45:47 by mgama             #+#    #+#             */
/*   Updated: 2022/11/29 20:41:27 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_ftoa(double x, int max)
{
	int		n;
	int		i;
	int		k;
	char	*p;
	char	*tmp;

	i = 0;
	k = 0;
	p = ft_calloc(20, sizeof(char));
	if (!p)
		return (0);
	if (x < 0)
	{
		x = -x;
		p[i] = '-';
		i++;
		k++;
	}
	n = (int)x;
	tmp = ft_itoa(n);
	ft_strlcat(p, tmp, 20);
	free(tmp);
	if (n == 0)
	{
		k++;
		i++;
	}
	while (n > 0)
	{
		x /= 10;
		n = (int)x;
		i++;
	}
	*(p + i) = '.';
	x *= 10;
	n = (int)x;
	x = x - n;
	while (((n > 0) || (i > k)) && max + i > 0)
	{
		if (k == i)
			k++;
		*(p + k) = '0' + n;
		x *= 10;
		n = (int)x;
		x = x - n;
		k++;
		max--;
	}
	*(p + k) = '\0';
	return (p);
}
