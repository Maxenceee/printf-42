/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:24:34 by mgama             #+#    #+#             */
/*   Updated: 2023/12/14 23:34:51 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, int capitals, int *count)
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

void	ft_puthex(unsigned int n, int capitals, int *count)
{
	ft_putnbr_base(n, capitals, count);
}

void	ft_puthex_p(unsigned long int n, int *count)
{
	ft_putstr_fd("0x", 1, count);
	ft_putnbr_base_p(n, 0, count);
}
