/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgama <mgama@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:17:43 by mgama             #+#    #+#             */
/*   Updated: 2022/11/21 14:41:52 by mgama            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_in_int_spaces(char *d_i, int save_i, int *count, t_flags flags)
{
	if (save_i < 0 && flags.plus == 0 && flags.dot >= 0)
		ft_putchar_c('-', count);
	if (flags.dot >= 0)
		ft_print_width(flags.dot - 1, ft_strlen(d_i) - 1, 1, count);
	ft_putstrprec(d_i, ft_strlen(d_i), count);
}

void	ft_print_int_spaces(char *d_i, int save_i, int *count, t_flags flags)
{
	if (flags.minus == 1)
		ft_print_in_int_spaces(d_i, save_i, count, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ft_print_width(flags.width, 0, 0, count);
	}
	else
		ft_print_width(flags.width, ft_strlen(d_i), flags.zero, count);
	if (flags.minus == 0)
		ft_print_in_int_spaces(d_i, save_i, count, flags);
}

void	ft_print_int_flags(t_flags *flags, long int *li, int *count)
{
	if (*li < 0 && (flags->dot >= 0 || flags->zero == 1))
	{
		if (flags->zero == 1 && flags->dot == -1)
			ft_putstrprec("-", 1, count);
		(*li) *= -1;
		flags->zero = 1;
		flags->width--;
	}
	else if (*li >= 0 && flags->plus == 1)
	{
		ft_putstrprec("+", 1, count);
		flags->width--;
	}
	else if (*li >= 0 && flags->blank == 1)
	{
		ft_putstrprec(" ", 1, count);
		flags->width--;
	}
}

void	ft_print_int(int i, int *count, t_flags flags)
{
	char		*d_i;
	long int	li;

	li = i;
	if (flags.dot == 0 && li == 0)
	{
		ft_print_width(flags.width, 0, 0, count);
		return ;
	}
	ft_print_int_flags(&flags, &li, count);
	d_i = ft_itoa(li);
	ft_print_int_spaces(d_i, i, count, flags);
	free(d_i);
}
