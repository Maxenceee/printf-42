/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:24:34 by mgama             #+#    #+#             */
/*   Updated: 2023/12/15 16:50:57 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(uint32_t nbr, int capitals, int *count)
{
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, capitals, count);
		ft_putnbr_base(nbr % 16, capitals, count);
	}
	else
		ft_putchar(DIGITS[nbr + capitals], count);
}

void	ft_putnbr_base_p(unsigned long int nbr, int capitals, int *count)
{
	if (nbr >= 16)
	{
		ft_putnbr_base_p(nbr / 16, capitals, count);
		ft_putnbr_base_p(nbr % 16, capitals, count);
	}
	else
		ft_putchar(DIGITS[nbr + capitals], count);
}

void	ft_puthex(uint32_t n, int capitals, int *count)
{
	ft_putnbr_base(n, capitals, count);
}

void	ft_puthex_p(unsigned long int n, int *count)
{
	if (!n)
		return ((void)ft_putstr_fd("(nil)", STDOUT_FILENO, count));
	ft_putstr_fd("0x", STDOUT_FILENO, count);
	ft_putnbr_base_p(n, 0, count);
}
