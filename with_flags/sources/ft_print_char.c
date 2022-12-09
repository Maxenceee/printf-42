/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:55:31 by mgama             #+#    #+#             */
/*   Updated: 2022/12/09 17:25:43 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_flags.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_c(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_print_char(char c, int *count, t_flags flags)
{
	if (flags.minus == 1)
		ft_putchar_c(c, count);
	ft_print_width(flags.width, 1, 0, count);
	if (flags.minus == 0)
		ft_putchar_c(c, count);
}
