/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:23:53 by mgama             #+#    #+#             */
/*   Updated: 2022/12/04 17:07:33 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

size_t	ft_nbrsize_l(long int nb)
{
	size_t	i;
	int		div;

	i = 0;
	div = 1;
	while (nb / div > 9)
	{
		i++;
		div *= 10;
	}
	return (i);
}

size_t	ft_nbrsize_ul(unsigned long int nb)
{
	size_t	i;
	int		div;

	i = 0;
	div = 1;
	while (nb / div > 9)
	{
		i++;
		div *= 10;
	}
	return (i);
}
