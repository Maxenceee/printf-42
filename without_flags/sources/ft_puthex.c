/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:24:34 by mgama             #+#    #+#             */
/*   Updated: 2022/12/02 18:03:03 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, int capitals, int *count)
{
	static char		digits[] = "0123456789abcdef0123456789ABCDEF";
	
	if (nbr >= 16)
	{
		ft_putnbr_base(nbr / 16, capitals, count);
		ft_putnbr_base(nbr % 16, capitals, count);
	}
	else
		ft_putchar(digits[nbr + capitals], count);
}

void	ft_putnbr_base_p(unsigned long int nbr, int capitals, int *count)
{
	static char		digits[] = "0123456789abcdef0123456789ABCDEF";
	
	if (nbr >= 16)
	{
		ft_putnbr_base_p(nbr / 16, capitals, count);
		ft_putnbr_base_p(nbr % 16, capitals, count);
	}
	else
		ft_putchar(digits[nbr + capitals], count);
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
