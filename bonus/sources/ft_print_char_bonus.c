/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:55:31 by mgama             #+#    #+#             */
/*   Updated: 2023/12/22 12:12:25 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_flags_bonus.h"

void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putchar_c(char c, int *count)
{
	if (write(STDOUT_FILENO, &c, 1) == -1)
	{
		(*count) = -1;
		return ;
	}
	(*count)++;
}

#ifdef __APPLE__

void	ft_print_char(char c, int *count, t_flags flags, int percent)
{
	(void)percent;
	if (flags.minus == 1)
		ft_putchar_c(c, count);
	ft_print_width(flags.width, 1, 0, count);
	if (flags.minus == 0)
		ft_putchar_c(c, count);
}

#else

void	ft_print_char(char c, int *count, t_flags flags, int percent)
{
	if (percent)
		return ((void)ft_putchar_c(c, count));
	if (flags.minus == 1)
		ft_putchar_c(c, count);
	ft_print_width(flags.width, 1, 0, count);
	if (flags.minus == 0)
		ft_putchar_c(c, count);
}

#endif /* __APPLE__ */
