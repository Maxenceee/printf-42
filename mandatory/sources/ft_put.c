/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:21:31 by mgama             #+#    #+#             */
/*   Updated: 2023/12/16 01:36:41 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	if (write(1, &c, 1) == -1)
	{
		(*count) = -1;
		return ;
	}
	(*count)++;
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	size_t	c;

	if (!s)
		s = "(null)";
	c = ft_strlen(s);
	if (write(fd, s, c) == -1)
	{
		(*count) = -1;
		return ;
	}
	(*count) += c;
}

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putstr_fd("-2147483648", STDOUT_FILENO, count);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
	else
		ft_putchar(nb + 48, count);
}

void	ft_putnbr_u(uint32_t nb, int *count)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
	else
		ft_putchar(nb + 48, count);
}
